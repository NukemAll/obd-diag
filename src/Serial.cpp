/*
 * Serial.cpp
 *
 * 
*/

#include "Serial.h"


Serial::Serial()
{
	hComm = INVALID_HANDLE_VALUE;
	
	
}

Serial::~Serial()
{
    // Close() function already called from destructor main class    
}


BOOL Serial::Open (int nComPortNr)
{
    if (INVALID_HANDLE_VALUE != hComm) {
        ErrorMessage = "Port already open.";
        return (FALSE);
	}

    char szPort[16];

    wsprintfA (szPort,  "\\\\.\\COM%d", nComPortNr);

    hComm = CreateFileA (szPort,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,0,0);
   
    if (hComm == INVALID_HANDLE_VALUE) {
        ErrorMessage = "Invalid handle.";
        return (FALSE);
    }

    if (!GetCommTimeouts(hComm, &timeouts_alt)) {
		ErrorMessage = "GetCommTimeouts - Error";
		Close ();
        return (FALSE);
    }

   COMMTIMEOUTS timeouts;
   timeouts.ReadIntervalTimeout = MAXDWORD  ;  
   timeouts.ReadTotalTimeoutMultiplier = MAXDWORD  ;
   timeouts.ReadTotalTimeoutConstant = 100; // Timeout 
   timeouts.WriteTotalTimeoutMultiplier = 0;
   timeouts.WriteTotalTimeoutConstant = 0;

   if (!SetCommTimeouts(hComm, &timeouts)) {
		ErrorMessage = "SetCommTimeouts - Error";
		Close ();
		return (FALSE);
    }
    
    
    //DCB dcb;
    dcb.DCBlength = sizeof(DCB);

    if (!GetCommState (hComm, &dcb)) {
        ErrorMessage = "GetCommState - Error";
		Close ();
        return (FALSE);
    }

    dcb.BaudRate = 10400;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    
    dcb.fBinary = TRUE;
    dcb.fParity = FALSE;
    dcb.fDsrSensitivity = FALSE;
    dcb.fNull = FALSE;
    dcb.fAbortOnError = FALSE;
    dcb.fOutxCtsFlow = false; // Disable CTS monitoring
    dcb.fOutxDsrFlow = false; // Disable DSR monitoring
    dcb.fDtrControl = DTR_CONTROL_ENABLE; // Enable DTR control (for self-powered interfaces)
    dcb.fOutX = false; // Disable XON/XOFF for transmission
    dcb.fInX = false; // Disable XON/XOFF for receiving
    dcb.fRtsControl = RTS_CONTROL_ENABLE; // Enable RTS to go high
    dcb.fParity = (dcb.Parity != NOPARITY);
    
    
    if (!SetCommState(hComm, &dcb)) {
		ErrorMessage = "SetCommState - Error";
        Close ();
        return (FALSE);
    }
    
    if (!SetCommTimeouts(hComm, &timeouts)) {
        ErrorMessage = "SetCommTimeouts - Error";
		Close ();
        return (FALSE);
    }
    
   
    ErrorMessage = "";
    return(TRUE);
}

BOOL Serial::Close (void)
{
  	if(INVALID_HANDLE_VALUE == hComm) {
	   ErrorMessage = "No Port open.";   
       return (FALSE);
    }
      
    CloseHandle(hComm);
    hComm   = INVALID_HANDLE_VALUE;
	
	return(TRUE);
}


BOOL Serial::SetBaudRate (int nBaud)
{
    if (INVALID_HANDLE_VALUE == hComm) {
        ErrorMessage = "No Port open.";
        return (FALSE);
    }

    if (!GetCommState (hComm, &dcb)) {
        ErrorMessage = "GetCommState - Error";
		Close ();
    }
    dcb.BaudRate = nBaud;
   
    if (!SetCommState(hComm, &dcb)) {
		ErrorMessage = "SetCommState - Error";
        Close ();
        return (FALSE);
    }

	return (TRUE);
}

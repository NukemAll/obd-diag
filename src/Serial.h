/*
 * Serial.h
 *
 * 
*/

#include <windows.h>


class Serial
{
 public:
    Serial();
    ~Serial();

    BOOL Open (int nComPortNr);
	BOOL Close (void);
    BOOL SetBaudRate (int nBaud);
    
	HANDLE hComm;
	COMMTIMEOUTS timeouts_alt;
	
	DCB dcb;
	
	//Error handling stuff
    char* ErrorMessage; 
	
           
};

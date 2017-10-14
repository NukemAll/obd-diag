/*
 * AirbagComStartStop.cpp
 *
 * 
*/

#include "UniECU.h"

//
// KW82XBaudInit()
//
bool UniECU::KW82XBaudInit()
{
   	// Read stuff
    unsigned long BytesRead = 0;
	
	int InterBitTime = 200; // 5 Baud = 200ms, 200 Baud = 5ms

	// communication baudrate
	iSerial.SetBaudRate(9600);
    
    // clear buffers 
    PurgeComm(iSerial.hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);
    
    // idle-line >= 2000ms at logical 1
    EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(2000);
    
    // Start Bit 0
    EscapeCommFunction(iSerial.hComm, SETBREAK);
    Wait(InterBitTime); 
    // 0x62
    // low-byte 
    // 0  
    EscapeCommFunction(iSerial.hComm, SETBREAK);
    Wait(InterBitTime);
    // 1  
    EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);    
    // 0
    EscapeCommFunction(iSerial.hComm, SETBREAK);
    Wait(InterBitTime);
    // 0
    EscapeCommFunction(iSerial.hComm, SETBREAK);
    Wait(InterBitTime);   
    // h-byte
    // 0 
    EscapeCommFunction(iSerial.hComm, SETBREAK);
    Wait(InterBitTime);    
    // 1
    EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);
    // 1
    EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);
    // 0
    EscapeCommFunction(iSerial.hComm, SETBREAK);
    Wait(InterBitTime);    
    // Stop Bit = 1
    EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);
    
    
    // look for sync byte from ECU
    BytesToRead = 12;
    int i = -1;
    do {
        i++;
        if (i == BytesToRead) {
            FunctionReturnInfo = "No sync byte 0x55 found!.";
            return (false);    
        }       
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
    } while (BufferBytesRead[i] != 0x55);
    // following bytes 
    i++;    
    ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);        
    i++;
    ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
    // no
    if ( (BufferBytesRead[i-1] != 0x52) && (BufferBytesRead[i] != 0x80) ) {
        FunctionReturnInfo = "KW82 protocol not supported!";
        return (false);
    }
    // yes - transmit 7F to establish communication
    unsigned char Compl = 0x7F;
    TransmitCommChar(iSerial.hComm, Compl);
    // read echo, block length, block title
    for (int i=0; i < 3; i++) {
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
    }
    // is block title correct ?
    if (BufferBytesRead[2] != 0xA0) {
        FunctionReturnInfo = "Block title incorrect!.";
        return (false);
    }
    // yes, set block length        
    BytesToRead = (unsigned int) BufferBytesRead[1];
    // read ECU ID
    for (int i=0; i < BytesToRead; i++) {
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
    }
    // store checksum bytes for request intervention
    S1[0] = BufferBytesRead[BytesToRead-2];
    S1[1] = BufferBytesRead[BytesToRead-1];
    //StatusWidget->addItem(QString::number(S1[0]) + " " + QString::number(S1[1]));

    // Display ECU ID in GUI
    QString ECUID = "";
    for (int i=0; i < (BytesToRead-2); i++) {
        ECUID = ECUID + BufferBytesRead[i]; 
    }
    ECUIDlineEdit->setText(ECUID);

    return (true);
}

bool UniECU::AirbagDisconnect()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0xB2; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0xB4;
    BytesToWrite = 4;
    
    SendReceiveAirbag();
    
    if (BufferBytesRead[BytesToWrite+1] == 0xF0) {
        switch (BufferBytesRead[BytesToWrite+2]) {
        case 0xAA:
            StatusWidget->addItem("ECU disconnected.");
            return (true);
            break;
        case 0x55:
            StatusWidget->addItem("ECU can't execute command.");
            return (false);
            break;
        default:
            StatusWidget->addItem("Unknown error.");
            return (false);
        }
    } else {
        StatusWidget->addItem("Not disconnected due to time critical action. Try again.");
        return (false);
    } 
      
}





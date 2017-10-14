/*
 * KW2000DataTransfer.cpp
 *
 * 
*/

#include "UniECU.h"

//
// KW2000DataTransfer() 
//
void UniECU::KW2000DataTransfer()
{
    // Read stuff
    DWORD BytesRead = 0;

    // clear buffers
    PurgeComm(iSerial.hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);

    

    // send command sequence    
    for (int i=0; i < BytesToWrite; i++) {
        TransmitCommChar(iSerial.hComm, ECUCommand[i]);
        Wait(5);
    }
    Wait(25);

    // read ECU answer
    for (int i=0; i < BytesToWrite+1; i++) {
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
        BufferBytesReadTemp[i] = BufferBytesRead[i];
    }
    
    ECUBlockLength = ((int)BufferBytesRead[BytesToWrite]) - 128 + 4;
    
    for (int i=BytesToWrite+1; i < (BytesToWrite+ECUBlockLength); i++) {
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
        BufferBytesReadTemp[i] = BufferBytesRead[i];
    }
}

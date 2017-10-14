/*
 * KW82DataTransfer.cpp
 *
 * 
*/

#include "UniECU.h"

//
// KW82DataTransfer()
//
void UniECU::KW82DataTransfer()
{
    unsigned long BytesRead = 0;
     
    PurgeComm(iSerial.hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);

    // find end of response block for command intervention
    int itemp = 0;
    ReadFile(iSerial.hComm, &BufferBytesRead[itemp], 1, &BytesRead, NULL);
    do {
        itemp++;
        if (itemp > 200)
            break;
        ReadFile(iSerial.hComm, &BufferBytesRead[itemp], 1, &BytesRead, NULL);    
    } while ( ((BufferBytesRead[itemp] != S1[1]) && (BufferBytesRead[itemp-1] != S1[0])) );
 
    // time windows >= 1 ms 
    //Wait(1);
    // clear buffers
    PurgeComm(iSerial.hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);
    // time Windows <= 8 mss   
 
     // send command sequence    
    for (int i=0; i < BytesToWrite; i++) 
        TransmitCommChar(iSerial.hComm, ECUCommand[i]);
 
    // read answer from ECU
    for (int i=0; i < BytesToWrite+1; i++) 
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
    
    AirbagBlockLength = ((int)BufferBytesRead[BytesToWrite]);
    
    for (int i=BytesToWrite+1; i < (BytesToWrite+AirbagBlockLength); i++) 
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
        
    AirbagBlockTitle = ((int)BufferBytesRead[BytesToWrite+1]);  
}

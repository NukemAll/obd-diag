/*
 * KW82ConnectDisconnect.cpp
 *
 * 
*/

#include "UniECU.h"

//
// KW82Connect()
//
bool UniECU::KW82Connect()
{
    // get Gui parameters    
    ECUaddress = ECUaddressGui->text().toInt( 0, 16 );
    Baudrate = BaudrateGui->text().toInt();

    // convert ECU address in GUI to binary 
    // (low byte first in array BinByte[])
    QString StringToBin =  QString::number(ECUaddress, 2);
    int size = StringToBin.size();
    
    int BinByte[8];
    for (int i=0; i<size; i++) {
        BinByte[i] = StringToBin.mid(size-1-i, 1).toInt();    
    }
    for (int i=size; i<8; i++)
        BinByte[i] = 0;
    
    // 5 Baud init
    // Read stuff
    unsigned long BytesRead = 0;
	
	int InterBitTime = 200; // 5 Baud = 200ms, 200 Baud = 5ms
	
    if (KW82InitMethod->currentText() == "200 Baud") 
        InterBitTime = 5;        

	// communication baudrate
	iSerial.SetBaudRate(Baudrate);
    
    // clear buffers 
    PurgeComm(iSerial.hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);
    
    // idle-line >= 2000ms at logical 1
    EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(2000);
    
    // Start Bit 0
    EscapeCommFunction(iSerial.hComm, SETBREAK);
    Wait(InterBitTime); 
    // ECU address
    // low-byte 
    // Bit 1  
    if (BinByte[0] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);
    // Bit 2
    if (BinByte[1] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);    
    // Bit 3
    if (BinByte[2] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else 
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);
    // Bit 4
    if (BinByte[3] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else 
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);   
    // h-byte
    // Bit 5 
    if (BinByte[4] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else 
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);    
    // Bit 6
    if (BinByte[5] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else 
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);
    // Bit 7
    if (BinByte[6] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else 
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
    Wait(InterBitTime);
    // Bit 8
    if (BinByte[7] == 0)
        EscapeCommFunction(iSerial.hComm, SETBREAK);
    else 
        EscapeCommFunction(iSerial.hComm, CLRBREAK);
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
            InfoWindow->addItem("No sync byte 0x55 found!.");
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
        InfoWindow->addItem("Not a KW82 protocol!");
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
        InfoWindow->addItem("Block title incorrect!.");
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
    InfoWindow->addItem("ECU ID found:");
    //InfoWindow->addItem((const char*)BufferBytesRead);
    
    // Display ECU ID in GUI
    QString ECUID = "";
    for (int i=0; i < (BytesToRead-2); i++) {
        ECUID = ECUID + BufferBytesRead[i]; 
    }
    InfoWindow->addItem(ECUID);
    
    return (true);
        
}


//
// KW82Disconnect()
//
bool UniECU::KW82Disconnect()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0xB2; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0xB4;
    BytesToWrite = 4;
    
    KW82DataTransfer();
    
    if (BufferBytesRead[BytesToWrite+1] == 0xF0) {
        switch (BufferBytesRead[BytesToWrite+2]) {
        case 0xAA:
            InfoWindow->addItem("ECU disconnected.");
            return (true);
            break;
        case 0x55:
            InfoWindow->addItem("ECU can't execute command.");
            return (false);
            break;
        default:
            InfoWindow->addItem("Unknown error.");
            return (false);
        }
    } else {
        InfoWindow->addItem("Not disconnected due to time critical action. Try again.");
        return (false);
    } 
      
}


//
// GetInterventionBytes
//
void UniECU::GetInterventionBytes()
{
    unsigned long BytesRead = 0;
    int itemp = 0;
     
    ReadFile(iSerial.hComm, &BufferBytesRead[itemp], 1, &BytesRead, NULL);
    do {
        itemp++;
        ReadFile(iSerial.hComm, &BufferBytesRead[itemp], 1, &BytesRead, NULL);    
    } while ( ((BufferBytesRead[itemp] != AirbagBlockTitle) && (BufferBytesRead[itemp-1] != AirbagBlockLength)) );
    S1[0] = BufferBytesRead[itemp-3];
    S1[1] = BufferBytesRead[itemp-2];
        
}

/*
 * 
 * SearchECU.cpp
 * 
*/
 
#include "UniECU.h"


//
// SearchECU()
//
void UniECU::SearchECUStart()
{
    SearchECUStartAddress = SearchECUStartAddressGui->text().toInt( 0, 16 );
    SearchECUStopAddress = SearchECUStopAddressGui->text().toInt( 0, 16 );
    SearchECUTesterAddress = SearchECUTesterAddressGui->text().toInt( 0, 16 );
    SearchECUTime = SearchECUTimeGui->text().toInt();
    SearchECUBaudrate = SearchECUBaudrateGui->text().toInt();
    
    SearchECUStartButton->setDisabled(true);
    ConnectButton->setDisabled(true);
    ClosePortButton->setDisabled(true);
    SearchECUCancelButton->setDisabled(false);
    InfoWindow->addItem("ECU search started!");
    SearchECUTimer->start(SearchECUTime);
}


//
// SearchECUCancel()
//
void UniECU::SearchECUCancel()
{
    SearchECUTimer->stop();
    InfoWindow->addItem("ECU search stopped!"); 
    SearchECUStartButton->setDisabled(false);
    ConnectButton->setDisabled(false);
    ClosePortButton->setDisabled(false);
    SearchECUCancelButton->setDisabled(true);   
}


//
// SetSearchECUTesterAddress()
//
void UniECU::SetSearchECUTesterAddress()
{
    switch (SearchECUProtocolGui->currentIndex()) {
    case 0: // KW2000
        SearchECUTesterAddressGui->setDisabled(false);
        SearchECUBaudrateGui->setText("10400");
        break;
    case 1: // KW82
        SearchECUTesterAddressGui->setDisabled(true);
        SearchECUBaudrateGui->setText("9600");
        break;
    }
}


//
// SearchECUTimerFunction()
//
void UniECU::SearchECUTimerFunction()
{
    switch (SearchECUProtocolGui->currentIndex()) {
    case 0: // KW2000
        // fast initialisation
        int cs;

        // prepare request command 
        ECUCommand[0] = 0x81; 
        ECUCommand[1] = (unsigned char) SearchECUStartAddress; 
        ECUCommand[2] = (unsigned char) SearchECUTesterAddress;
        ECUCommand[3] = 0x81;
        BytesToWrite = 5;
        cs = 0; // checksum
        for (int i=0; i < BytesToWrite-1; i++) {
            cs += (int) ECUCommand[i];
        }
        cs = cs%256;
        ECUCommand[BytesToWrite-1] = (unsigned long) cs;
     
        // set communication baudrate
    	iSerial.SetBaudRate(SearchECUBaudrate);
    
        // clear buffers 
        PurgeComm(iSerial.hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);
    
        // Wake-up pattern
        // k-line for 25 ms on low
        EscapeCommFunction(iSerial.hComm, SETBREAK); 
        Wait(23);    
        // k-line for 25 ms on high    
        EscapeCommFunction(iSerial.hComm, CLRBREAK); 
        Wait(23);    
    
        KW2000DataTransfer();

        switch ( BufferBytesRead[BytesToWrite+3] ) {
        case 0x7F:
            InfoWindow->addItem("Connection failed !");
            break;
        case 0xC1:
            InfoWindow->addItem("ECU found at address: " + QString::number(SearchECUStartAddress, 16));
            InfoWindow->addItem("KB1: "+ QString::number(BufferBytesRead[BytesToWrite+4], 16));
            InfoWindow->addItem("KB2: "+ QString::number(BufferBytesRead[BytesToWrite+5], 16));
            SearchECUCancel();
            break;
        default:
            InfoWindow->addItem("At address  " + QString::number(SearchECUStartAddress, 16) + "  nothing found.");
        }    
        
        SearchECUStartAddress = SearchECUStartAddress + 1;
        if (SearchECUStartAddress > SearchECUStopAddress)
            SearchECUCancel();
            
        break;
    case 1: // KW82
        // convert ECU address in GUI to binary 
        // (low byte first in array BinByte[])
        QString StringToBin =  QString::number(SearchECUStartAddress, 2);
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
    	
//        if (KW82InitMethod->currentText() == "200 Baud") 
//            InterBitTime = 5;        
    
    	// communication baudrate
    	iSerial.SetBaudRate(SearchECUBaudrate);
        
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
        int ii = 0;
        int i = -1;
        do {
            i++;
            if (i == BytesToRead) {
                InfoWindow->addItem("At address  " + QString::number(SearchECUStartAddress, 16) + "  nothing found.");
                //InfoWindow->addItem("No sync byte 0x55 found!.");
                
                SearchECUStartAddress = SearchECUStartAddress + 1;
                if (SearchECUStartAddress > SearchECUStopAddress)
                    SearchECUCancel();
                
                ii = 1;                
                break;    
            }       
            ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
        } while (BufferBytesRead[i] != 0x55);
        if (ii == 1)
            break;
        // following bytes 
        i++;    
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);        
        i++;
        ReadFile(iSerial.hComm, &BufferBytesRead[i], 1, &BytesRead, NULL);
        // no
        if ( (BufferBytesRead[i-1] != 0x52) && (BufferBytesRead[i] != 0x80) ) {
            InfoWindow->addItem("Not a KW82 protocol at address: " + QString::number(SearchECUStartAddress, 16));
            break;
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
            break;
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
        InfoWindow->addItem("ECU found at address: " + QString::number(SearchECUStartAddress, 16));
        //InfoWindow->addItem("ECU ID:");
        
        // Display ECU ID in GUI
        QString ECUID = "ECU ID:  ";
        for (int i=0; i < (BytesToRead-2); i++) {
            ECUID = ECUID + BufferBytesRead[i]; 
        }
        InfoWindow->addItem(ECUID);
        
        SearchECUCancel();
        break;
    }
    
}

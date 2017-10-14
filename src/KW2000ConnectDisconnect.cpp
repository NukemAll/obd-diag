/*
 * KW2000ConnectDisconnect.cpp
 *
 * 
*/

#include "UniECU.h"

//
//  KW2000Connect()
//
bool UniECU::KW2000FastConnect()
{
    // get Gui parameters
    ECUaddress = ECUaddressGui->text().toInt( 0, 16 );
    Testeraddress = TesteraddressGui->text().toInt( 0, 16 );
    TesterPresentTime = TesterPresentTimeGui->text().toInt();
    Baudrate = BaudrateGui->text().toInt();
    
    // fast initialisation
    int cs;

    // prepare request command 
    ECUCommand[0] = 0x81; 
    ECUCommand[1] = (unsigned char) ECUaddress; 
    ECUCommand[2] = (unsigned char) Testeraddress;
    ECUCommand[3] = 0x81;
    BytesToWrite = 5;
    cs = 0; // checksum
    for (int i=0; i < BytesToWrite-1; i++) {
        cs += (int) ECUCommand[i];
    }
    cs = cs%256;
    ECUCommand[BytesToWrite-1] = (unsigned long) cs;
 
    // set communication baudrate
	iSerial.SetBaudRate(Baudrate);
    
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
        return (false);
        break;
    case 0xC1:
        InfoWindow->addItem("KB1: "+ QString::number(BufferBytesRead[BytesToWrite+4], 16));
        InfoWindow->addItem("KB2: "+ QString::number(BufferBytesRead[BytesToWrite+5], 16));
        TimerTesterPresent->start(TesterPresentTime);
        return (true);
        break;
    default:
        InfoWindow->addItem("Unknown response Byte: " + QString::number(BufferBytesRead[BytesToWrite+3], 16));
        return (false);
    }    
}


//
//  KW2000Disconnect()
//
bool UniECU::KW2000Disconnect()
{
    TimerTesterPresent->stop();
    
    int cs;
    //   
    ECUCommand[0] = 0x81; 
    ECUCommand[1] = (unsigned char) ECUaddress; 
    ECUCommand[2] = (unsigned char) Testeraddress;
    ECUCommand[3] = 0x82;
    BytesToWrite = 5;
    cs = 0; // checksum
    for (int i=0; i < BytesToWrite-1; i++) {
        cs += (int) ECUCommand[i];
    }
    cs = cs%256;
    ECUCommand[BytesToWrite-1] = (unsigned long) cs;  

    KW2000DataTransfer();
    
    switch ( BufferBytesRead[BytesToWrite+ECUBlockLength-2] ) {
    case 0x7F:
        InfoWindow->addItem("Can't execute command !");
        return (false);
        break;
    case 0xC2:
        InfoWindow->addItem("ECU disconnected.");
        return (true);
        break;
    default:
        InfoWindow->addItem("Unknown error !");
        return (false);
    }
}


//
// TesterPresent()
//
void UniECU::TesterPresent()
{
    ECUCommand[0] = 0x01;
    ECUCommand[1] = 0x3E;
    ECUCommand[2] = 0x3F;
    BytesToWrite = 3;
    // clear buffers
    PurgeComm(iSerial.hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);
    
    // send command sequence    
    for (int i=0; i < BytesToWrite; i++) {
        TransmitCommChar(iSerial.hComm, ECUCommand[i]);
        Wait(5);
    } 
    
}

/*
 * KW82Communication.cpp
 *
 * 
*/

#include "UniECU.h"


//
// KW82ReadDTC()
//
void UniECU::KW82ReadDTC()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0x12; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0x14;
    BytesToWrite = 4;
    
    KW82DataTransfer();
    
    QString Show = "DTC: ";
      
    switch (BufferBytesRead[BytesToWrite+1]) {
    case 0xA2:
        for (int i=BytesToWrite+2; i < (BytesToWrite+2+AirbagBlockLength); i++) {
            Show = Show + " " + QString::number(BufferBytesRead[i], 10);
        }
        InfoWindow->addItem(Show);
        
        GetInterventionBytes();
        //InfoWindow->addItem(QString::number(S1[0], 16) + " " + QString::number(S1[1], 16));
        break;
    case 0x55:
            InfoWindow->addItem("ECU can't execute command!");
            break;
    default:
        InfoWindow->addItem("Error due to time critical action. Try again.");
    } 

}


//
// KW82ClearDTC()
//
void UniECU::KW82ClearDTC()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0xB1; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0xB3;
    BytesToWrite = 4;
    
    KW82DataTransfer();
    
    //QString Show = "Read: ";
        
    if (BufferBytesRead[BytesToWrite+1] == 0xF0) {   
        switch (BufferBytesRead[BytesToWrite+2]) {
        case 0xF0:
            InfoWindow->addItem("DTC cleared.");
            //for (int i=BytesToWrite+2; i < (BytesToWrite+2+AirbagBlockLength); i++) {
            //    Show = Show + " " + QString::number(BufferBytesRead[i], 16);
            //}
            //InfoWindow->addItem(Show);
        
            GetInterventionBytes();
            //InfoWindow->addItem(QString::number(S1[0], 16) + " " + QString::number(S1[1], 16));
            break;
        case 0x55:
            InfoWindow->addItem("ECU can't execute command!");
            break;
        } 
    } else {
        InfoWindow->addItem("Error due to time critical action. Try again.");
    } 
}


//
// KW82Snapshot
//
void UniECU::KW82Snapshot()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0x11; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0x13;
    BytesToWrite = 4;
    
    KW82DataTransfer();
    
    QString Show = "Snapshot: ";
        
    switch (BufferBytesRead[BytesToWrite+1]) {
    case 0xA1:
        for (int i=BytesToWrite+3; i < (BytesToWrite+AirbagBlockLength-2); i++) {
            Show = Show + " " + QString::number(BufferBytesRead[i], 16);
        }
        InfoWindow->addItem(Show);
        //StatusWidget->addItem(QString::number(0x1e, 10));
        
        GetInterventionBytes();
        //InfoWindow->addItem(QString::number(S1[0], 16) + " " + QString::number(S1[1], 16));
        break;
    default:
        InfoWindow->addItem("Error due to time critical action. Try again.");
    } 
}

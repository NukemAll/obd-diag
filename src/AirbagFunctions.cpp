/*
 * AirbagFunctions.cpp
 *
 * 
*/

#include "UniECU.h"

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


//
// Read DTC
//
bool UniECU::ReadDTCAirbag()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0x12; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0x14;
    BytesToWrite = 4;
    
    SendReceiveAirbag();
        
    
    QString Show = "DTC: ";
   
    switch (BufferBytesRead[BytesToWrite+1]) {
    case 0xA2:
        for (int i=BytesToWrite+2; i < (BytesToWrite+2+AirbagBlockLength); i++) {
            Show = Show + " " + QString::number(BufferBytesRead[i], 10);
        }
        StatusWidget->addItem(Show);
        
        GetInterventionBytes();
        //StatusWidget->addItem(QString::number(S1[0], 16) + " " + QString::number(S1[1], 16));
        return (true);
        break;
    default:
        StatusWidget->addItem("Error due to time critical action. Try again.");
        return (false);
    } 

}


//
// Clear DTC
//
bool UniECU::ClearDTCAirbag()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0xB1; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0xB3;
    BytesToWrite = 4;
    
    SendReceiveAirbag();
    
    QString Show = "Read: ";
        
    if (BufferBytesRead[BytesToWrite+1] == 0xF0) {   
        switch (BufferBytesRead[BytesToWrite+2]) {
        case 0xF0:
            StatusWidget->addItem("DTC cleared.");
            for (int i=BytesToWrite+2; i < (BytesToWrite+2+AirbagBlockLength); i++) {
                Show = Show + " " + QString::number(BufferBytesRead[i], 16);
            }
            StatusWidget->addItem(Show);
        
            GetInterventionBytes();
            //StatusWidget->addItem(QString::number(S1[0], 16) + " " + QString::number(S1[1], 16));
            return (true);
            break;
        case 0x55:
            StatusWidget->addItem("ECU can't execute command!");
            break;
        } 
    } else {
        StatusWidget->addItem("Error due to time critical action. Try again.");
        return (false);
    } 
      
}


//
// Read Snapshot
//
bool UniECU::ReadSnapshotAirbag()
{
    
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0x11; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0x13;
    BytesToWrite = 4;
    
    SendReceiveAirbag();
    
    QString Show = "Snapshot: ";
        
    switch (BufferBytesRead[BytesToWrite+1]) {
    case 0xA1:
        for (int i=BytesToWrite+3; i < (BytesToWrite+AirbagBlockLength-2); i++) {
            Show = Show + " " + QString::number(BufferBytesRead[i], 16);
        }
        StatusWidget->addItem(Show);
        //StatusWidget->addItem(QString::number(0x1e, 10));
        
        FAD = BufferBytesRead[BytesToWrite+3+20+1]/38.5;
        lineEditFAD->setText(QString::number(FAD, 'g'));
        FAP = BufferBytesRead[BytesToWrite+3+20+2]/38.5;
        lineEditFAP->setText(QString::number(FAP, 'g'));
        BPD = BufferBytesRead[BytesToWrite+3+20+3]/38.5;
        lineEditBPD->setText(QString::number(BPD, 'g'));
        BPP = BufferBytesRead[BytesToWrite+3+20+4]/38.5;
        lineEditBPP->setText(QString::number(BPP, 'g'));
        SAD = BufferBytesRead[BytesToWrite+3+20+5]/38.5;
        lineEditSAD->setText(QString::number(SAD, 'g'));
        SAP = BufferBytesRead[BytesToWrite+3+20+6]/38.5;
        lineEditSAP->setText(QString::number(SAP, 'g'));
        
        GetInterventionBytes();
        //StatusWidget->addItem(QString::number(S1[0], 16) + " " + QString::number(S1[1], 16));
        return (true);
        break;
    default:
        StatusWidget->addItem("Error due to time critical action. Try again.");
        lineEditFAD->setText("NA");
        lineEditFAP->setText("NA");
        lineEditBPD->setText("NA");
        lineEditBPP->setText("NA");
        lineEditSAD->setText("NA");
        lineEditSAP->setText("NA");
        return (false);
    } 
}

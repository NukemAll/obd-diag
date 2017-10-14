/*
 * Communication.cpp
 *
 * 
*/
 
#include "UniECU.h"


//
// 
//
void UniECU::ReadDTC()
{
    // set ComBaudrate
    ComBaudrate = ComBaudrateGui->text().toInt();
    iSerial.SetBaudRate(ComBaudrate);

    switch (ChooseSystemGui->currentIndex()) {
    case 0: // Bosch Motronic 1.5.5
        KW2000ReadDTC();
        break;
    case 1: // Airbag-System SAB6
        KW82ReadDTC();
        break;
    case 2: // Custom (KW2000)
        KW2000ReadDTC();
        break;
    case 3: // Custom (KW82)
        KW82ReadDTC();
        break;
    }        

}


//
//
//
void UniECU::ClearDTC()
{
    // set ComBaudrate
    ComBaudrate = ComBaudrateGui->text().toInt();
    iSerial.SetBaudRate(ComBaudrate);
    
    switch (ChooseSystemGui->currentIndex()) {
    case 0: // Bosch Motronic 1.5.5
        KW2000ClearDTC();
        break;
    case 1: // Airbag-System SAB6
        KW82ClearDTC();
        break;
    case 2: // Custom (KW2000)
        KW2000ClearDTC();
        break;
    case 3: // Custom (KW82)
        KW82ClearDTC();
        break;
    case 4: // ABS
        KW82ClearDTC();
        break;
    }            

}


//
//
//
void UniECU::ReadResistanceAirbag()
{
    ECUCommand[0] = 0x02; 
    ECUCommand[1] = 0x11; 
    ECUCommand[2] = 0x00;
    ECUCommand[3] = 0x13;
    BytesToWrite = 4;
    
    KW82DataTransfer();
    
    //QString Show = "Snapshot: ";
        
    switch (BufferBytesRead[BytesToWrite+1]) {
    case 0xA1:
        //for (int i=BytesToWrite+3; i < (BytesToWrite+AirbagBlockLength-2); i++) {
        //    Show = Show + " " + QString::number(BufferBytesRead[i], 16);
        //}
        //InfoWindow->addItem(Show);
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
        //InfoWindow->addItem(QString::number(S1[0], 16) + " " + QString::number(S1[1], 16));
        break;
    default:
        InfoWindow->addItem("Error due to time critical action. Try again.");
        lineEditFAD->setText("NA");
        lineEditFAP->setText("NA");
        lineEditBPD->setText("NA");
        lineEditBPP->setText("NA");
        lineEditSAD->setText("NA");
        lineEditSAP->setText("NA");
    }               

}


//
//
//
void UniECU::Snapshot()
{
    // set ComBaudrate
    ComBaudrate = ComBaudrateGui->text().toInt();
    iSerial.SetBaudRate(ComBaudrate);

    switch (ChooseSystemGui->currentIndex()) {
    case 0: // Bosch Motronic 1.5.5
        
        break;
    case 1: // Airbag-System SAB6
        KW82Snapshot();
        break;
    case 3: // Custom (KW82)
        KW82Snapshot();
        break;
    case 4: // ABS
        KW82Snapshot();
        break;
    }                  

}


//
//
//
void UniECU::ECUInfo()
{
    // set ComBaudrate
    ComBaudrate = ComBaudrateGui->text().toInt();
    iSerial.SetBaudRate(ComBaudrate);

    switch (ChooseSystemGui->currentIndex()) {
    case 0: // Bosch Motronic 1.5.5
        KW2000Info();
        break;
    case 1: // Airbag-System SAB6
        
        break;
    case 2: // Custom (KW2000)
        KW2000Info();
        break;

    }              
}

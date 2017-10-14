/*
 * KW2000Communication.cpp
 *
 * 
*/

#include "UniECU.h"

//
//  KW2000Info()
//
void UniECU::KW2000Info()
{
    TimerTesterPresent->stop();
    
    int cs;
    //   
    ECUCommand[0] = 0x82; 
    ECUCommand[1] = (unsigned char) ECUaddress; 
    ECUCommand[2] = (unsigned char) Testeraddress;
    ECUCommand[3] = 0x1A;
    ECUCommand[4] = 0x00; // place holder   
    BytesToWrite = 6;
    
    for (int Mi=0; Mi<5; Mi++) {
        switch ( Mi ) {
            case 0:
                ECUCommand[4] = 0x90;
                InfoWindow->addItem("VIN:");
                break; 
            case 1:
                ECUCommand[4] = 0x97;
                InfoWindow->addItem("Engine:");
                break;  
            case 2:
                ECUCommand[4] = 0x94;
                InfoWindow->addItem("Software Number:");
                break;
            case 3:
                ECUCommand[4] = 0x95;
                InfoWindow->addItem("Software Version Number:");
                break;
            case 4:
                ECUCommand[4] = 0x99;
                InfoWindow->addItem("Programming Date (YYYYMMDD):");
                break;
            default:
                break;
        }
    
        cs = 0; // checksum
        for (int i=0; i < BytesToWrite-1; i++) {
            cs += (int) ECUCommand[i];
        }
        cs = cs%256;
        ECUCommand[BytesToWrite-1] = (unsigned long) cs;  

        KW2000DataTransfer();
    
        switch ( BufferBytesRead[BytesToWrite+3] ) {
        case 0x7F:
            InfoWindow->addItem("No Data.");
            break;
        case 0x5A:
            for (int i=0; i < ECUBlockLength-4-1; i++)
                BufferBytesRead[i] = BufferBytesReadTemp[BytesToWrite+4+1+i];
            BytesToRead = ECUBlockLength-4-1-1; 
            switch ( ECUCommand[4] ) {
                case 0x95:
                    DisplayReadBytesDez();
                    break;
                case 0x99:
                    DisplayReadBytesHex();
                    break;
                default:
                    DisplayReadBytesRaw();
                    break;
            }
            break;
        default:
            InfoWindow->addItem("Unknown error, process canceled !");
        }
    }
    
    TimerTesterPresent->start(TesterPresentTime);    
}


//
//  KW2000ReadDTC()
//
void UniECU::KW2000ReadDTC()
{
    TimerTesterPresent->stop();
    
    int cs;
    //   
    ECUCommand[0] = 0x84; 
    ECUCommand[1] = (unsigned char) ECUaddress; 
    ECUCommand[2] = (unsigned char) Testeraddress;
    ECUCommand[3] = 0x18;
    ECUCommand[4] = 0x00;
    ECUCommand[5] = 0xFF;
    ECUCommand[6] = 0x00;            
    BytesToWrite = 8;
    cs = 0; // checksum
    for (int i=0; i < BytesToWrite-1; i++) {
        cs += (int) ECUCommand[i];
    }
    cs = cs%256;
    ECUCommand[BytesToWrite-1] = (unsigned long) cs;  

    KW2000DataTransfer();
    
    int NumberDTC;
    QString HBDTC, LBDTC;
    switch ( BufferBytesRead[BytesToWrite+3] ) {
    case 0x7F:
        InfoWindow->addItem("Can't execute command !");
        break;
    case 0x58:
        NumberDTC = (int)BufferBytesRead[BytesToWrite+4];
        InfoWindow->addItem("Number of DTC:  " + QString::number(NumberDTC));
        for (int i=0; i < (NumberDTC*3); i=i+3) {
            if ( (int)(BufferBytesRead[BytesToWrite+5+i]) < 16 ) {
                HBDTC = "0" + QString::number(BufferBytesRead[BytesToWrite+5+i]);
            } else {
                HBDTC = QString::number(BufferBytesRead[BytesToWrite+5+i], 16);     
            }
            if ( (int)(BufferBytesRead[BytesToWrite+5+i+1]) < 16 ) {
                LBDTC = "0" + QString::number(BufferBytesRead[BytesToWrite+5+i+1]);
            } else {
                LBDTC = QString::number(BufferBytesRead[BytesToWrite+5+i+1], 16);     
            }
            InfoWindow->addItem("DTC " + QString::number(i/3+1) + ":   " 
                                      +"P" + HBDTC + LBDTC
                                      + "   Status:  " 
                                      + QString::number(BufferBytesRead[BytesToWrite+5+i+2], 16));           
      }       
        break;
    default:
        InfoWindow->addItem("Unknown error !");
    }    
    
    TimerTesterPresent->start(TesterPresentTime);    
}


//
//  KW2000ClearDTC()
//
void UniECU::KW2000ClearDTC()
{
    TimerTesterPresent->stop();
    
    int cs;
    //   
    ECUCommand[0] = 0x83; 
    ECUCommand[1] = (unsigned char) ECUaddress; 
    ECUCommand[2] = (unsigned char) Testeraddress;
    ECUCommand[3] = 0x14;
    ECUCommand[4] = 0xFF;
    ECUCommand[5] = 0x00;
    BytesToWrite = 7;
    cs = 0; // checksum
    for (int i=0; i < BytesToWrite-1; i++) {
        cs += (int) ECUCommand[i];
    }
    cs = cs%256;
    ECUCommand[BytesToWrite-1] = (unsigned long) cs;  

    KW2000DataTransfer();
    
    switch ( BufferBytesRead[BytesToWrite+3] ) {
    case 0x7F:
        InfoWindow->addItem("Can't execute command !");
        break;
    case 0x54:
        InfoWindow->addItem("DTC cleared.");
        break;
    default:
        InfoWindow->addItem("Unknown error !");
    }      
    
    TimerTesterPresent->start(TesterPresentTime);    
      
}

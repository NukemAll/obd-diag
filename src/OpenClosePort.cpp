/*
 * 
 * OpenClosePort.cpp
 * 
*/
 
#include "UniECU.h"


void UniECU::OpenPort()
{
    // Open Port
    int PortNo = ComEdit->text().toInt();

    if (iSerial.Open(PortNo)==TRUE) {
        ComPortStatusLabel->setText("Port open.");
        GuiOpenPortCondition();
    }
    else {
        ComPortStatusLabel->setText(iSerial.ErrorMessage);
        return;  
    }       
}

void UniECU::ClosePort()
{
    // Close Port
    if (iSerial.Close()==TRUE) {
        ComPortStatusLabel->setText("Port close.");
        GuiStartCondition(); 
    }
    else { 
        ComPortStatusLabel->setText("Can't close Port.");       
    }
}

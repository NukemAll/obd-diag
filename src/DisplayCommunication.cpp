/*
 * DisplayCommunication.cpp
 *
 * 
*/

#include "UniECU.h"


//
// Display data
//
void UniECU::DisplayReadBytesHex()
{
    // Display read values on GUI
    QString testbuf = "";
    for (int i=0; i < BytesToRead; i++) {
        testbuf = testbuf + " " + QString::number(BufferBytesRead[i], 16); 
    }
    InfoWindow->addItem(testbuf);
        
}

void UniECU::DisplayReadBytesRaw()
{
    // Display read values on GUI
    QString testbuf = "";
    for (int i=0; i < BytesToRead; i++) {
        testbuf = testbuf + " " + BufferBytesRead[i]; 
    }
    InfoWindow->addItem(testbuf);
        
}

void UniECU::DisplayReadBytesDez()
{
    // Display read values on GUI
    QString testbuf = "";
    for (int i=0; i < BytesToRead; i++) {
        testbuf = testbuf + " " + QString::number(BufferBytesRead[i], 10); 
    }
    InfoWindow->addItem(testbuf);
        
}

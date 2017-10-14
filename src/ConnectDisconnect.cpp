/*
 * 
 * ConnectDisconnect.cpp
 * 
*/
 
#include "UniECU.h"


//
// Connect()
//
void UniECU::Connect()
{
    switch (ChooseSystemGui->currentIndex()) {
    case 0: // Bosch Motronic 1.5.5
        if ( KW2000FastConnect() == true ) {
            // Button settings
            GuiConnectCondition();
            ReadResistanceAirbagButton->setDisabled(true);
            ECUInfoButton->setDisabled(false);
            ReadDTCButton->setDisabled(false);
            ClearDTCButton->setDisabled(false); 
            ComBaudrateGui->setDisabled(true);
            SnapshotButton->setDisabled(true);
        } 
        break;
    case 1: // Airbag-System SAB6
        if ( KW82Connect() == true ) {
            // Button settings
            GuiConnectCondition(); 
            ReadResistanceAirbagButton->setDisabled(false);
            ECUInfoButton->setDisabled(true);
            ReadDTCButton->setDisabled(false);
            ClearDTCButton->setDisabled(false);
            ComBaudrateGui->setDisabled(true);
            SnapshotButton->setDisabled(false);
        } 
        break;
    case 2: // Custom (KW2000)
        if ( KW2000FastConnect() == true ) {
            // Button settings
            GuiConnectCondition(); 
            ReadResistanceAirbagButton->setDisabled(true);
            ECUInfoButton->setDisabled(false);
            ReadDTCButton->setDisabled(false);
            ClearDTCButton->setDisabled(false); 
            ComBaudrateGui->setDisabled(false);
            SnapshotButton->setDisabled(true);
            // Input settings
            ECUaddressGui->setDisabled(true);
            TesteraddressGui->setDisabled(true);
            BaudrateGui->setDisabled(true);
            TesterPresentTimeGui->setDisabled(true);
        } 
        break;
    case 3: // Custom (KW82)
        if ( KW82Connect() == true ) {
            // Button settings
            GuiConnectCondition();
            ReadResistanceAirbagButton->setDisabled(false);
            ECUInfoButton->setDisabled(true);
            ReadDTCButton->setDisabled(false);
            ClearDTCButton->setDisabled(false);
            ComBaudrateGui->setDisabled(false);
            SnapshotButton->setDisabled(false);
            // Input settings
            ECUaddressGui->setDisabled(true);
            BaudrateGui->setDisabled(true);
            KW82InitMethod->setDisabled(true);     
        } 
        break;
    case 4: // ABS
        if ( KW82Connect() == true ) {
            // Button settings
            GuiConnectCondition();
            ReadResistanceAirbagButton->setDisabled(true);
            ECUInfoButton->setDisabled(true);
            ReadDTCButton->setDisabled(true);
            ClearDTCButton->setDisabled(false);
            ComBaudrateGui->setDisabled(true);
            SnapshotButton->setDisabled(false);
        } 
        break;
    }
}


//
// Disconnect()
//
void UniECU::Disconnect()
{
	switch (ChooseSystemGui->currentIndex()) {
    case 0:
        if ( KW2000Disconnect() == true ) {
            // Button settings
            GuiDisconnectCondition(); 
        } 
        break;  
    case 1: // Airbag-System SAB6
        if ( KW82Disconnect() == true ) {
            // Button settings
            GuiDisconnectCondition(); 
         } 
        break;  
    case 2: // Custom (KW2000)
        if ( KW2000Disconnect() == true ) {
            // Button settings
            GuiDisconnectCondition(); 
            // Input settings
            ECUaddressGui->setDisabled(false);
            TesteraddressGui->setDisabled(false);
            BaudrateGui->setDisabled(false);
            TesterPresentTimeGui->setDisabled(false);
        } 
        break;
    case 3: // Custom (KW82)
        if ( KW82Disconnect() == true ) {
            // Button settings
            GuiDisconnectCondition();
            // Input settings
            ECUaddressGui->setDisabled(false);
            BaudrateGui->setDisabled(false);
            KW82InitMethod->setDisabled(false); 
        } 
        break; 
    case 4: // ABS
        if ( KW82Disconnect() == true ) {
            // Button settings
            GuiDisconnectCondition();
         } 
        break;   
    }
}

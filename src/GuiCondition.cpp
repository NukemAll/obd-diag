/*
 * GuiCondition.cpp
 *
 * 
*/
 
#include "UniECU.h"


//
//  GuiStartCondition
//
void UniECU::GuiStartCondition()
{
    // Button settings
	OpenPortButton->setDisabled(false);
	ClosePortButton->setDisabled(true);
    ECUaddressGui->setDisabled(true);
    TesteraddressGui->setDisabled(true);
    BaudrateGui->setDisabled(true);
    ComBaudrateGui->setDisabled(true);
    TesterPresentTimeGui->setDisabled(false);
    KW82InitMethod->setDisabled(true);     
    ConnectButton->setDisabled(true);
    DisconnectButton->setDisabled(true); 
    ReadResistanceAirbagButton->setDisabled(true);
    ECUInfoButton->setDisabled(true);
    ReadDTCButton->setDisabled(true);
    ClearDTCButton->setDisabled(true); 
    SearchECUStartButton->setDisabled(true);  
    SearchECUCancelButton->setDisabled(true);
    SnapshotButton->setDisabled(true);
    
    // input settings
    ChooseSystemGui->setCurrentIndex(0);
}


void UniECU::GuiOpenPortCondition()
{
    // Button settings
    OpenPortButton->setDisabled(true);
    ClosePortButton->setDisabled(false);
    ConnectButton->setDisabled(false);
    SearchECUStartButton->setDisabled(false);   
}


void UniECU::GuiConnectCondition()
{
    // Button settings
    ConnectButton->setDisabled(true);
    DisconnectButton->setDisabled(false); 
    ChooseSystemGui->setDisabled(true);
    SearchECUStartButton->setDisabled(true);
}


void UniECU::GuiDisconnectCondition()
{
    // Button settings
    ConnectButton->setDisabled(false);
    DisconnectButton->setDisabled(true);
    ReadResistanceAirbagButton->setDisabled(true);
    ECUInfoButton->setDisabled(true);
    ReadDTCButton->setDisabled(true);
    ClearDTCButton->setDisabled(true);
    SnapshotButton->setDisabled(true);
    ChooseSystemGui->setDisabled(false);
    SearchECUStartButton->setDisabled(false);
}

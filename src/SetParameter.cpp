/*
 * SetParameter.cpp
 *
 * 
*/

#include "UniECU.h"


void UniECU::SetParameter()
{
    switch (ChooseSystemGui->currentIndex()) {
    case 0: // Bosch Motronic 1.5.5
        ECUaddressGui->setText("11");
        ECUaddressGui->setDisabled(true);
        TesteraddressGui->setText("f1");
        TesteraddressGui->setDisabled(true);
        BaudrateGui->setText("10400");
        BaudrateGui->setDisabled(true);
        ComBaudrateGui->setText("10400");
        ComBaudrateGui->setDisabled(true);        
        TesterPresentTimeGui->setText("2000");
        TesterPresentTimeGui->setDisabled(false);
        KW82InitMethod->setDisabled(true);        
        
        break;
    case 1: // Airbag-System SAB6
        ECUaddressGui->setText("62");
        ECUaddressGui->setDisabled(true);
        TesteraddressGui->setDisabled(true);
        BaudrateGui->setText("9600");
        BaudrateGui->setDisabled(true);
        ComBaudrateGui->setText("9600");
        ComBaudrateGui->setDisabled(true);        
        TesterPresentTimeGui->setDisabled(true);
        KW82InitMethod->setDisabled(true);   
        break;
    case 2: // KW2000
        ECUaddressGui->setDisabled(false);
        TesteraddressGui->setDisabled(false);
        BaudrateGui->setText("10400");
        BaudrateGui->setDisabled(false);
        TesterPresentTimeGui->setDisabled(false);
        KW82InitMethod->setDisabled(true);    
        ComBaudrateGui->setText("10400");
        ComBaudrateGui->setDisabled(false);        
        break;
    case 3: // KW82
        ECUaddressGui->setDisabled(false);
        TesteraddressGui->setDisabled(true);
        BaudrateGui->setText("9600");
        BaudrateGui->setDisabled(false);
        TesterPresentTimeGui->setDisabled(true);
        KW82InitMethod->setDisabled(false);    
        ComBaudrateGui->setText("9600");
        ComBaudrateGui->setDisabled(false);        
        break;
    case 4: // ABS
        ECUaddressGui->setText("21");
        ECUaddressGui->setDisabled(true);
        TesteraddressGui->setDisabled(true);
        BaudrateGui->setText("9600");
        BaudrateGui->setDisabled(true);
        ComBaudrateGui->setText("9600");
        ComBaudrateGui->setDisabled(true);        
        TesterPresentTimeGui->setDisabled(true);
        KW82InitMethod->setDisabled(true);   
        break;
    }
}

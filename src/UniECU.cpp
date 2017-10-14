/*
 * 
 *
 * 
*/
 
#include "UniECU.h"

//
//  Constructor
//
UniECU::UniECU(QWidget *parent) 
: QMainWindow(parent)
, iSerial()
{
	setupUi(this); // this sets up GUI

    // set realtime priority for our process
    HANDLE hop =  OpenProcess(PROCESS_ALL_ACCESS, false, GetCurrentProcessId());
    if (!SetPriorityClass(hop, REALTIME_PRIORITY_CLASS))
        InfoWindow->addItem("SetPriorityClass failed");

    //Get frequency from hardware timer
    if (!QueryPerformanceFrequency((LARGE_INTEGER*)&g_Frequency)) 
        InfoWindow->addItem("Performance Counter nicht vorhanden");
        
    // Serial communication interface
    connect( OpenPortButton, SIGNAL( clicked() ), this, SLOT( OpenPort() ) );
    connect( ClosePortButton, SIGNAL( clicked() ), this, SLOT( ClosePort() ) );
    
    // Chosse system
    connect( ChooseSystemGui, SIGNAL( currentIndexChanged(int) ), this, SLOT( SetParameter() ) );
    
    // Connect/Disconnect Buttons
    connect( ConnectButton, SIGNAL( clicked() ), this, SLOT( Connect() ) );
    connect( DisconnectButton, SIGNAL( clicked() ), this, SLOT( Disconnect() ) );
    
    // KW2000 stuff
    TimerTesterPresent = new QTimer(this);
    connect( TimerTesterPresent, SIGNAL(timeout()), this, SLOT( TesterPresent() ) );
    
    // Communication
    connect( ECUInfoButton, SIGNAL( clicked() ), this, SLOT( ECUInfo() ) );
    connect( ReadResistanceAirbagButton, SIGNAL( clicked() ), this, SLOT( ReadResistanceAirbag() ) );
    connect( ReadDTCButton, SIGNAL( clicked() ), this, SLOT( ReadDTC() ) );    
    connect( ClearDTCButton, SIGNAL( clicked() ), this, SLOT( ClearDTC() ) );    
    connect( SnapshotButton, SIGNAL( clicked() ), this, SLOT( Snapshot() ) );
    
    // Search ECU
    connect( SearchECUStartButton, SIGNAL( clicked() ), this, SLOT( SearchECUStart() ) ); 
    connect( SearchECUCancelButton, SIGNAL( clicked() ), this, SLOT( SearchECUCancel() ) );        
    connect( SearchECUProtocolGui, SIGNAL( currentIndexChanged(int) ), this, SLOT( SetSearchECUTesterAddress() ) );        
    SearchECUTimer = new QTimer(this);        
    connect( SearchECUTimer, SIGNAL(timeout()), this, SLOT( SearchECUTimerFunction() ) );  
    
    GuiStartCondition();       
} 


//
//  Deconstructor
//
UniECU::~UniECU() 
{
    iSerial.Close ();                         
}

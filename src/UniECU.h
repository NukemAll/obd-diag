/*
 * 
 *
 * 
*/

#include <QString>
#include <cstring>
#include <QMessageBox.h>
#include <qtimer.h>
#include <ui_UniECU.h>
#include "Serial.h"

using namespace std;


class UniECU : public QMainWindow, private Ui::MainWindow 
{
    Q_OBJECT
 
public:
    UniECU(QWidget *parent = 0);
	~UniECU();
    
    // Serial communication stuff
	Serial iSerial;

    // Timer stuff
    LONGLONG liFirst, liSecond, liElasped, liTarget;
    LONGLONG g_Frequency, g_CurentCount, g_LastCount; 
    void Wait(unsigned int);
	void Clock(int); // argument: 1 = start, 0=stop
	
	// Display stuff
	void DisplayReadBytesHex();
    void DisplayReadBytesRaw();
    void DisplayReadBytesDez();
 
    // Datatransfer stuff
    unsigned char BufferBytesRead[255];
    unsigned char BufferBytesReadTemp[255];
    unsigned char ECUCommand[255];
    int BytesToRead, BytesToWrite;

    // Gui stuff
    int ECUaddress;
    int Testeraddress;
    int Baudrate;
    int ComBaudrate;
    int TesterPresentTime;
    void GuiStartCondition();
    void GuiOpenPortCondition();
    void GuiConnectCondition();
    void GuiDisconnectCondition();

	// KW2000 stuff
    bool KW2000FastConnect();
    bool KW2000Disconnect();
    void KW2000Info();      
    void KW2000ReadDTC();
    void KW2000ClearDTC();
    void KW2000DataTransfer();
    int ECUBlockLength;
  	QTimer *TimerTesterPresent;
                  
    // KW82 stuff
	bool KW82Connect();	
	bool KW82Disconnect();
	void KW82ReadDTC();
	void KW82ClearDTC();
	void KW82Snapshot();
	void KW82DataTransfer();
	void GetInterventionBytes();
	unsigned char S1[2];
	int AirbagBlockLength;
	int AirbagBlockTitle;
	float FAD, FAP, BPD, BPP, SAD, SAP;
	
	// Search ECU stuff
	int SearchECUStartAddress;
	int SearchECUStopAddress;
	int SearchECUTesterAddress;
	int SearchECUTime;
	int SearchECUBaudrate;
	QTimer *SearchECUTimer;
	
public slots:
    void OpenPort();
    void ClosePort();
    void Connect();
	void Disconnect();
	void SetParameter();
    void TesterPresent();
    void ClearDTC();
	void ReadDTC();
    void ReadResistanceAirbag();	
    void Snapshot();
    void ECUInfo();
    void SearchECUStart();
    void SearchECUCancel();
    void SetSearchECUTesterAddress();
    void SearchECUTimerFunction();
};


  





 
 
 

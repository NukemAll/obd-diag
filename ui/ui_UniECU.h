/********************************************************************************
** Form generated from reading ui file 'UniECU.ui'
**
** Created: Sun 8. Jun 10:24:22 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UNIECU_H
#define UI_UNIECU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout1;
    QHBoxLayout *hboxLayout2;
    QLabel *label;
    QLineEdit *ComEdit;
    QPushButton *OpenPortButton;
    QPushButton *ClosePortButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *hboxLayout3;
    QLabel *ComPortStatusLabel;
    QGroupBox *groupBox_28;
    QHBoxLayout *hboxLayout4;
    QVBoxLayout *vboxLayout1;
    QVBoxLayout *vboxLayout2;
    QVBoxLayout *vboxLayout3;
    QVBoxLayout *vboxLayout4;
    QHBoxLayout *hboxLayout5;
    QLabel *label_8;
    QComboBox *ChooseSystemGui;
    QFrame *line_4;
    QHBoxLayout *hboxLayout6;
    QHBoxLayout *hboxLayout7;
    QVBoxLayout *vboxLayout5;
    QHBoxLayout *hboxLayout8;
    QVBoxLayout *vboxLayout6;
    QLabel *label_19;
    QLabel *label_20;
    QVBoxLayout *vboxLayout7;
    QLineEdit *ECUaddressGui;
    QLineEdit *TesteraddressGui;
    QHBoxLayout *hboxLayout9;
    QLabel *label_9;
    QLineEdit *BaudrateGui;
    QFrame *line_3;
    QVBoxLayout *vboxLayout8;
    QHBoxLayout *hboxLayout10;
    QLabel *label_21;
    QLineEdit *TesterPresentTimeGui;
    QHBoxLayout *hboxLayout11;
    QLabel *label_23;
    QComboBox *KW82InitMethod;
    QFrame *line_5;
    QHBoxLayout *hboxLayout12;
    QPushButton *ConnectButton;
    QSpacerItem *spacerItem;
    QPushButton *DisconnectButton;
    QGroupBox *groupBox_29;
    QPushButton *ECUInfoButton;
    QPushButton *ReadDTCButton;
    QPushButton *ClearDTCButton;
    QListWidget *InfoWindow;
    QFrame *line_7;
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout13;
    QLabel *label_2;
    QLineEdit *ComBaudrateGui;
    QWidget *layoutWidget1;
    QHBoxLayout *hboxLayout14;
    QPushButton *pushButton_4;
    QSpacerItem *spacerItem1;
    QWidget *layoutWidget2;
    QHBoxLayout *hboxLayout15;
    QFrame *line_6;
    QVBoxLayout *vboxLayout9;
    QLabel *label_10;
    QVBoxLayout *vboxLayout10;
    QVBoxLayout *vboxLayout11;
    QHBoxLayout *hboxLayout16;
    QHBoxLayout *hboxLayout17;
    QLabel *label_13;
    QLineEdit *lineEditFAD;
    QHBoxLayout *hboxLayout18;
    QLabel *label_14;
    QLineEdit *lineEditFAP;
    QHBoxLayout *hboxLayout19;
    QHBoxLayout *hboxLayout20;
    QLabel *label_16;
    QLineEdit *lineEditSAD;
    QHBoxLayout *hboxLayout21;
    QLabel *label_15;
    QLineEdit *lineEditSAP;
    QHBoxLayout *hboxLayout22;
    QHBoxLayout *hboxLayout23;
    QLabel *label_18;
    QLineEdit *lineEditBPD;
    QHBoxLayout *hboxLayout24;
    QLabel *label_17;
    QLineEdit *lineEditBPP;
    QPushButton *ReadResistanceAirbagButton;
    QPushButton *SnapshotButton;
    QGroupBox *groupBox;
    QHBoxLayout *hboxLayout25;
    QVBoxLayout *vboxLayout12;
    QHBoxLayout *hboxLayout26;
    QVBoxLayout *vboxLayout13;
    QComboBox *SearchECUProtocolGui;
    QHBoxLayout *hboxLayout27;
    QVBoxLayout *vboxLayout14;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *vboxLayout15;
    QLineEdit *SearchECUStartAddressGui;
    QLineEdit *SearchECUStopAddressGui;
    QFrame *line_2;
    QHBoxLayout *hboxLayout28;
    QVBoxLayout *vboxLayout16;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *vboxLayout17;
    QLineEdit *SearchECUTesterAddressGui;
    QLineEdit *SearchECUBaudrateGui;
    QLineEdit *SearchECUTimeGui;
    QVBoxLayout *vboxLayout18;
    QFrame *line;
    QHBoxLayout *hboxLayout29;
    QPushButton *SearchECUStartButton;
    QSpacerItem *spacerItem2;
    QPushButton *SearchECUCancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->setEnabled(true);
    MainWindow->resize(774, 558);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
    MainWindow->setSizePolicy(sizePolicy);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    groupBox_4 = new QGroupBox(centralwidget);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(10, 10, 269, 120));
    hboxLayout = new QHBoxLayout(groupBox_4);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    label = new QLabel(groupBox_4);
    label->setObjectName(QString::fromUtf8("label"));
    label->setCursor(QCursor(Qt::ArrowCursor));
    label->setFrameShape(QFrame::NoFrame);
    label->setFrameShadow(QFrame::Raised);
    label->setLineWidth(1);

    hboxLayout2->addWidget(label);

    ComEdit = new QLineEdit(groupBox_4);
    ComEdit->setObjectName(QString::fromUtf8("ComEdit"));
    ComEdit->setFocusPolicy(Qt::ClickFocus);
    ComEdit->setLayoutDirection(Qt::RightToLeft);

    hboxLayout2->addWidget(ComEdit);


    hboxLayout1->addLayout(hboxLayout2);

    OpenPortButton = new QPushButton(groupBox_4);
    OpenPortButton->setObjectName(QString::fromUtf8("OpenPortButton"));
    OpenPortButton->setFocusPolicy(Qt::ClickFocus);

    hboxLayout1->addWidget(OpenPortButton);

    ClosePortButton = new QPushButton(groupBox_4);
    ClosePortButton->setObjectName(QString::fromUtf8("ClosePortButton"));
    ClosePortButton->setEnabled(false);
    ClosePortButton->setFocusPolicy(Qt::ClickFocus);

    hboxLayout1->addWidget(ClosePortButton);


    vboxLayout->addLayout(hboxLayout1);

    groupBox_2 = new QGroupBox(groupBox_4);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    hboxLayout3 = new QHBoxLayout(groupBox_2);
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    ComPortStatusLabel = new QLabel(groupBox_2);
    ComPortStatusLabel->setObjectName(QString::fromUtf8("ComPortStatusLabel"));
    ComPortStatusLabel->setFrameShape(QFrame::NoFrame);
    ComPortStatusLabel->setFrameShadow(QFrame::Sunken);

    hboxLayout3->addWidget(ComPortStatusLabel);


    vboxLayout->addWidget(groupBox_2);


    hboxLayout->addLayout(vboxLayout);

    groupBox_28 = new QGroupBox(centralwidget);
    groupBox_28->setObjectName(QString::fromUtf8("groupBox_28"));
    groupBox_28->setGeometry(QRect(10, 140, 302, 206));
    hboxLayout4 = new QHBoxLayout(groupBox_28);
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    vboxLayout3 = new QVBoxLayout();
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    vboxLayout4 = new QVBoxLayout();
    vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
    hboxLayout5 = new QHBoxLayout();
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    label_8 = new QLabel(groupBox_28);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    hboxLayout5->addWidget(label_8);

    ChooseSystemGui = new QComboBox(groupBox_28);
    ChooseSystemGui->setObjectName(QString::fromUtf8("ChooseSystemGui"));

    hboxLayout5->addWidget(ChooseSystemGui);


    vboxLayout4->addLayout(hboxLayout5);

    line_4 = new QFrame(groupBox_28);
    line_4->setObjectName(QString::fromUtf8("line_4"));
    line_4->setFrameShape(QFrame::HLine);
    line_4->setFrameShadow(QFrame::Sunken);

    vboxLayout4->addWidget(line_4);


    vboxLayout3->addLayout(vboxLayout4);

    hboxLayout6 = new QHBoxLayout();
    hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
    hboxLayout7 = new QHBoxLayout();
    hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
    vboxLayout5 = new QVBoxLayout();
    vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
    hboxLayout8 = new QHBoxLayout();
    hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
    vboxLayout6 = new QVBoxLayout();
    vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
    label_19 = new QLabel(groupBox_28);
    label_19->setObjectName(QString::fromUtf8("label_19"));

    vboxLayout6->addWidget(label_19);

    label_20 = new QLabel(groupBox_28);
    label_20->setObjectName(QString::fromUtf8("label_20"));

    vboxLayout6->addWidget(label_20);


    hboxLayout8->addLayout(vboxLayout6);

    vboxLayout7 = new QVBoxLayout();
    vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
    ECUaddressGui = new QLineEdit(groupBox_28);
    ECUaddressGui->setObjectName(QString::fromUtf8("ECUaddressGui"));
    ECUaddressGui->setMaxLength(2);
    ECUaddressGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    vboxLayout7->addWidget(ECUaddressGui);

    TesteraddressGui = new QLineEdit(groupBox_28);
    TesteraddressGui->setObjectName(QString::fromUtf8("TesteraddressGui"));
    TesteraddressGui->setMaxLength(2);
    TesteraddressGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    vboxLayout7->addWidget(TesteraddressGui);


    hboxLayout8->addLayout(vboxLayout7);


    vboxLayout5->addLayout(hboxLayout8);

    hboxLayout9 = new QHBoxLayout();
    hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
    label_9 = new QLabel(groupBox_28);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    hboxLayout9->addWidget(label_9);

    BaudrateGui = new QLineEdit(groupBox_28);
    BaudrateGui->setObjectName(QString::fromUtf8("BaudrateGui"));
    BaudrateGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    hboxLayout9->addWidget(BaudrateGui);


    vboxLayout5->addLayout(hboxLayout9);


    hboxLayout7->addLayout(vboxLayout5);

    line_3 = new QFrame(groupBox_28);
    line_3->setObjectName(QString::fromUtf8("line_3"));
    line_3->setFrameShape(QFrame::VLine);
    line_3->setFrameShadow(QFrame::Sunken);

    hboxLayout7->addWidget(line_3);


    hboxLayout6->addLayout(hboxLayout7);

    vboxLayout8 = new QVBoxLayout();
    vboxLayout8->setObjectName(QString::fromUtf8("vboxLayout8"));
    hboxLayout10 = new QHBoxLayout();
    hboxLayout10->setObjectName(QString::fromUtf8("hboxLayout10"));
    label_21 = new QLabel(groupBox_28);
    label_21->setObjectName(QString::fromUtf8("label_21"));

    hboxLayout10->addWidget(label_21);

    TesterPresentTimeGui = new QLineEdit(groupBox_28);
    TesterPresentTimeGui->setObjectName(QString::fromUtf8("TesterPresentTimeGui"));
    TesterPresentTimeGui->setMaxLength(4);
    TesterPresentTimeGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    hboxLayout10->addWidget(TesterPresentTimeGui);


    vboxLayout8->addLayout(hboxLayout10);

    hboxLayout11 = new QHBoxLayout();
    hboxLayout11->setObjectName(QString::fromUtf8("hboxLayout11"));
    label_23 = new QLabel(groupBox_28);
    label_23->setObjectName(QString::fromUtf8("label_23"));

    hboxLayout11->addWidget(label_23);

    KW82InitMethod = new QComboBox(groupBox_28);
    KW82InitMethod->setObjectName(QString::fromUtf8("KW82InitMethod"));

    hboxLayout11->addWidget(KW82InitMethod);


    vboxLayout8->addLayout(hboxLayout11);


    hboxLayout6->addLayout(vboxLayout8);


    vboxLayout3->addLayout(hboxLayout6);


    vboxLayout2->addLayout(vboxLayout3);

    line_5 = new QFrame(groupBox_28);
    line_5->setObjectName(QString::fromUtf8("line_5"));
    line_5->setFrameShape(QFrame::HLine);
    line_5->setFrameShadow(QFrame::Sunken);

    vboxLayout2->addWidget(line_5);


    vboxLayout1->addLayout(vboxLayout2);

    hboxLayout12 = new QHBoxLayout();
    hboxLayout12->setObjectName(QString::fromUtf8("hboxLayout12"));
    ConnectButton = new QPushButton(groupBox_28);
    ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));

    hboxLayout12->addWidget(ConnectButton);

    spacerItem = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout12->addItem(spacerItem);

    DisconnectButton = new QPushButton(groupBox_28);
    DisconnectButton->setObjectName(QString::fromUtf8("DisconnectButton"));
    DisconnectButton->setEnabled(true);

    hboxLayout12->addWidget(DisconnectButton);


    vboxLayout1->addLayout(hboxLayout12);


    hboxLayout4->addLayout(vboxLayout1);

    groupBox_29 = new QGroupBox(centralwidget);
    groupBox_29->setObjectName(QString::fromUtf8("groupBox_29"));
    groupBox_29->setGeometry(QRect(320, 10, 441, 501));
    ECUInfoButton = new QPushButton(groupBox_29);
    ECUInfoButton->setObjectName(QString::fromUtf8("ECUInfoButton"));
    ECUInfoButton->setGeometry(QRect(10, 60, 75, 24));
    ReadDTCButton = new QPushButton(groupBox_29);
    ReadDTCButton->setObjectName(QString::fromUtf8("ReadDTCButton"));
    ReadDTCButton->setGeometry(QRect(100, 60, 75, 24));
    ClearDTCButton = new QPushButton(groupBox_29);
    ClearDTCButton->setObjectName(QString::fromUtf8("ClearDTCButton"));
    ClearDTCButton->setGeometry(QRect(100, 130, 75, 24));
    InfoWindow = new QListWidget(groupBox_29);
    InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
    InfoWindow->setGeometry(QRect(10, 180, 421, 281));
    line_7 = new QFrame(groupBox_29);
    line_7->setObjectName(QString::fromUtf8("line_7"));
    line_7->setGeometry(QRect(10, 40, 231, 16));
    line_7->setFrameShape(QFrame::HLine);
    line_7->setFrameShadow(QFrame::Sunken);
    layoutWidget = new QWidget(groupBox_29);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(10, 20, 99, 22));
    hboxLayout13 = new QHBoxLayout(layoutWidget);
    hboxLayout13->setObjectName(QString::fromUtf8("hboxLayout13"));
    hboxLayout13->setContentsMargins(0, 0, 0, 0);
    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    hboxLayout13->addWidget(label_2);

    ComBaudrateGui = new QLineEdit(layoutWidget);
    ComBaudrateGui->setObjectName(QString::fromUtf8("ComBaudrateGui"));
    ComBaudrateGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    hboxLayout13->addWidget(ComBaudrateGui);

    layoutWidget1 = new QWidget(groupBox_29);
    layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
    layoutWidget1->setGeometry(QRect(10, 470, 424, 26));
    hboxLayout14 = new QHBoxLayout(layoutWidget1);
    hboxLayout14->setObjectName(QString::fromUtf8("hboxLayout14"));
    hboxLayout14->setContentsMargins(0, 0, 0, 0);
    pushButton_4 = new QPushButton(layoutWidget1);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

    hboxLayout14->addWidget(pushButton_4);

    spacerItem1 = new QSpacerItem(341, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout14->addItem(spacerItem1);

    layoutWidget2 = new QWidget(groupBox_29);
    layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
    layoutWidget2->setGeometry(QRect(250, 20, 181, 142));
    hboxLayout15 = new QHBoxLayout(layoutWidget2);
    hboxLayout15->setObjectName(QString::fromUtf8("hboxLayout15"));
    hboxLayout15->setContentsMargins(0, 0, 0, 0);
    line_6 = new QFrame(layoutWidget2);
    line_6->setObjectName(QString::fromUtf8("line_6"));
    line_6->setFrameShape(QFrame::VLine);
    line_6->setFrameShadow(QFrame::Sunken);

    hboxLayout15->addWidget(line_6);

    vboxLayout9 = new QVBoxLayout();
    vboxLayout9->setObjectName(QString::fromUtf8("vboxLayout9"));
    label_10 = new QLabel(layoutWidget2);
    label_10->setObjectName(QString::fromUtf8("label_10"));

    vboxLayout9->addWidget(label_10);

    vboxLayout10 = new QVBoxLayout();
    vboxLayout10->setObjectName(QString::fromUtf8("vboxLayout10"));
    vboxLayout11 = new QVBoxLayout();
    vboxLayout11->setObjectName(QString::fromUtf8("vboxLayout11"));
    hboxLayout16 = new QHBoxLayout();
    hboxLayout16->setObjectName(QString::fromUtf8("hboxLayout16"));
    hboxLayout17 = new QHBoxLayout();
    hboxLayout17->setObjectName(QString::fromUtf8("hboxLayout17"));
    label_13 = new QLabel(layoutWidget2);
    label_13->setObjectName(QString::fromUtf8("label_13"));

    hboxLayout17->addWidget(label_13);

    lineEditFAD = new QLineEdit(layoutWidget2);
    lineEditFAD->setObjectName(QString::fromUtf8("lineEditFAD"));
    lineEditFAD->setLayoutDirection(Qt::RightToLeft);

    hboxLayout17->addWidget(lineEditFAD);


    hboxLayout16->addLayout(hboxLayout17);

    hboxLayout18 = new QHBoxLayout();
    hboxLayout18->setObjectName(QString::fromUtf8("hboxLayout18"));
    label_14 = new QLabel(layoutWidget2);
    label_14->setObjectName(QString::fromUtf8("label_14"));

    hboxLayout18->addWidget(label_14);

    lineEditFAP = new QLineEdit(layoutWidget2);
    lineEditFAP->setObjectName(QString::fromUtf8("lineEditFAP"));
    lineEditFAP->setLayoutDirection(Qt::RightToLeft);

    hboxLayout18->addWidget(lineEditFAP);


    hboxLayout16->addLayout(hboxLayout18);


    vboxLayout11->addLayout(hboxLayout16);

    hboxLayout19 = new QHBoxLayout();
    hboxLayout19->setObjectName(QString::fromUtf8("hboxLayout19"));
    hboxLayout20 = new QHBoxLayout();
    hboxLayout20->setObjectName(QString::fromUtf8("hboxLayout20"));
    label_16 = new QLabel(layoutWidget2);
    label_16->setObjectName(QString::fromUtf8("label_16"));

    hboxLayout20->addWidget(label_16);

    lineEditSAD = new QLineEdit(layoutWidget2);
    lineEditSAD->setObjectName(QString::fromUtf8("lineEditSAD"));
    lineEditSAD->setLayoutDirection(Qt::RightToLeft);

    hboxLayout20->addWidget(lineEditSAD);


    hboxLayout19->addLayout(hboxLayout20);

    hboxLayout21 = new QHBoxLayout();
    hboxLayout21->setObjectName(QString::fromUtf8("hboxLayout21"));
    label_15 = new QLabel(layoutWidget2);
    label_15->setObjectName(QString::fromUtf8("label_15"));

    hboxLayout21->addWidget(label_15);

    lineEditSAP = new QLineEdit(layoutWidget2);
    lineEditSAP->setObjectName(QString::fromUtf8("lineEditSAP"));
    lineEditSAP->setLayoutDirection(Qt::RightToLeft);

    hboxLayout21->addWidget(lineEditSAP);


    hboxLayout19->addLayout(hboxLayout21);


    vboxLayout11->addLayout(hboxLayout19);

    hboxLayout22 = new QHBoxLayout();
    hboxLayout22->setObjectName(QString::fromUtf8("hboxLayout22"));
    hboxLayout23 = new QHBoxLayout();
    hboxLayout23->setObjectName(QString::fromUtf8("hboxLayout23"));
    label_18 = new QLabel(layoutWidget2);
    label_18->setObjectName(QString::fromUtf8("label_18"));

    hboxLayout23->addWidget(label_18);

    lineEditBPD = new QLineEdit(layoutWidget2);
    lineEditBPD->setObjectName(QString::fromUtf8("lineEditBPD"));
    lineEditBPD->setLayoutDirection(Qt::RightToLeft);

    hboxLayout23->addWidget(lineEditBPD);


    hboxLayout22->addLayout(hboxLayout23);

    hboxLayout24 = new QHBoxLayout();
    hboxLayout24->setObjectName(QString::fromUtf8("hboxLayout24"));
    label_17 = new QLabel(layoutWidget2);
    label_17->setObjectName(QString::fromUtf8("label_17"));

    hboxLayout24->addWidget(label_17);

    lineEditBPP = new QLineEdit(layoutWidget2);
    lineEditBPP->setObjectName(QString::fromUtf8("lineEditBPP"));
    lineEditBPP->setLayoutDirection(Qt::RightToLeft);

    hboxLayout24->addWidget(lineEditBPP);


    hboxLayout22->addLayout(hboxLayout24);


    vboxLayout11->addLayout(hboxLayout22);


    vboxLayout10->addLayout(vboxLayout11);

    ReadResistanceAirbagButton = new QPushButton(layoutWidget2);
    ReadResistanceAirbagButton->setObjectName(QString::fromUtf8("ReadResistanceAirbagButton"));

    vboxLayout10->addWidget(ReadResistanceAirbagButton);


    vboxLayout9->addLayout(vboxLayout10);


    hboxLayout15->addLayout(vboxLayout9);

    SnapshotButton = new QPushButton(groupBox_29);
    SnapshotButton->setObjectName(QString::fromUtf8("SnapshotButton"));
    SnapshotButton->setGeometry(QRect(100, 90, 75, 24));
    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 350, 301, 161));
    hboxLayout25 = new QHBoxLayout(groupBox);
    hboxLayout25->setObjectName(QString::fromUtf8("hboxLayout25"));
    vboxLayout12 = new QVBoxLayout();
    vboxLayout12->setObjectName(QString::fromUtf8("vboxLayout12"));
    hboxLayout26 = new QHBoxLayout();
    hboxLayout26->setObjectName(QString::fromUtf8("hboxLayout26"));
    vboxLayout13 = new QVBoxLayout();
    vboxLayout13->setObjectName(QString::fromUtf8("vboxLayout13"));
    SearchECUProtocolGui = new QComboBox(groupBox);
    SearchECUProtocolGui->setObjectName(QString::fromUtf8("SearchECUProtocolGui"));

    vboxLayout13->addWidget(SearchECUProtocolGui);

    hboxLayout27 = new QHBoxLayout();
    hboxLayout27->setObjectName(QString::fromUtf8("hboxLayout27"));
    vboxLayout14 = new QVBoxLayout();
    vboxLayout14->setObjectName(QString::fromUtf8("vboxLayout14"));
    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    vboxLayout14->addWidget(label_4);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    vboxLayout14->addWidget(label_3);


    hboxLayout27->addLayout(vboxLayout14);

    vboxLayout15 = new QVBoxLayout();
    vboxLayout15->setObjectName(QString::fromUtf8("vboxLayout15"));
    SearchECUStartAddressGui = new QLineEdit(groupBox);
    SearchECUStartAddressGui->setObjectName(QString::fromUtf8("SearchECUStartAddressGui"));
    SearchECUStartAddressGui->setMaxLength(2);
    SearchECUStartAddressGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    vboxLayout15->addWidget(SearchECUStartAddressGui);

    SearchECUStopAddressGui = new QLineEdit(groupBox);
    SearchECUStopAddressGui->setObjectName(QString::fromUtf8("SearchECUStopAddressGui"));
    SearchECUStopAddressGui->setMaxLength(2);
    SearchECUStopAddressGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    vboxLayout15->addWidget(SearchECUStopAddressGui);


    hboxLayout27->addLayout(vboxLayout15);


    vboxLayout13->addLayout(hboxLayout27);


    hboxLayout26->addLayout(vboxLayout13);

    line_2 = new QFrame(groupBox);
    line_2->setObjectName(QString::fromUtf8("line_2"));
    line_2->setFrameShape(QFrame::VLine);
    line_2->setFrameShadow(QFrame::Sunken);

    hboxLayout26->addWidget(line_2);

    hboxLayout28 = new QHBoxLayout();
    hboxLayout28->setObjectName(QString::fromUtf8("hboxLayout28"));
    vboxLayout16 = new QVBoxLayout();
    vboxLayout16->setObjectName(QString::fromUtf8("vboxLayout16"));
    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    vboxLayout16->addWidget(label_5);

    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    vboxLayout16->addWidget(label_6);

    label_7 = new QLabel(groupBox);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    vboxLayout16->addWidget(label_7);


    hboxLayout28->addLayout(vboxLayout16);

    vboxLayout17 = new QVBoxLayout();
    vboxLayout17->setObjectName(QString::fromUtf8("vboxLayout17"));
    SearchECUTesterAddressGui = new QLineEdit(groupBox);
    SearchECUTesterAddressGui->setObjectName(QString::fromUtf8("SearchECUTesterAddressGui"));
    SearchECUTesterAddressGui->setMaxLength(2);
    SearchECUTesterAddressGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    vboxLayout17->addWidget(SearchECUTesterAddressGui);

    SearchECUBaudrateGui = new QLineEdit(groupBox);
    SearchECUBaudrateGui->setObjectName(QString::fromUtf8("SearchECUBaudrateGui"));
    SearchECUBaudrateGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    vboxLayout17->addWidget(SearchECUBaudrateGui);

    SearchECUTimeGui = new QLineEdit(groupBox);
    SearchECUTimeGui->setObjectName(QString::fromUtf8("SearchECUTimeGui"));
    SearchECUTimeGui->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    vboxLayout17->addWidget(SearchECUTimeGui);


    hboxLayout28->addLayout(vboxLayout17);


    hboxLayout26->addLayout(hboxLayout28);


    vboxLayout12->addLayout(hboxLayout26);

    vboxLayout18 = new QVBoxLayout();
    vboxLayout18->setObjectName(QString::fromUtf8("vboxLayout18"));
    line = new QFrame(groupBox);
    line->setObjectName(QString::fromUtf8("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    vboxLayout18->addWidget(line);

    hboxLayout29 = new QHBoxLayout();
    hboxLayout29->setObjectName(QString::fromUtf8("hboxLayout29"));
    SearchECUStartButton = new QPushButton(groupBox);
    SearchECUStartButton->setObjectName(QString::fromUtf8("SearchECUStartButton"));

    hboxLayout29->addWidget(SearchECUStartButton);

    spacerItem2 = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout29->addItem(spacerItem2);

    SearchECUCancelButton = new QPushButton(groupBox);
    SearchECUCancelButton->setObjectName(QString::fromUtf8("SearchECUCancelButton"));

    hboxLayout29->addWidget(SearchECUCancelButton);


    vboxLayout18->addLayout(hboxLayout29);


    vboxLayout12->addLayout(vboxLayout18);


    hboxLayout25->addLayout(vboxLayout12);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 774, 19));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    QWidget::setTabOrder(ComEdit, OpenPortButton);
    QWidget::setTabOrder(OpenPortButton, ClosePortButton);

    retranslateUi(MainWindow);
    QObject::connect(pushButton_4, SIGNAL(clicked()), InfoWindow, SLOT(clear()));

    ChooseSystemGui->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UniECU - Data transfer with protocol KW2000 and KW82", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("MainWindow", "Serial communication interface:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Com Port:", 0, QApplication::UnicodeUTF8));
    ComEdit->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
    OpenPortButton->setText(QApplication::translate("MainWindow", "Open port", 0, QApplication::UnicodeUTF8));
    ClosePortButton->setText(QApplication::translate("MainWindow", "Close port", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("MainWindow", "Status:", 0, QApplication::UnicodeUTF8));
    ComPortStatusLabel->setText(QApplication::translate("MainWindow", "Port closed.", 0, QApplication::UnicodeUTF8));
    groupBox_28->setTitle(QApplication::translate("MainWindow", "Initialisation:", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("MainWindow", "Choose system:", 0, QApplication::UnicodeUTF8));
    ChooseSystemGui->insertItems(0, QStringList()
     << QApplication::translate("MainWindow", "Bosch Motronic 1.5.5 (KW2000)", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("MainWindow", "Airbag-System SAB6 (KW82)", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("MainWindow", "Custom (KW2000)", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("MainWindow", "Custom (KW82)", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("MainWindow", "ABS (KW82)", 0, QApplication::UnicodeUTF8)
    );
    label_19->setText(QApplication::translate("MainWindow", "ECU address:", 0, QApplication::UnicodeUTF8));
    label_20->setText(QApplication::translate("MainWindow", "Tester address:", 0, QApplication::UnicodeUTF8));
    ECUaddressGui->setInputMask(QApplication::translate("MainWindow", "hh; ", 0, QApplication::UnicodeUTF8));
    ECUaddressGui->setText(QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8));
    TesteraddressGui->setInputMask(QApplication::translate("MainWindow", "hh; ", 0, QApplication::UnicodeUTF8));
    TesteraddressGui->setText(QApplication::translate("MainWindow", "f1", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("MainWindow", "Baudrate:", 0, QApplication::UnicodeUTF8));
    BaudrateGui->setText(QApplication::translate("MainWindow", "10400", 0, QApplication::UnicodeUTF8));
    label_21->setText(QApplication::translate("MainWindow", "Tester present time:", 0, QApplication::UnicodeUTF8));
    TesterPresentTimeGui->setText(QApplication::translate("MainWindow", "2000", 0, QApplication::UnicodeUTF8));
    label_23->setText(QApplication::translate("MainWindow", "Init method:", 0, QApplication::UnicodeUTF8));
    KW82InitMethod->insertItems(0, QStringList()
     << QApplication::translate("MainWindow", "5 Baud", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("MainWindow", "200 Baud", 0, QApplication::UnicodeUTF8)
    );
    ConnectButton->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
    DisconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
    groupBox_29->setTitle(QApplication::translate("MainWindow", "Communication:", 0, QApplication::UnicodeUTF8));
    ECUInfoButton->setText(QApplication::translate("MainWindow", "ECU Info", 0, QApplication::UnicodeUTF8));
    ReadDTCButton->setText(QApplication::translate("MainWindow", "Read DTC", 0, QApplication::UnicodeUTF8));
    ClearDTCButton->setText(QApplication::translate("MainWindow", "Clear DTC", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Baudrate:", 0, QApplication::UnicodeUTF8));
    ComBaudrateGui->setText(QApplication::translate("MainWindow", "10400", 0, QApplication::UnicodeUTF8));
    pushButton_4->setText(QApplication::translate("MainWindow", "Clear window", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("MainWindow", "Airbag circuit resistance (ohm):", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("MainWindow", "FAD:", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("MainWindow", "FAP:", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("MainWindow", "SAD:", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("MainWindow", "SAP:", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("MainWindow", "BPD:", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("MainWindow", "BPP:", 0, QApplication::UnicodeUTF8));
    ReadResistanceAirbagButton->setText(QApplication::translate("MainWindow", "Read current values", 0, QApplication::UnicodeUTF8));
    SnapshotButton->setText(QApplication::translate("MainWindow", "Snapshot", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MainWindow", "Search ECU:", 0, QApplication::UnicodeUTF8));
    SearchECUProtocolGui->insertItems(0, QStringList()
     << QApplication::translate("MainWindow", "KW2000", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("MainWindow", "KW82", 0, QApplication::UnicodeUTF8)
    );
    label_4->setText(QApplication::translate("MainWindow", "Start at address:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Stop at address:", 0, QApplication::UnicodeUTF8));
    SearchECUStartAddressGui->setInputMask(QApplication::translate("MainWindow", "hh; ", 0, QApplication::UnicodeUTF8));
    SearchECUStartAddressGui->setText(QApplication::translate("MainWindow", "00", 0, QApplication::UnicodeUTF8));
    SearchECUStopAddressGui->setInputMask(QApplication::translate("MainWindow", "hh; ", 0, QApplication::UnicodeUTF8));
    SearchECUStopAddressGui->setText(QApplication::translate("MainWindow", "00", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindow", "Tester address:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("MainWindow", "Baudrate:", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("MainWindow", "Time interval:", 0, QApplication::UnicodeUTF8));
    SearchECUTesterAddressGui->setInputMask(QApplication::translate("MainWindow", "hh; ", 0, QApplication::UnicodeUTF8));
    SearchECUTesterAddressGui->setText(QApplication::translate("MainWindow", "f1", 0, QApplication::UnicodeUTF8));
    SearchECUBaudrateGui->setText(QApplication::translate("MainWindow", "10400", 0, QApplication::UnicodeUTF8));
    SearchECUTimeGui->setText(QApplication::translate("MainWindow", "2000", 0, QApplication::UnicodeUTF8));
    SearchECUStartButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
    SearchECUCancelButton->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIECU_H

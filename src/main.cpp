/*
 * main.cpp
 *
 * 
*/

#include <QApplication>
#include <QtGui>

#include "UniECU.h"



int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     UniECU *iUniECU = new UniECU;

	 iUniECU->show();
	      	 	 
	 return app.exec();
 } 

/*
 * Wait.cpp
 *
 * 
*/

#include "UniECU.h"

//
// Wait()
//
void UniECU::Wait(unsigned int mSeconds)
{

    liTarget = g_Frequency * (ULONGLONG)mSeconds;
    liTarget = liTarget / (ULONGLONG) 1000; // convert counts per mSecond

    // liTarget is now our target time
    // Query the current counter for start point.
    QueryPerformanceCounter((LARGE_INTEGER*)&liFirst);
    
    liElasped = (ULONGLONG) 0;

    while(liElasped < liTarget) {
        QueryPerformanceCounter((LARGE_INTEGER*)&liSecond);
        liElasped = liSecond - liFirst;
    }
    
}


//
// Clock()
//
void UniECU::Clock(int StartStop)
{
    if (StartStop == 1) {
        QueryPerformanceCounter((LARGE_INTEGER*)&g_CurentCount);    
    }
    if (StartStop == 0) {
        QueryPerformanceCounter((LARGE_INTEGER*)&g_LastCount);
        double dTimeDiff = (((double)(g_LastCount-g_CurentCount))/((double)g_Frequency));  
        InfoWindow->addItem("Time: "+QString::number(dTimeDiff));
    }
       
}

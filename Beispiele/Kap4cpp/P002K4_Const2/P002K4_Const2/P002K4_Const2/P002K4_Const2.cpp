// P002K4_Const2
#include "stdafx.h"
#include <cmath>                                                                   //1
#include <iostream>
#include <iomanip>
using namespace std;
#define EZ 2.718281828459045   //basis logarithmus naturalis (Eulersche Zahl)      //2
#define WBV 0x1A9215340ull         //Weltbevölkerung (01.04.2013                       //3

int main (void)
{
    long long llWBV = WBV;                                                          //4
    double dWBV     = WBV;                                                          //5
    double dEZ      = EZ;                                                           //6
    double dLn      = log (dEZ);                                                    //7
    double dLg      = log10 (dEZ);                                                  //8
    
    cout << "Eulersche Zahl                                   : " << dEZ << endl;   //9
    cout << "dekadischer logarithmus von EZ                   : " << dLg << endl;   //10
    cout << "logarithmus naturalis von EZ                     : " << dLn << endl;   //11
    cout << endl;
    cout << "Welbev\x94lkerung als int                           : " << (int)llWBV
                                                                     << endl;       //12
    cout << "Welbev\x94lkerung als long int                      : " << (long int)llWBV
                                                                     << endl;       //13
    cout << "Welbev\x94lkerung als long long                     : " << llWBV
                                                                     << endl;       //14
    cout << "Welbev\x94lkerung als long (hex-Darst. klein)       : " << hex << llWBV
                                                                     << endl;       //15
    cout << "Welbev\x94lkerung als long long (hex-Darst. gro\xe1)   : "
         << setiosflags (ios::uppercase) << llWBV                    << endl;       //16
    cout << endl;
    cout << "Welbev\x94lkerung als double (Exp.-Darst. gro\xe1)     : "
         << dWBV                                                     << endl;       //17
    cout << "Welbev\x94lkerung als double (Exp.-Darst. klein)    : "
         << resetiosflags (ios::uppercase) << dWBV                   << endl;       //18
         
    return 0;
}
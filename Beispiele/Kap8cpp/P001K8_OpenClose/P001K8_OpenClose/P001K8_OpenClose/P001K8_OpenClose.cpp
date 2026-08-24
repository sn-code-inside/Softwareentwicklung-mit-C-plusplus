// P001K8_OpenClose.cpp
#include "stdafx.h"
#include <fstream>                                                                  // 1
#include <iostream>
using namespace std;
int main(void)
{
    // ifstream inFile("..\\Debug\\P001K8_OpenClose.EXE", ios::in|ios::binary);     // 2
    ifstream inFile;                                                                // 3
    inFile.open("..\\Debug\\P001K8_OpenClose.EXE", ios::in|ios::binary);            // 4
    if(false == inFile.good())                                                      // 5
    {
        cout << "Fehler beim Oeffnen von P001K8_OpenClose.EXE.\n";
        return 1;
    }
    inFile.close();                                                                 // 6
        if(false == inFile.good())
    {
        cout << "Fehler beim Schliessen von P001K8_OpenClose.EXE. \n ";
        return 2;
    }
        cout << "P001K8_OpenClose.EXE konnte geoeffnet und geschlossen werden. \n ";// 7
        return 0;
}
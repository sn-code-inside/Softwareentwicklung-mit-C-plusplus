// Auf1K9.cpp
#include "stdafx.h"
#include "cSquareMatrix.h"
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
void showMatrix (int *iM, unsigned int uiForm)
{
    int iRow = 0;
    for (int i=0; i<(int)((uiForm)*(uiForm)); i++)
    {
        cout << iM[i] << "\t"; iRow++;
        if ( iRow == (int)uiForm )
        {
            iRow = 0;
            cout << "\n";
        }
    }
}

int main(void)
{
    //=========================================
    LPCTSTR str = L"Auf1K9";
    printConsole(str);
    //=========================================
    unsigned int uiForm = 3;
    int iM1[9] = {1,  3,  2,  9, 4, 12, 18, 6, 36};
    int iM2[9] = {36, 12, 18, 4, 9, 3,  2,  6, 1};

    cout << "Ausgangsmatrizen:\n";
    cout << "M1:\n";
    showMatrix ((int*)&iM1, uiForm);
    cout << "\n\nM2:\n";
    showMatrix ((int*)&iM2, uiForm);

    cSquareMatrix M1 ((int*)&iM1, uiForm);
    cSquareMatrix M2 ((int*)&iM2, uiForm);
    cSquareMatrix MRes = M1*M2;

    cout << "\n\nResultierende Matrix (MRes = M1*M2):\n";
    cout << "MRes:\n";
    showMatrix (MRes.getMatrix(), uiForm);

    return 0;
}

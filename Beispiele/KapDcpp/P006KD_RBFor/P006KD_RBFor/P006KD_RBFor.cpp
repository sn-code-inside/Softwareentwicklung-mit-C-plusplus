// P006KD_RBFor.cpp
#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
int main(void)
{
    //=========================================
    LPCTSTR str = L"P006KD_RBFor";
    printConsole(str);
    //=========================================
    vector<int> v{1,2,3,4,5};           //ein Container mit den int 1-5 
    for (int i : v)                     //oder:   for (auto i : v)  
        cout << i << "\t";              //gibt aus: 1 2 3 4 5
    cout << endl;

    double u[] = { 1.,2.1,-3. };        //ein C-Array
    for (auto x : u)                    //x hat den Typ, den u speichert  (double)
        cout << x << "\t";              //gibt aus: 1 2.1 -3
    cout << endl;

    int i = 0;
    for (auto x : u)                    //x durchläuft alle Werte von u
    {
        x = 5;                          //das ändert die Index-Variable x, aber nicht u !!! 
        cout << "x=" << x << "\tu=" << u[i++] << "\t";
    }
    cout << endl;

    i = 0;
    for (auto& x : u)                   //x durchläuft alle Elemente von u per Referenz
    {
        x = 5;                          //ändert alle Elemente von u auf 5!!!!!
        cout << "x=" << x << "\tu=" << u[i] << "\t";
    }
    cout << endl;

    //for (const auto& x : u)             
    //    x = 5;                        //Fehler, da x konstant ist
     
    for (int n = 0; auto x : u)         //n zur Nummerierung  
        cout << "u[" << n++ << "] = " << x << '\n';

    return 0;
}


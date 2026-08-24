// P003K4_VarBook.cpp 
// 
//
#include <iostream>
using namespace std;
int main(void)
{
    int iX = 1;                                         //1
    cout << "iX vor Scope      : " << iX << endl;       //2
    { //---------------------------------------StartOfScope
        int i = 0;                                     //3
        cout << "iX im Scope       : " << iX << endl;   //4
        cout << "i im Scope        : " << i << endl;   //5
        i++;                                            //6
        iX++;                                           //7
        int iX = 25;                                    //8
        cout << "Neues iX im Scope : " << iX << endl;   //9
        iX++;                                           //10
    } //------------------------------------------EndOfScope
    //cout << "i nach Scope      : " << i  << endl;     //11
    cout << "iX nach Scope     : " << iX << endl;       //12
    return 0;
}


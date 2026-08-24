// P003K4_VarAuto

#include "stdafx.h"
#include <typeinfo>
#include <iostream>
using namespace std;

int main (void)
{
	auto aTest1 = 3.1;
    auto aTest2 = 3;
    auto aTest3 = 'A';
    const type_info &tInf1 = typeid (aTest1);
    cout << "Name des auto-Types: " << tInf1.name() << endl;
    cout << "Wert des auto-Types: " << aTest1 << endl;
    cout << "Size des auto-Types: " << sizeof (aTest1) << endl << endl;

    const type_info &tInf2 = typeid (aTest2);
    cout << "Name des auto-Types: " << tInf2.name() << endl;
    cout << "Wert des auto-Types: " << aTest2 << endl;
    cout << "Size des auto-Types: " << sizeof (aTest2) << endl << endl;

    const type_info &tInf3 = typeid (aTest3);
    cout << "Name des auto-Types: " << tInf3.name() << endl;
    cout << "Wert des auto-Types: " << aTest3 << endl;
    cout << "Size des auto-Types: " << sizeof (aTest3) << endl << endl;
 
    return 0;
}


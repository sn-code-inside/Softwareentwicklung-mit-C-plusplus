// WCoutEx.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include<wchar.h>
using namespace std;

int _tmain (void)
{
    wchar_t wcArr[3];
    //_wsetlocale (LC_ALL, L"CJK");

    wcArr[0] = 0x8000;
    wcArr[1] = 0x8001;
    wcArr[2] = 0;
    wcout << wcArr;
	return 0;
}


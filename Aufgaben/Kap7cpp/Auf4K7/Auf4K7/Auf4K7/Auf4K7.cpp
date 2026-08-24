//Auf4K7.cpp
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
int main(int argc, char* argv[])
{
    try
    {
        if (argc > 1)
        {
            invalid_argument Err(" Es wurden Parameter uebergeben.\n");
            throw Err;
        }
        else
        {
            cout << "Programmname (Debug-Version): \n" << argv[0] << endl;
        }
    }
    catch (invalid_argument& Err) { cout << Err.what(); }
    return 0;
}

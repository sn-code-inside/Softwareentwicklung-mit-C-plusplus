// P00AK3Ignore.cpp
#include "stdafx.h"
#include <iostream>

const int iMax = 3;                                 //1
int main (void)
{
    char cStr1[iMax];                               //2
    char cStr2[iMax];                               //3
    int iTest = 0;                                  //4
    std::cin >> iTest;                              //5
    //std::cin.ignore (1);                          //6
    std::cin.getline (cStr1, iMax);                 //7
    std::cin.getline (cStr2, iMax);                 //8
    std::cout << std::endl << cStr2 << std::endl;   //9
    std::cout << cStr1 << std::endl;                //10
    std::cout << iTest << std::endl;                //11
	return 0;
}


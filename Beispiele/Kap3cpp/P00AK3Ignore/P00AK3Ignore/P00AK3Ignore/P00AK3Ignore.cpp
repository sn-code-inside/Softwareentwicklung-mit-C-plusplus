// P00AK3Ignore.cpp
#include "stdafx.h"
#include <iostream>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
const int iMax = 30;                                 //1
int main (void)
{/*
    char cStr1[iMax] = { 0 };                       //2
    char cStr2[iMax] = { 0 };                       //3
    //=========================================
    CONST WCHAR * str = L"P008K3coutManip";
    printConsole (str);
    //========================================= 
    int iTest = 0;                                  //4
    //std::cin >> std::ws;
    std::cin >> iTest;                              //5
    std::cin.ignore (1);                          //6
    std::cin.getline (cStr1, iMax);                 //7
    std::cin.getline (cStr2, iMax);                 //8
    std::cout << std::endl << cStr2 << std::endl;   //9
    std::cout << cStr1 << std::endl;                //10
    std::cout << iTest << std::endl;                //11
    return 0;
    */
    char cStr1[iMax] = { 0 };                                          //2
    char cStr2[iMax] = { 0 };                                          //3
    int iTest = 0;                                                     //4
    std::cout << "cin iTest  : "; std::cin >> iTest;                   //5
    //std::cin.ignore(1);                                              //6
    std::cout << "cin Str1   : "; std::cin.getline(cStr1, iMax);       //7
    std::cout << "cin Str2   : "; std::cin.getline(cStr2, iMax);       //8
    std::cout << std::endl;
    std::cout << "cout Str2  : " << cStr2 << std::endl;                //9
    std::cout << "cout Str1  : "; std::cout << cStr1 << std::endl;     //10
    std::cout << "cout iTest : " << iTest << std::endl;                //11
    return 0;
     
}


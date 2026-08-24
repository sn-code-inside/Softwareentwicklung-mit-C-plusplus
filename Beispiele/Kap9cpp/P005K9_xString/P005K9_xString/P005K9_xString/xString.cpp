#include "stdafx.h"
#include "xString.h"
#include <string.h>
#include <iostream>
using namespace std;
xString::xString(char* str)
{
    myString_ = new char [strlen(str)+1];                       //CPP1
    strcpy_s (myString_, strlen(str)+1, str);                   //CPP2
    cout << ">> Konstruktor fuer " << myString_ << endl;
}
xString::~xString(void)
{
    cout << ">> Destruktor fuer " << myString_ << endl;
    delete [] myString_;                                        //CPP3
}
char *xString::getString(void)
{
    return myString_;                                           //CPP4
}
xString xString::operator + (xString& str2)                     //CPP5
{
    int iLen1 = strlen(myString_);
    int iLen2 = strlen(str2.getString());
    int iLenAll = iLen1+iLen2+1;                                //CPP6
    char * strResString = new char [iLenAll];                   //CPP7
    strcpy_s (strResString, iLenAll, myString_);
    strcat_s (strResString, iLenAll, str2.getString());         //CPP8
    xString *strRes = new xString(strResString);                //CPP9
    delete []strResString;                                      //CPP10
    return *strRes;                                             //CPP11
}
xString xString::addStr (xString& str2)                     
{
    int iLen1 = strlen(myString_);
    int iLen2 = strlen(str2.getString());
    int iLenAll = iLen1+iLen2+1;                            
    char * strResString = new char [iLenAll];               
    strcpy_s (strResString, iLenAll, myString_);
    strcat_s (strResString, iLenAll, str2.getString());     
    xString *strRes = new xString(strResString);            
    delete []strResString;                                  
    return *strRes;                                         
}
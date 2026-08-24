#include "stdafx.h"
#include "xString.h"
#include <string.h>
#include <iostream>
using namespace std;
void subStr (xString& str, char* strSub)                            //CPP1
{
    char * strIn = strstr (str.myString_, strSub);
    if (strIn)
        strIn [0] = 0;
}
void operator -= (xString& str, char* strSub)                       //CPP2
{
    subStr (str, strSub);
}
xString::xString(char* str)
{
    myString_ = new char [strlen(str)+1];                       
    strcpy_s (myString_, strlen(str)+1, str);                   
    cout << ">> Konstruktor fuer " << myString_ << endl;
}
xString::~xString(void) {
    cout << ">> Destruktor fuer " << myString_ << endl;
    delete [] myString_;                                        
}
char *xString::getString(void) {
    return myString_;                                           
}
xString xString::operator + (xString& str2)  {
    return addStr (str2);
}
xString xString::operator - (xString& str2)                         //CPP3
{
    char * strIn = strstr (myString_, str2.getString());
    if (strIn)
        strIn [0] = 0;
    xString *strRes = new xString (myString_);
    return *strRes; 
}
xString xString::addStr (xString& str2)  {
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
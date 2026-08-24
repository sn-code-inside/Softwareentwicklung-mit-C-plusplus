#include "stdafx.h"
#include "xString.h"
#include <string.h>
#include <iostream>
using namespace std;
void subStr (xString& str, char* strSub)                            
{
    char * strIn = strstr (str.myString_, strSub);
    if (strIn)
        strIn [0] = 0;
}
void operator -= (xString& str, char* strSub)                       
{
    subStr (str, strSub);
}
/*
void operator += (xString& str, char* strSub)                       //1                 
{
    int iLMy = strlen (str.myString_)+strlen (strSub)+1;            //2
    char * strTemp = new char[iLMy];                                //3
    strcpy_s (strTemp, iLMy, str.myString_);                        //4
    delete [] str.myString_;                                        //5
    str.myString_ = new char[iLMy];                                 //6
    strcpy_s (str.myString_, iLMy, strTemp);                        //7
    delete [] strTemp;                                              //8
    strcat_s (str.myString_, iLMy, strSub);                         //9
}
*/
xString::xString(char* str)
{
    myString_ = new char [strlen(str)+1];                       
    strcpy_s (myString_, strlen(str)+1, str);  
    cout << ">> Konstruktor fuer " << myString_ << endl;
}
xString::xString(void)                                              //10
{
    myString_ = NULL;   
    cout << ">> Konstruktor fuer " << NULL << endl;
}
xString::~xString(void) {
    if (myString_)
    {
        cout << ">> Destruktor fuer " << myString_ << endl;
        delete [] myString_; 
        myString_=NULL;
    }
    else
        cout << ">> Destruktor fuer " << NULL << endl;
}
xString::xString(const xString& str)                                //11                
{
    if (str.myString_)                                              //12
    {
        myString_ = new char[strlen (str.myString_)+1];             //13
        strcpy_s (myString_, strlen (str.myString_)+1, str.myString_); 
        cout << ">> (Copy-)Konstruktor fuer " << myString_ << endl;
    }
    else
    {
        myString_ = NULL;
        cout << ">> (Copy-)Konstruktor fuer " << NULL << endl;
    }

 }
xString::xString ( const xString&& str)                            //Move Konstruktor
{
    myString_=(move (str.myString_));
}
 xString& xString::operator=(const xString& str)                    //14
 {
     if (myString_)                                                 //15
         delete [] myString_;
     if (str.myString_)                                             //16
     {
        myString_ = new char[strlen (str.myString_)+1];             //17
        strcpy_s (myString_, strlen (str.myString_)+1, str.myString_); 
     }
    else
        myString_ = NULL;                                           //18
     return *this;                                                  //19
 }
char *xString::getString(void) {
    return myString_;                                           
}
xString xString::operator + (xString& str2)  {
    return addStr (str2);
}
xString xString::operator - (xString& str2)                         
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
void xString::operator += (char* strSub)                                            
{
    int iLMy = strlen (myString_)+strlen (strSub)+1;           
    char * strTemp = new char[iLMy];                               
    strcpy_s (strTemp, iLMy, myString_);                       
    delete [] myString_;                                       
    myString_ = new char[iLMy];                                
    strcpy_s (myString_, iLMy, strTemp);                       
    delete [] strTemp;                                             
    strcat_s (myString_, iLMy, strSub);                        
}
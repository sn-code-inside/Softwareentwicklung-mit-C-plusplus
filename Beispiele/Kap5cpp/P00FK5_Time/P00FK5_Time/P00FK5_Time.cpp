// P00FK5_Time.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <ctime>
#include <clocale>                                 //1
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_BUFF 1024   
int main (void)
{
    time_t tLocalTime;                          
    struct tm tTimeInf;                         
    char strDateTime [MAX_BUFF];
    int iSelect;                                    //2
    errno_t uiError;    

    struct lconv * ptr2LConv;                       //3      
    char *strLoc;
    //=========================================
    //CONST WCHAR * str = L"P00FK6_Time";
    const char *str = "P00FK5_Time";
    printConsole(str);  
    //========================================= 

    tLocalTime = time ( NULL );                     //4
    uiError = localtime_s (&tTimeInf, &tLocalTime); //5
    iSelect=0;                                      //6
    strLoc = setlocale(LC_ALL,NULL);                //7
    do
    {
        cout << "Locale is: " << strLoc << endl;    //8
        strftime (strDateTime, MAX_BUFF, "%c", 
                  &tTimeInf);                       //9
        cout << "Date is: " << strDateTime << endl; //10
        ptr2LConv = localeconv ();                  //11

        cout << "Currency symbol is: " 
             << ptr2LConv->int_curr_symbol 
             << endl << "-" << endl;                //12

        if (iSelect==0)                             //13
            strLoc = setlocale (LC_ALL,"German");   //14
        else if (iSelect == 1)                  
            strLoc = setlocale (LC_ALL,"English");  //15
        else if (iSelect==2)
            strLoc = setlocale (LC_ALL,"Japanese"); //16 
     } while (iSelect++<3);                         //17
    return 0;
}

/*
#include <iostream>
using namespace std;
#include <ctime>
#include <locale.h>                                  //1
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_BUFF 1024   
int main (void)
{
    time_t tLocalTime;                          
    struct tm tTimeInf;                         
    char strDateTime [MAX_BUFF];
    int iSelect;                                    //2
    errno_t uiError;    

    struct lconv * ptr2LConv;                       //3      
    char *strLoc;
    //=========================================
    CONST WCHAR * str = L"P00FK5_Time";
    //printConsole(str);  
    //========================================= 

    tLocalTime = time ( NULL );                     //4
    uiError = localtime_s (&tTimeInf, &tLocalTime); //5
    iSelect=0;                                      //6
    strLoc = setlocale(LC_ALL,NULL);                //7
    do
    {
        cout << "Locale is: " << strLoc << endl;    //8
        strftime (strDateTime, MAX_BUFF, "%c", 
                  &tTimeInf);                       //9
        cout << "Date is: " << strDateTime << endl; //10
        ptr2LConv = localeconv ();                  //11
        cout << "Currency symbol is: " 
             << ptr2LConv->int_curr_symbol << endl;
        printf ("Currency symbol is: %s\n-\n",
                 ptr2LConv->int_curr_symbol);       //12

        if (iSelect==0)                             //13
            strLoc = setlocale (LC_ALL,"German");   //14
        else if (iSelect == 1)                  
            strLoc = setlocale (LC_ALL,"English");  //15
        else if (iSelect==2)
        {
            strLoc = setlocale (LC_ALL,"Japanese"); //16  
            //strLoc = setlocale(LC_ALL,"German_Switzerland.1252") ; 
        }
     } while (iSelect++<3);                         //17
    return 0;
}
*/
//P009K4_BitfelderGCC.c 
#include <string.h>
#include <stdbool.h>                                //1
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================   
int main (void)
{
    //=========================================
    LPCTSTR str = "P009K4_Bitfelder";
    printConsole(str);
    //========================================= 
    struct tMitarbeiterBool                         //2         
    {
        char cVorname[16];                          //3
        char cNachname[16];                     
        bool bLanJava;                              //4
        bool bLanPerl;
        bool bLanC;
        bool bLanCpp;
        bool bRes1;
        bool bRes2;
        bool bRes3;
        bool bRes4;
        bool bRes5;
    };
    struct tMitarbeiterBool mitarbeiterBool;        //5
    unsigned int usSize = sizeof (mitarbeiterBool); //6
    printf ("Sizeof mitarbeiterBool: %u\n", usSize);//7
            
    struct tMitarbeiterBF                           //8                           
    {
        char cVorname[16];
        char cNachname[16];  
        unsigned char cLanJava:1;                   //9
        unsigned char cLanPerl:1;
        unsigned char cLanC:1;
        unsigned char cLanCpp:1;
        unsigned char cRes1:1;
        unsigned char cRes2:1;
        unsigned char cRes3:1;
        unsigned char cRes4:1;
    };
    struct tMitarbeiterBF mitarbeiterBF;            //10
    usSize = sizeof (mitarbeiterBF);                //11
    printf ("Sizeof mitarbeiterBF  : %u\n", usSize);//12       
    return 0;
}

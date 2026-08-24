//P004K4_Struct2
#include <stdio.h>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 
int main (void)
{
    struct tPerson                                             
    {
        unsigned short usAge;                                  
        unsigned short usSize;                                 
        float fWeight;                                         
        char cName[256];                                       
    };
    struct tPerson person1 = {32, 180, 81.5, "Anton Aue"};                     //1
    //=========================================
    CONST WCHAR * str = L"P004K4_Struct2";
    printConsole(str);
    //========================================= 
    printf ("Alter: %i, Gr\x94\xe1 \be: %i, Gewicht: %.1f, Name: %s\n",        //2
            person1.usAge, person1.usSize, person1.fWeight, person1.cName); 

    return 0;
}
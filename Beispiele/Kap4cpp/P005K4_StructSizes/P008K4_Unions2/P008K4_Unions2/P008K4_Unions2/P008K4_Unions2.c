//P008K4_Unions2
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
    union souUnion                                                      //1                                                     
    {
        char cTest;                                                     //2
        short siTest;                                                   //3
        int iTest;                                                      //4
        long long llTest;                                               //5
    } vUnion;                                                           //6
    CONST WCHAR * str = L"P008K4_Unions2";
    vUnion.llTest  = 0x4c4c4c4c4c4c4c4c;                                //7
    vUnion.iTest   = 0x5d5d5d5d;                                        
    vUnion.siTest  = 0x6e6e;                                            
    vUnion.cTest   = 0x7f;           
    //=========================================

    printConsole(str);
    //========================================= 
    printf ("cTest: %x; siTest: %x; iTest: %x; llTest: %llx\n",         //8
             vUnion.cTest, vUnion.siTest, vUnion.iTest, vUnion.llTest); 
    printf ("Der belegte Speicher von vUnion: %u", sizeof (vUnion));    //9
    return 0;
}
//P06K4_StructFiles
#include <stdio.h>
//#pragma pack(2)
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 
int main (void)
{
    struct tTest                                                            //1          
    {
        unsigned char ucByte;
        unsigned int usiNumb;
    };

    int i=0;                                                                //2
    struct tTest test [3];                                                  //3
    size_t uiSOTest;                                                        //4
    FILE *p2FDatei;		                                                    //5
    errno_t err;                                                            //6
    //--- for Schleife--------------------------start                       //7
    //=========================================
    CONST WCHAR * str = L"P06K4_StructFiles";
    printConsole(str);
    //=========================================  
    for (i=0; i<3; i++)
    {
        test[i].ucByte  = i+1; 
        test[i].usiNumb = i+0x1001u;
    }
    //--- for Schleife----------------------------end
    uiSOTest = sizeof (test);                                               //8
    printf ("Die drei Variablen im array test belegen %i Bytes.", uiSOTest);//9
    //---File test.bin schreiben----------------start                       //10
    err = fopen_s(&p2FDatei, "test.bin", "wb");                             		
    if(p2FDatei != NULL)                                                    
    {
        fwrite ((const char *)test , 1 , uiSOTest , p2FDatei );         
        fclose(p2FDatei);
    }
    //---File test.bin schreiben------------------end
    return 0;
}
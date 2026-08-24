//P002K3crlf
#include <stdio.h>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================             
int main ()
{
    //=========================================
    CONST WCHAR * str = L"P002K3crlf";
    printConsole(str);
    //========================================= 
	printf (" 1");	//Cursor steht eine Zeile unter dem Space von " 1"
	printf (" \n");  //Cursor steht eine Zeile unter dem Space von " 1"
	printf (" 2");
	printf (" \n");	
	printf (" 3");
	printf (" \n");
	return 0;
}
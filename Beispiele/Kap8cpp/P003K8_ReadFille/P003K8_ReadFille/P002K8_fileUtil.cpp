//P002K8_fileUtil.cpp
#include "P002K8_fileUtil.h"
#include <fstream>                                                              
using namespace std;                                                            

cFUtils::cFUtils(const char *strFileName)
{
    strFName_ =  new char [strlen(strFileName)+sizeof(char)];
    strcpy_s (strFName_, strlen(strFileName)+sizeof(char), strFileName);
    iFLenght_ = 0;          //Filelänge wird auf 0 gesetzt 
    strFBuff_ = NULL;       //FileBuffer wird auf 0 gesetzt
}

cFUtils::~cFUtils(void)
{
    delete [] strFName_;
    if (strFBuff_)
        delete [] strFBuff_;
}

/*===========================================================================*/
/* Desc.: Prüft, ob ein File mit dem Namen strFileName vorhanden ist.        */
/*        strFileName beinhaltet Name und Pfad des Files. Falls nur der Name */
/*        angegeben wird, so muss sich das File im dem Directory des auf-    */
/*        rufenden EXE-Files befinden.                                       */
/* In   : strFileName (const char *): Filename                               */
/* Out  : bool :Return: Hinweis (true : File existiert;                      */
/*                               false: File existiert nicht)                */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
bool cFUtils::fileExist (void)       
/*---------------------------------------------------------------------------*/
{                                            
    ifstream inFile(strFName_, ios::in|ios::binary);                  
    if (inFile.good()) 
    {
        inFile.close();
        return true;
    }
    return false;                                                                
}

/*===========================================================================*/
/* Desc.: Es wird das File mit dem Namen strFName_ gelesen.                  */
/* In   : -                                                                  */
/* Out  : FileLaenge                                                         */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
int cFUtils::readFile (void)       
/*---------------------------------------------------------------------------*/
{                                            
    ifstream inFile(strFName_, ios::in|ios::binary);                  
    if (inFile.good()) 
    {
        inFile.seekg (0, inFile.end);           //Setzt den Filepointer an das Ende des Files
        iFLenght_ = (int)inFile.tellg ();       //Fileänge wird ermittelt
        strFBuff_ = new char [iFLenght_];
        inFile.seekg (0, inFile.beg);           //Setzt den Filepointer wieder an den Anfang des Files
        inFile.read (strFBuff_, iFLenght_);
        inFile.close();
    }
    return iFLenght_;                                                                
}

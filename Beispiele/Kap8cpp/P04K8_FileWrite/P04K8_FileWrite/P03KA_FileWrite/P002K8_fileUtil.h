//P002K8_fileUtil.h
/*===========================================================================*/
//Autor        : NN
//Creation Date: 03.04.2013
//Modul-Desc.  : Sammlung spezieller Funktionen zum Filehandling
/*===========================================================================*/
#ifndef _P002K8_FILEUTIL_                                                           
#define _P002K8_FILEUTIL_                                                           

class cFUtils
{
public:
    cFUtils(const char *strFileName);
    ~cFUtils(void);
    //Desc.: Prüft, ob ein File mit dem Namen strFileName vorhanden ist 
    bool fileExist (void);
    //Desc.: Liest ein File; File-Länge wird zurück gegeben
    int readFile (void);
    //Desc.: Beschreibt ein File
    bool writeFile (char * str);    
    //Desc.: Gibt den FileBuffer zurück
    char *getFileBuff (void){return strFBuff_;}
    //Desc.: Gibt den Filelänge zurück
    int getFileLen (void) {return iFLenght_;}
private:
    char *strFName_;                //Name des Files
    int  iFLenght_;                 //Filelänge
    char* strFBuff_;                //FileBuffer
};
#endif
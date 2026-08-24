#pragma once
#include <windows.h> 
#include <stdio.h>
const int ciBlack   = 0x00; const int ciDGray   = 0x08;    
const int ciBlue    = 0x01; const int ciLBlue   = 0x09;   
const int ciGreen   = 0x02; const int ciLGreen  = 0x0a;   
const int ciCyan    = 0x03; const int ciLCyan   = 0x0b;   
const int ciRed     = 0x04; const int ciLRed    = 0x0c;
const int ciMagenta = 0x05; const int ciLMagenta= 0x0d;
const int ciBrown   = 0x06; const int ciYellow  = 0x0e;
const int ciLGray   = 0x07; const int ciWhite   = 0x0f;

class cConsole
{
public:
    cConsole(void);
    ~cConsole(void);
    /// Löscht eine Zeile der Länge iLen.
    void delLine (COORD Pos, int iLen);
    /// Ermittlung des Namens der Vordergrundfarbe
    const char* strColor2String (int iColor);
    /// Ausgabe eines Textes an der CursorPos
    void printfStrWithColorAtPos(COORD Pos, char *str, int iColor);
    /// Ausgabe eines Textes an der CursorPos
    void printfWithColor(char * str, int iColor);
    /// Ausgabe des Namens der Konsole als Titel
    void printConsole (LPCTSTR lpConsoleTitle);
    /// Löscht alle Tasten aus dem Puffer.
    void clearKeyBuffer (void);
    /// Liest Key von Tastatur wenn diese gedrueckt wurde 
    char getKey (void);
    /// setzt KeyReceived 
    void setReceived (bool);
    /// returned ob Taste im Thread angekommen ist 
    bool getReceived (void);
    /// Setzt das consSection_                                             
    void enterSection (void);
    /// Gibt die consSection_  wieder frei
    void leaveSection (void);
    /// Initialisiert die consSection_                                    
    void initSection (void);

private:
    CRITICAL_SECTION consSection_;                                          
    HANDLE  hConsole_; 
    char strColor_[16];
    bool bReceived_;                //true, falls Taste im Thread angekommen ist; sonst false
};


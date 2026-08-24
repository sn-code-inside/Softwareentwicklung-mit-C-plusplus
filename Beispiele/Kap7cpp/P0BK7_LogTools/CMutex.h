#pragma once
#include <Windows.h>

class CMutex
{
public:
    CMutex(void);
    ~CMutex(void);
    DWORD lockMutex(void);
    DWORD unlockMutex(void);
private:
    static HANDLE HdlMutex_;
    static int iObjCounter_;
};



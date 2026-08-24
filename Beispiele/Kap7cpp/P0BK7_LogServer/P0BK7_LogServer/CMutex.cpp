#include "CMutex.h"
#include <Windows.h>
#include <atlstr.h>

int CMutex::iObjCounter_;
CMutex::CMutex(void)
{
    if (iObjCounter_ == 0)
    {
        CString sMutextName = L"Global\\LogServer";
        HdlMutex_ = CreateMutex(NULL, FALSE, sMutextName);
    }
    iObjCounter_++;
}
CMutex::~CMutex(void)
{
    if (iObjCounter_==0)
        CloseHandle(HdlMutex_);
    else
        iObjCounter_--;
}

DWORD CMutex::lockMutex(void)
{
    DWORD dwWaitResult = WaitForSingleObject(HdlMutex_, INFINITE);
    return dwWaitResult;
}

DWORD CMutex::unlockMutex(void)
{
    DWORD dwWaitResult = ReleaseMutex(HdlMutex_);
    return dwWaitResult;
}
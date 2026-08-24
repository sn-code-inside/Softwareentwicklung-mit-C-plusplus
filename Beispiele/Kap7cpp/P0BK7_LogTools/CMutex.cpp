#include "CMutex.h"
#include <Windows.h>
#include <atlstr.h>

int CMutex::iObjCounter_;
HANDLE CMutex::HdlMutex_;
CMutex::CMutex(void)
{
    if (iObjCounter_ == 0)
    {
        CString sMutexName = L"Global\\LogSrvLogSnd";
        HdlMutex_ = CreateMutex(NULL, FALSE, sMutexName);
    }
    iObjCounter_++;
}
CMutex::~CMutex(void)
{
    iObjCounter_--;
    if (iObjCounter_==0)
        CloseHandle(HdlMutex_);
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
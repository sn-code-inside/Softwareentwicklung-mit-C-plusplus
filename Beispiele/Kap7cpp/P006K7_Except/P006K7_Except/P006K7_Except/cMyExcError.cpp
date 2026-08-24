#include "stdafx.h"
#include "cMyExcError.h"
#include <string>

cMyExcError::cMyExcError(char *strErrMsg)
{
    strcpy_s (strMsg_, iMAX_STR, strErrMsg);                  
}


cMyExcError::~cMyExcError(void)
{
}

char *cMyExcError::getErrHint (void)
{
    return strMsg_;
}
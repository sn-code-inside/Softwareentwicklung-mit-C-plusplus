#pragma once
#define iMAX_STR    81                                   
class cMyExcError
{
public:
    cMyExcError(char *);                                    
    ~cMyExcError(void);
    char *getErrHint (void);
private:
    char strMsg_[iMAX_STR];
};


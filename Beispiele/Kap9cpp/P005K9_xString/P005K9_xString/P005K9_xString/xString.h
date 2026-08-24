#pragma once
class xString
{
public:
    xString(char*);
    ~xString(void);
    char* getString (void);
    xString operator + (xString&);
    xString addStr (xString&);   
private:
    char *myString_;
};


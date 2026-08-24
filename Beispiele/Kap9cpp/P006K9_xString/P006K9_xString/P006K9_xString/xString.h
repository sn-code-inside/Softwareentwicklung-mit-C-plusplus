#pragma once
class xString
{
void friend subStr (xString& str, char* strSub);                //H1
void friend operator -= (xString& str, char* strSub);           //H2
public:
    xString(char*);
    ~xString(void);
    char* getString (void);
    xString operator + (xString&);
    xString operator - (xString&);                              //H3       
    xString addStr (xString&);   
private:
    char *myString_;
};


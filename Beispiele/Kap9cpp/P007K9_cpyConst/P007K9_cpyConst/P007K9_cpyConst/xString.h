#pragma once
class xString
{
void friend subStr (xString& str, char* strSub);                
void friend operator -= (xString& str, char* strSub); 
//void friend operator += (xString& str, char* strSub);   //additive Zuweisung    
public:
    xString(char*);
    xString(void);
    ~xString(void);
    xString( const xString&);                           //Copy Konstruktor
    xString& operator=(const xString&);                 //Zuweisungsoperator
    char* getString (void);
    xString operator + (xString&);
    xString operator - (xString&);                                     
    xString addStr (xString&);  
    void operator += (char* strSub);                    //additive Zuweisung  
private:
    char *myString_;
};


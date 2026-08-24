// P004K4_Struct
#include "stdafx.h"
int main (void)
{
    struct tPerson                                              //1
    {
        unsigned short usAge;                                   //2  
        unsigned short usSize;                                  //2
        float fWeight;                                          //4
        char cName[256];                                        //5
    };
    tPerson person1;// = {33, 180, 81.5, "Anton Aue"};          //6
    //person1.usAge = 33;                                       //7
}

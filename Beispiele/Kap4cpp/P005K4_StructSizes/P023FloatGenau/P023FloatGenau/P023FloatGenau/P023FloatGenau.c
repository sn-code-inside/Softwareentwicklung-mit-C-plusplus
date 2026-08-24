//P023FloatGenau.c
#include <stdio.h>

int main(void)
{
    union uFloat                                                //1
    {
        float fValue;                                           //2
        unsigned int ui4FValue;                                 //3
    };

    union uFloat fMyFloat;                                      //4
    fMyFloat.fValue = -1.1f;                                    //5
    printf ("fMyFloat.fValue  : %+.2f\n", fMyFloat.fValue);     //6
    printf ("fMyFloat.i4FValue: %X\n"   , fMyFloat.ui4FValue);  //7
    fMyFloat.ui4FValue = 0x3FE00000;                            //8
    printf ("fMyFloat.fValue  : %+.2f\n", fMyFloat.fValue);     //9
    printf ("fMyFloat.i4FValue: %X\n"   , fMyFloat.ui4FValue);  //10
    return 0;
}

//P005K4_StructSizesGCC
#include <stdio.h>
int main (void)
{
    struct tTest                                                            
    {
        unsigned char ucByte;                                               
        unsigned int uiNumb;                                                 
    }test2, test3;

    struct tTest test1 = {1, 0x1001u};                                      
    test2.ucByte = 2; test2.uiNumb = 0x1002u;
    test3.ucByte = 3; test3.uiNumb = 0x1003u;


    size_t uiSOTest = sizeof (test1);                                       
    printf ("Variablen der Struktur tTest belegen %i Bytes.", uiSOTest);    
    return 0;
}

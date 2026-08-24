//Auf2K3gcc.c
#include <stdio.h>
int main(void)
{
 /*   
    \textbackslash x81 &                                                & ü (unter DOS)                                    \\\hline
                          \\\hline
\textbackslash x84 &                                                & ä (unter DOS)                                    \\\hline
                         \\\hline
 DOS)                                    \\\hline
\textbackslash xF6 &                                                & ö (unter UNIX und Windos)                                    \\\hline
        & Ä (unter DOS)                                    \\\hline
\textbackslash xC4 &                                                & Ä (unter UNIX und Windos)                                    \\\hline
                      & Ö (unter DOS)                                    \\\hline
\textbackslash xD6 &                                                & Ö (unter UNIX und Windos)                                    \\\hline
                                     & Ü (unter DOS)                                    \\\hline
\textbackslash xDC &                                                & Ü (unter UNIX und Windos)                                    \\\hline
\textbackslash xE1 &                                                & ß (unter DOS)                                    \\\hline
\textbackslash xDF &                                                & ß (unter UNIX und Windos)     
*/
    printf ("\x81\x84\x94\x8E\x99\x9A\xE1");
 printf ("\tflie\xe1t wei\xe1 es Mondlicht\n");       
    return 0;
}

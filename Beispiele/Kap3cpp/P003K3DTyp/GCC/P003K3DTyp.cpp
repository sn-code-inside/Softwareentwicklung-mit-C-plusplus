// P003K3DTyp.cpp

#include <iostream>
using namespace std;
#include <limits.h>                                                             //1
#include <float.h>                                                              //2
int main(void)
{
    cout << "Typ\t\t\tBytes\tMinimalwert\t\tMaximalwert\n";
    cout << "//=== 0. bool =========================================================\n";
    cout << "bool               \t" << sizeof (bool)                << "\t"     //3
         << 0        << "\t\t\t"    << 1                            << "\n";    //4
    cout << "//=== 1. char =========================================================\n";
    cout << "char               \t" << sizeof (char)                << "\t" 
         << CHAR_MIN << "\t\t\t"    << CHAR_MAX                     << "\n";    //5
    cout << "unsigned char      \t" << sizeof (unsigned char)       << "\t" 
         << 0        << "\t\t\t"    << UCHAR_MAX                    << "\n";    //6
    cout << "signed  char       \t" << sizeof (signed char)         << "\t" 
         << SCHAR_MIN<< "\t\t\t"    << SCHAR_MAX                    << "\n";     
    cout << "//=== 2. int ==========================================================\n";
    cout << "int                \t" << sizeof (int)                 << "\t" 
         << INT_MIN  << "\t\t"      << INT_MAX                      << "\n"; 
    cout << "unsigned int       \t" << sizeof (unsigned int)        << "\t" 
         << 0        << "\t\t\t"    << UINT_MAX                     << "\n";   
    cout << "signed int         \t" << sizeof (signed int)          << "\t" 
         << INT_MIN  << "\t\t"      << INT_MAX                      << "\n";   
    cout << "short int          \t" << sizeof (short int)           << "\t" 
         << SHRT_MIN << "\t\t\t"    << SHRT_MAX                     << "\n";  
    cout << "unsigned short int \t" << sizeof (unsigned short int)  << "\t" 
         << 0        << "\t\t\t"    << USHRT_MAX                    << "\n";   
    cout << "signed short int   \t" << sizeof (signed short int)    << "\t" 
         << SHRT_MIN << "\t\t\t"    << SHRT_MAX                     << "\n"; 
    cout << "long int         \t"   << sizeof (long int)            << "\t" 
         << LONG_MIN << "\t\t"      << LONG_MAX                     << "\n"; 
    cout << "unsigned long int  \t" << sizeof (unsigned long int)   << "\t" 
         << 0        << "\t\t\t"    << ULONG_MAX                    << "\n"; 
    cout << "signed long int    \t" << sizeof (signed long int)     << "\t" 
         << LONG_MIN << "\t\t"      << LONG_MAX                     << "\n"; 
    cout << "long long          \t" << sizeof (__int64)    << "\t" 
         << LLONG_MIN<< "\t"        << LLONG_MAX                    << "\n"; 
    cout << "unsigned long long \t" << sizeof (unsigned long long)  << "\t" 
         << 0        << "\t\t\t"    << ULLONG_MAX                   << "\n"; 
    cout << "//=== 3. float ========================================================\n";
    cout << "float              \t" << sizeof (float)               << "\t" 
         << FLT_MIN  << "\t\t"      << FLT_MAX                      << "\n"; 
    cout << "//=== 4. double =======================================================\n";
    cout << "double             \t" << sizeof (double)              << "\t" 
         << DBL_MIN  << "\t\t"      << DBL_MAX                      << "\n"; 
    cout << "long double        \t" << sizeof (long double)         << "\t"     //6
         << LDBL_MIN << "\t\t"      << LDBL_MAX                     << "\n"; 
    return 0;
}

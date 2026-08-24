// P009KD_Concepts.cpp
//
#include <Windows.h>
#include <iostream>
#include <concepts>
#include <string>
using namespace std;
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}

template <typename T> concept SummableAndPrintable = requires(T a, T b)             //1
{
    { a + b } -> convertible_to<T>;                                                 //2
    cout << a;                      
} && (integral<T> || floating_point<T> || same_as <T, string>) 
  && !same_as<T, bool> &&!same_as<T, char>;
template <SummableAndPrintable T> T addAndPrint(T a, T b)                           //3
{
    T result = a + b;
    cout << "Ergebnis: " << result << endl;
    return result;
}

int main(void) {
    //=========================================
    LPCTSTR str = L"P009KD_Concepts";
    printConsole(str);
    //=========================================
    addAndPrint(10, 20);                                                            //4
    addAndPrint(1.2f, 1.7f);
    addAndPrint(string("Hello "), string("C++20"));
    //addAndPrint('A', '!');  C2672 "addAndPrint": keine überladene Funktion gefunden
    //addAndPrint(true, false);   
    addAndPrint(string("A"), string("!"));

    return 0;
}
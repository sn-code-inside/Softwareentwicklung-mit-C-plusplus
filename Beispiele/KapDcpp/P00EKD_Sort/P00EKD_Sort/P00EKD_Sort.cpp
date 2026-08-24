// P00EKD_Sort.cpp 
#include <Windows.h>
#include <iostream>
#include <algorithm>
using namespace std;
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
int main() {
    //=========================================
    LPCTSTR str = L"P00EKD_Sort";
    printConsole(str);
    //=========================================
    int zahlen[] = { 5, 2, 8, 1, 9 };
    int n = 5;
    cout << "Vor dem Sortieren.\n";
    for (int i = 0; i < n; i++) {
        cout << zahlen[i] << " ";
    }

    sort(begin (zahlen), end (zahlen));

    cout << "\nNach dem Sortieren.\n";
    for (int i = 0; i < n; i++) {
        cout << zahlen[i] << " ";
    }
    return 0;
}
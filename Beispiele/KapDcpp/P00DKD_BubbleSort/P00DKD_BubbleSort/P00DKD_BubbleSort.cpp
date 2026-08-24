// P00DKD_BubbleSort.cpp 
#include <Windows.h>
#include <iostream>
using namespace std;
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
int main(void) {
    //=========================================
    LPCTSTR str = L"P00DKD_BubbleSort";
    printConsole(str);
    //=========================================
    int zahlen[] = { 5, 2, 8, 1, 9 };
    int n = 5;
    cout << "Vor dem Sortieren.\n";
    for (int i = 0; i < n; i++) {
        cout << zahlen[i] << " ";
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (zahlen[j] > zahlen[j + 1]) {
                int temp = zahlen[j];
                zahlen[j] = zahlen[j + 1];
                zahlen[j + 1] = temp;
            }
        }
    }
    cout << "\nNach dem Sortieren.\n";
    for (int i = 0; i < n; i++) {
        cout << zahlen[i] << " ";
    }

    return 0;
}
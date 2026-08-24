// P007KD_RangeFilter.cpp
#include <Windows.h>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
int main() {
    //=========================================
    LPCTSTR str = L"P007KD_RangeFilter";
    printConsole(str);
    //=========================================
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8 };

    auto results = numbers | views::filter   ([](int n) { return n % 2 != 0; })     //1
                           | views::transform([](int n) { return n * (2 + 1); });   //2

    for (int x : numbers)                                                           //3
        cout << x << " ";
    cout << endl;

    for (auto v : results)                                                          //4      
        cout << v << " ";        
    cout << endl;

    size_t uiS = numbers.size();                                                    //5 
    for (int i = 0; i < uiS; i++)
        cout << numbers[i] << " ";

    return 0;
}
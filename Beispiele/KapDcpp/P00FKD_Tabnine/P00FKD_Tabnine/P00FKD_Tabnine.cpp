// P00FKD_Tabnine.cpp 
//

#include <iostream>
using namespace std;
void xSwap(int& x, int& y);

void bubbleSort(int* iArr, int iLen)
{
    for (int i = 0; i < iLen; i++)
        cout << iArr[i] << "; ";
    cout << endl;
    cout << endl;
    for (int i = 0; i < iLen-1; i++)
    {
        for (int j = 0; j < iLen-i-1; j++)
        {
            if (iArr[j] > iArr[j + 1])
            {
                xSwap(iArr[j], iArr[j + 1]);
                for (int i = 0; i < iLen; i++)
                    cout << iArr[i] << "; ";
                cout << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < iLen; i++)
        cout << iArr[i] << "; ";
}

void xSwap(int& x, int& y)
{
    int iTemp = x;
    x = y;
    y = iTemp;
}
template <typename T> void tSwap(T& x, T& y)
{
    T tTemp = x;
    x = y;
    y = tTemp;
}

bool isGreater(int x, int y)
{
    return x > y ? true : false;
}
int main(void)
{
    cout << "Test TabNine\n";

    int zahlen[] = { 5, 2, 8, 9, 1 };
    int n = 5;
    bubbleSort(zahlen, (int)(end (zahlen)-begin (zahlen)));

    bool bIs = isGreater(6, 5);

    int iX = 6; int iY = 7;
    xSwap(iX, iY);

    string s1("ABC");
    string s2("DEF");
    tSwap(s1, s2);

    char str[16] = "25";
    int iRes = atoi(str);
    
    char str1[16];
    _itoa_s (iRes, str1, 16, 10);

    return 0;
}



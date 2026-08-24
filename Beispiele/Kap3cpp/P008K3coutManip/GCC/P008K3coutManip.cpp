// P008K3coutManip.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	setw (30);
    setfill (0x21);
    setiosflags (ios::right);
    cout << "Das ist ein Text\n";
    return 0;
}


// P00CKD_SpaceShipOpWO.cpp 
#include <Windows.h>
#include <iostream>
#include <compare>
#include <string>
//#include <cmath>
using namespace std;

// 1. strong_ordering: Ganze Zahlen sind strikt identisch, wenn sie gleich sind.
struct tNumb {
    int iValue;
    strong_ordering operator<=>(const tNumb& other) const
    {
        strong_ordering numbRes = iValue <=> other.iValue;
        return numbRes;
    }; 
};

// 2. weak_ordering: Vergleich von Strings ohne Beachtung der Groß-/Kleinschreibung.
struct tCmpStr 
{
    string s;
    weak_ordering operator<=>(const tCmpStr& other) const
    {
        for (size_t i = 0; i < min(s.size(), other.s.size()); ++i) 
        {
            char c1 = toupper(static_cast<unsigned char>(s[i]));
            char c2 = toupper(static_cast<unsigned char>(other.s[i]));
            if (c1 != c2) 
                return c1 <=> c2;
        }
        return s.size() <=> other.s.size();
    }
};

// 3. partial_ordering: Punkt im 2D-Raum. 
// Ein Punkt (1,1) ist weder größer noch kleiner als (0,2), sie sind unvergleichbar.
struct Point {
    double x, y;
    partial_ordering operator<=>(const Point& other) const {
        if (x == other.x && y == other.y) return partial_ordering::equivalent;
        if (x < other.x && y < other.y)   return partial_ordering::less;
        if (x > other.x && y > other.y)   return partial_ordering::greater;
        return partial_ordering::unordered; // Nicht vergleichbar
    }
};
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
int main() 
{
    //=========================================
    LPCTSTR str = L"P00CKD_SpaceShipOpWO";
    printConsole(str);
    //=========================================
    // Strong
    tNumb numb1{ 10 }, numb2{ 10 };
    strong_ordering numbRes = numb1 <=> numb2;
    if (numbRes == strong_ordering::equal)
        cout << "Strong: numb1 (10) und numb2 (10) sind absolut identisch (equal).\n";

    // Weak
    tCmpStr s1{ "ABC" }, s2{ "abc" };
    weak_ordering sRes = s1 <=> s2;
    if (sRes == weak_ordering::equivalent)
        cout << "Weak  : s1 (''ABC'') und s2 (''abc'') sind aequivalent(equivalent).\n";

    /*
    // Partial
    Point p1{ 1.0, 1.0 }, p2{ 0.0, 2.0 };
    auto res = (p1 <=> p2);
    if (res == partial_ordering::unordered)
        cout << "Partial: Punkte (1,1) und (0,2) sind nicht vergleichbar.\n";
    */

    return 0;
}



















/*
#include <iostream>
#include <string>
#include <compare>
//#include <algorithm>
//#include <cctype>
using namespace std;

struct CaseInsensitiveString 
{
    string data;

    // Operator <=> für schwache Ordnung implementieren
    weak_ordering operator<=>(const CaseInsensitiveString& other) const 
    {
        for (size_t i = 0; i < min(data.size(), other.data.size()); ++i) 
        {
            char c1 = tolower(data[i]);
            char c2 = tolower(other.data[i]);
            if (c1 < c2) return weak_ordering::less;
            if (c1 > c2) return weak_ordering::greater;
        }

        // Wenn alle bisherigen Zeichen gleich sind, entschetNumbet die Länge
        if (data.size() < other.data.size()) return weak_ordering::less;
        if (data.size() > other.data.size()) return weak_ordering::greater;

        // "abc" und "ABC" landen hier, sind äquivalent
        return weak_ordering::equivalent;
    }

    // Für == muss man bei weak_ordering oft explizit equivalent nutzen
    bool operator==(const CaseInsensitiveString& other) const 
    {
        return (*this <=> other) == weak_ordering::equivalent;
    }
};

int main(votNumb) 
{
    CaseInsensitiveString s1{ "abc" };
    CaseInsensitiveString s2{ "ABC" };
    CaseInsensitiveString s3{ "def" };

    string s_1("abc");
    string s_2("ABC");
    string s_3("def");

    weak_ordering c = s_1 <=> s_2;
    c = s_2 <=> s_3;
    cout << boolalpha;
    
    cout << "abc < def: " << (s1 < s3) << "\n";   // true
    cout << "abc == ABC: " << (s1 == s2) << "\n"; // true

    return 0;
}
*/
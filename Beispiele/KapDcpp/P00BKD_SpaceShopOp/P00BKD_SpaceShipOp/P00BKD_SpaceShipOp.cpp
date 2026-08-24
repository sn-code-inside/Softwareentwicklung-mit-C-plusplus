// P00BKD_SpaceShipOp.cpp 
#include <Windows.h>
#include <compare>          // Notwendig für den <=> Operator
#include <iostream>
#include <set>
using namespace std;



template <typename T> partial_ordering cmpNumb(T a, T b)
{
    partial_ordering result;
    try
    {
        //if (b == 13)
        //    result = (a <=> b / 0);
        //else
            result = (a <=> b);
    }
    catch (...)
    {
        int i = 0;
    }
    return result;
}

struct Point {
    int x; 
    int y;

    // Generiert automatisch <, <=, >, >=, == und !=
    //auto operator<=>(const Point&) const = default;

    
    std::strong_ordering operator<=>(const Point& other) const 
    {
        if (auto cmp = x <=> other.x; cmp != 0) return cmp;
        return y <=> other.y;
    }
    

    // Für die Gleichheit nutzen wir die Standard-Implementierung
    bool operator==(const Point& other) const = default;
};

void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
int main() 
{
    //=========================================
    LPCTSTR str = L"P00BKD_SpaceShipOp";
    printConsole(str);
    //=========================================
    int a = 10;
    int b = 11;
    partial_ordering c = cmpNumb(a, b);
    if (c._Value == -1)
        cout << "a: " << a << "; b: " << b << "; (a <=> b): a less b    (-1); a<b " << endl;

    a = b; c = cmpNumb(a, b);
    if (c._Value == 0)
        cout << "a: " << a << "; b: " << b << "; (a <=> b): a equal b   (0) ; a==b" << endl;

    a = b + 1; c = cmpNumb(a, b);
    if (c._Value ==1)
        cout << "a: " << a << "; b: " << b << "; (a <=> b): a greater b (1) ; a>b " << endl;

//    b = 13; c = cmpNumb(a, b);
//    if (c > 0)
//        cout << "a: " << a << "; b: " << b << "; (a <=> b): a greater b (1); a>b " << endl;

    /*


    if (result < 0) {
        std::cout << "a ist kleiner als b" << std::endl;
    }
    else if (result == 0) {
        std::cout << "a ist gleich b" << std::endl;
    }
    else {
        std::cout << "a ist groesser als b" << std::endl;
    }
    if (result != 0)
        std::cout << "a und b sind ungleich" << std::endl;
    if (result == 0)
        std::cout << "a und b sind gleich" << std::endl;


    int iSize = sizeof(Point);
    Point p1{ 2, 5 }, p2{ 1, 10 };

    std::set<Point> points = { {10, 20}, {5, 30}, {10, 5}, {5, 30} };
    for (const auto& p : points) {
        std::cout << "P(" << p.x << ", " << p.y << ")" << std::endl;
    }

    if (p1 < p2) std::cout <<  "1. p1 ist kleiner als p2\n";
    if (p1 <= p2) std::cout << "2. p1 ist kleiner gleich p2\n";
    if (p1 > p2) std::cout <<  "3. p1 ist groesser als p2\n";
    if (p1 >= p2) std::cout << "4. p1 ist groesser gleich p2\n";
    if (p1 == p2) std::cout << "5. p1 ist gleich p2\n";
    if (p1 != p2) std::cout << "6. p1 ist nicht gleich p2\n";
    */
    
    return 0;
}
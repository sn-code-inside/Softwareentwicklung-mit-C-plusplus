// P009KB_vector_VS19.cpp
#include <iostream>
using namespace std;
#include <vector>                                                                          
#include <algorithm>                                                            
#include <random>                                                               //1
//=============================================
#include <Windows.h>                                
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//=============================================
#define MAX_NUMB  10                                                                               
int main(void)
{
    //=========================================
    {
        LPCTSTR str = L"P009KB_vector_VS19";
        printConsole(str);
    }
    //=========================================
    vector <int>::iterator itForw;
    vector <int> vecInt(MAX_NUMB);

    random_device rand;                                                         //2 Hardware-Zufallsgenerator erzeugen
    mt19937 gener(rand());                                                      //3 Generator mit Seed von rand() initialisieren
    uniform_int_distribution<> dist(0, RAND_MAX);                               //4 Grenzen definieren
    for (unsigned int i = 0; i < vecInt.size(); i++)                            //5
    {
        vecInt[i] = gener();                                                    //6
        vecInt[i] = dist(gener);                                                //7
    }
    cout << "Ausgabe der Zufallszahlen:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)              //10
    {
        cout << *itForw << "\t";                                                //11
    }
    sort(vecInt.begin(), vecInt.end());                                         //12
    cout << "\n\nAusgabe der Zufallszahlen in sortierter Reihenfolge:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    vecInt.pop_back();                                                          //13
    vecInt.push_back(1);                                                        //14
    vecInt.insert(vecInt.begin(), 999999);                                      //15
    cout << "\n\nAusgabe der Zufallszahlen nach Einfuegen bei Begin und Ende:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    sort(vecInt.begin(), vecInt.end());
    cout << "\n\nAusgabe der Zufallszahlen nochmals sortiert:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    reverse(vecInt.begin(), vecInt.end());                                      //16
    cout << "\n\nAusgabe der Zufallszahlen in umgekehrter Reihenfolge:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    return 0;
}

/*
#include <iostream>
#include <random> // Header für Zufallszahlen

int main() {
    // 1. Seed erzeugen (nicht-deterministisch)
    std::random_device rd;

    // 2. Generator initialisieren (Mersenne Twister)
    std::mt19937 gen(rd());

    // 3. Verteilung definieren (Ganzzahlen zwischen 1 und 100)
    std::uniform_int_distribution<> distrib(1, 100);

    // Zufallszahl generieren
    for(int i=0; i<5; ++i) {
        std::cout << distrib(gen) << " ";
    }

    return 0;
}
*/

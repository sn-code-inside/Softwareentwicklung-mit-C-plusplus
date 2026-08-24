// P0B_2K7_Mutex.cpp

#include <iostream>
#include <windows.h>
#include <string>
#include <chrono>
#include <thread>

int main(void) 
{
    // 1. Definiere einen eindeutigen Namen für den Mutex
    std::wstring mutexName = L"Global\\MeinProzessMutex";

    // 2. Erstelle oder öffne den benannten Mutex
    HANDLE hMutex = CreateMutex(
        NULL,               // Standard-Sicherheitsattribute
        FALSE,              // Nicht sofort in Besitz nehmen
        mutexName.c_str()   // Eindeutiger Name
    );

    if (hMutex == NULL) {
        std::cerr << "Mutex konnte nicht erstellt werden: " << GetLastError() << std::endl;
        return 1;
    }

    std::cout << "Prozess wartet auf Mutex..." << std::endl;

    // 3. Warten auf den Mutex (Lock)
    DWORD dwWaitResult = WaitForSingleObject(
        hMutex,    // Handle zum Mutex
        INFINITE   // Unendlich lange warten
    );

    if (dwWaitResult == WAIT_OBJECT_0) {
        // --- KRITISCHER BEREICH START ---
        std::cout << "Mutex erhalten. Kritischer Bereich wird betreten." << std::endl;
        std::cout << "Arbeite 15 Sekunden..." << std::endl;

        // Simuliert Arbeit, in der der andere Prozess warten muss
        std::this_thread::sleep_for(std::chrono::seconds(15));

        std::cout << "Kritischer Bereich wird verlassen." << std::endl;
        // --- KRITISCHER BEREICH ENDE ---

        // 4. Mutex freigeben (Unlock)
        if (!ReleaseMutex(hMutex)) {
            std::cerr << "Mutex konnte nicht freigegeben werden." << std::endl;
        }
    }
    else {
        std::cerr << "Fehler beim Warten auf den Mutex." << std::endl;
    }

    // 5. Handle schließen
    CloseHandle(hMutex);
    std::cout << "Programm beendet." << std::endl;

    return 0;
}

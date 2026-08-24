// P00AKD_Concepts.cpp
#include <iostream>
#include <concepts>
#include <vector>

// Version 1: Für integrale Typen (int, long, etc.)
void process(std::integral auto value) {
    std::cout << "Ganzzahl-Verarbeitung: " << value << "\n";
}

// Version 2: Für Gleitkommazahlen (float, double)
void process(std::floating_point auto value) {
    std::cout << "Fließkomma-Verarbeitung: " << value << "\n";
}

// Version 3: Für alles, was ein Container ist (hat begin() und end())
template <typename T>
concept Container = requires(T & c) {
    c.begin();
    c.end();
};

void process(Container auto const& c) {
    std::cout << "Container-Verarbeitung (Elemente): ";
    for (const auto& item : c) std::cout << item << " ";
    std::cout << "\n";
}

int main() {
    process(10);           // Ruft Version 1 auf
    process(3.1415);       // Ruft Version 2 auf

    std::vector<int> v = { 1, 2, 3 };
    process(v);            // Ruft Version 3 auf

    process("Hallo");   // FEHLER: Erfüllt keines der Konzepte eindeutig
}
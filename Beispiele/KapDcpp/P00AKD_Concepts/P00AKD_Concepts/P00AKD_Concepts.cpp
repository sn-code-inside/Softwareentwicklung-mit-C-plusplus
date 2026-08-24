// P00AKD_Concepts.cpp
#include <iostream>
#include <concepts>
#include <string>

// 1. Definition des Concepts
template <typename T>
concept PrintableNumber = requires(T a, T b) 
{
    // Compound Requirement: a + b muss existieren und den Typ T ergeben
    { a + b } -> std::same_as<T>;

    // Simple Requirement: Die Ausgabe auf cout muss möglich sein
    std::cout << a;

} && (std::integral<T> || std::floating_point<T>) && !std::same_as<T, bool>;

// 2. Anwendung mit der requires-Klausel
template <typename T>  requires PrintableNumber<T>
void add_and_print(T a, T b) {
    std::cout << "Ergebnis: " << (a + b) << std::endl;
}

int main() {
    add_and_print(10, 20);          // OK: int
    add_and_print(5.5, 2.3);        // OK: double

    // add_and_print(true, false);  // FEHLER: bool wird durch !same_as<T, bool> abgelehnt
    // add_and_print("a", "b");     // FEHLER: const char* erfüllt integral/floating_point nicht

    return 0;
}
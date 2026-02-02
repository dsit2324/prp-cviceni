#include <iostream>
#include <limits>
#include "Datum.h"

int main() {
    Datum d1;
    Datum d2(1, 1, 2000);
    Datum d3(d2);
    std::cout << "Objekt vytvoreny vychozim konstruktorem d1: " << d1 << std::endl;
    std::cout << "Objekt vytvoreny vychozim konstruktorem d2: " << d2 << std::endl;
    std::cout << "Objekt vytvoreny vychozim konstruktorem d3: " << d3 << std::endl;
    std::cout << "Zadani noveho data" << std::endl;
    int den;
    int mesic;
    int rok;
    do {
        std::cout << "Zadej den:" << std::endl;
        std::cin >> den;
        std::cout << "Zadej mesic:" << std::endl;
        std::cin >> mesic;
        std::cout << "Zadej rok:" << std::endl;
        std::cin >> rok;
        Datum d1(den, mesic, rok);
        if (!d1.setDatum(den, mesic, rok) || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Nebylo zadano platne datum, zadej znovu:" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!d1.setDatum(den, mesic, rok));
    std::cout << "Objekt d1 po zmene: " << d1 << std::endl;
    return 0;
}

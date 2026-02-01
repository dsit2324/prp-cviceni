#include <iostream>
#include "Datum.h"


int main() {
    Datum d1;
    Datum d2(1, 1, 2000);
    Datum d3(d2);
    std::cout << "Objekt vytvoreny vychozim konstruktorem d1" << d1 << std::endl;
    return 0;
}

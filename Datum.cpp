//
// Created by dsofc on 01.02.2026.
//

#include "Datum.h"
#include <ctime>

Datum::Datum() {
    systemoveDatum();
}

Datum::Datum(int den, int mesic, int rok) {
    if (!setDatum(den, mesic, rok)) {
        systemoveDatum();
    }
}

Datum::Datum(const Datum &kopirka) : den(kopirka.getDen()), mesic(kopirka.getMesic()), rok(kopirka.getRok()) {
}

Datum::~Datum() {
}

int Datum::getDen() const {
    return this->den;
}

int Datum::getMesic() const {
    return this->mesic;
}

int Datum::getRok() const {
    return this->rok;
}

bool Datum::setDen(int den) {
    if (den < 1 || den > pocetDniVmesic(mesic, rok)) {
        return false;
    } else {
        this->den = den;
        return true;
    }
}

bool Datum::setMesic(int mesic) {
    if (mesic >= 1 && mesic <= 12) {
        this->mesic = mesic;
        return true;
    } else {
        return false;
    }
}

bool Datum::setRok(int rok) {
    if (rok >= MINROK && rok <= MAXROK) {
        this->rok = rok;
        return true;
    } else {
        return false;
    }
}

bool Datum::setDatum(int den, int mesic, int rok) {
    if (platnostData(den, mesic, rok)) {
        this->den = den;
        this->mesic = mesic;
        this->rok = rok;
        return true;
    } else {
        return false;
    }
}

void Datum::systemoveDatum() {
    time_t t = time(nullptr);
    tm *now = localtime(&t);

    den = now->tm_mday;
    mesic = now->tm_mon + 1;
    rok = now->tm_year + 1900;
}

bool Datum::platnostData(int den, int mesic, int rok) const {
    if ((rok >= MINROK && rok <= MAXROK) && (mesic >= 1 && mesic <= 12) && (
            den >= 1 && den <= pocetDniVmesic(mesic, rok))) {
        return true;
    } else {
        return false;
    }
}

bool Datum::prestupnyRok(int rok) const {
    if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
        return true;
    }
    return false;
}

int Datum::pocetDniVmesic(int mesic, int rok) const {
    if (mesic == 2 && prestupnyRok(rok)) {
        return 29;
    } else if (mesic == 2 && !prestupnyRok(rok)) {
        return 28;
    } else if (mesic == 4 || mesic == 6 || mesic == 9 || mesic == 11) {
        return 30;
    } else {
        return 31;
    }
}

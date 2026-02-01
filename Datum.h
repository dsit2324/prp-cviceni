//
// Created by dsofc on 01.02.2026.
//

#ifndef PRP_PISEMKA_DATUM_H
#define PRP_PISEMKA_DATUM_H

#define MINROK 1970
#define MAXROK 2050
#include <iosfwd>
#include <ostream>

class Datum {
public:
    Datum();
    Datum(int den, int mesic, int rok);
    Datum(const Datum& kopirka);
    ~Datum();
    int getDen() const;
    int getMesic() const;
    int getRok() const;
    bool setDen(int den);
    bool setMesic(int mesic);
    bool setRok(int rok);
    bool setDatum(int den, int mesic, int rok);
private:
    void systemoveDatum();
    bool platnostData(int den, int mesic, int rok) const;
    bool prestupnyRok(int rok) const;
    int pocetDniVmesic(int mesic, int rok) const;
    int den;
    int mesic;
    int rok;

};

std::ostream &operator<<(std::ostream &, const Datum &);

#endif //PRP_PISEMKA_DATUM_H
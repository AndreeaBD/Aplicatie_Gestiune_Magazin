#ifndef MAGAZIN_H
#define MAGAZIN_H

#include<string>
#include "Produs.h"

typedef Produs* LocatieProdus;

class Magazin {
private:
    LocatieProdus* locatii;
    int numarDeProduse = 0;
    int stocProduse = 0;
public:
    Magazin(int nrProduse);
    virtual ~Magazin();

    void operator << (const Produs &produs);
    void adaugaProdus();
    void eliminaProdus();
    void cautaProdus();
    void numaraMasiniDeSpalat();
    void scrieProduse();
    void listeazaInformatiiProdus(Produs*);
};

#endif // MAGAZIN_H

#ifndef MASINADESPALAT_H
#define MASINADESPALAT_H

#include <string>
#include "Produs.h"

class MasinaDeSpalat : public Produs {
private:
    int rotatiiPeMinut;
    string clasaEnergetica;
public:
    MasinaDeSpalat(int id, string nume, double pret, int numarDeRotatii, string clasaEnergetica);
    int getRotatiiPeMinut();
    string getClasaEnergetica();
    void setRotatiiPeMinut(int numarDeRotatii);
    void setClasaEnergetica(string clasaEnergetica);
};

#endif // MASINADESPALAT_H

#include "MasinaDeSpalat.h"

MasinaDeSpalat::MasinaDeSpalat(int id, string nume, double pret, int numarDeRotatii, string clasaEnergetica) : Produs(id, nume, pret) {
    this -> rotatiiPeMinut = numarDeRotatii;
    this -> clasaEnergetica = clasaEnergetica;
}

int MasinaDeSpalat::getRotatiiPeMinut() {
    return rotatiiPeMinut;
}

string MasinaDeSpalat::getClasaEnergetica() {
    return clasaEnergetica;
}

void MasinaDeSpalat::setRotatiiPeMinut(int rotatiiPeMinut) {
    this -> rotatiiPeMinut = rotatiiPeMinut;
}

void MasinaDeSpalat::setClasaEnergetica(string clasaEnergetica) {
    this -> clasaEnergetica = clasaEnergetica;
}

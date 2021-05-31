#include "Produs.h"

Produs::Produs(int id, string nume, double pret) : id(id), nume(nume), pret(pret) {}

Produs::~Produs() {}

int Produs::getId() {
    return id;
}

string Produs::getNume() {
    return nume;
}

double Produs::getPret() {
    return pret;
}

void Produs::setId(int id) {
    this->id = id;
}

void Produs::setNume(string nume) {
    this->nume = nume;
}

void Produs::setPret(double pret) {
    this->pret = pret;
}

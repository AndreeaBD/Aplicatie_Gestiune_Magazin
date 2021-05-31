#include "Frigider.h"

Frigider::Frigider(int id, string nume, double pret, int volum, bool areCongelator) : Produs(id, nume, pret) {
    this -> volum = volum;
    this -> areCongelator = areCongelator;
}

int Frigider::getVolum() {
    return volum;
}

bool Frigider::getCongelator() {
    return areCongelator;
}

void Frigider::setVolum(int volum) {
    this -> volum = volum;
}

void Frigider::setCongelator(bool stareCongelator) {
    this -> areCongelator = stareCongelator;
}

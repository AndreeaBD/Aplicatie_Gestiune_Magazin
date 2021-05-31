#ifndef FRIGIDER_H
#define FRIGIDER_H

#include <string>
#include "Produs.h"

using namespace std;

class Frigider : public Produs {
private:
    int volum;
    bool areCongelator;
public:
    Frigider(int id, string nume, double pret, int volum, bool areCongelator);
    int getVolum();
    bool getCongelator();
    void setVolum(int volum);
    void setCongelator(bool stare);
};

#endif // FRIGIDER

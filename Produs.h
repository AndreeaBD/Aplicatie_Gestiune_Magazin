#ifndef PRODUS_H
#define PRODUS_H

#include <string>
using namespace std;

class Produs {
protected:
    int id;
    string nume;
    double pret;
public:
    Produs(int id, string nume, double pret);
    virtual ~Produs();

    int getId();
    string getNume();
    double getPret();

    void setId(int);
    void setNume(string);
    void setPret(double);
};

#endif//PRODUS_H

#include "Magazin.h"
#include "Produs.h"
#include "MasinaDeSpalat.h"
#include "Frigider.h"
#include "Exceptii.h"

#include <iostream>
#include <string>
using namespace std;

Magazin::Magazin(int nrProduse) {
    this -> locatii = new LocatieProdus[nrProduse];

    for(int i = 0; i < nrProduse; i++) {
        locatii[i] = NULL;
        numarDeProduse++;
    }
}

Magazin::~Magazin() {
    delete [] locatii;
}

ostream& operator << (ostream& out, Produs *produs) {
    MasinaDeSpalat* masina = dynamic_cast<MasinaDeSpalat*>(produs);
    Frigider* frigider = dynamic_cast<Frigider*>(produs);

    if(masina) {

        out << "Masina de spalat cu " << masina->getRotatiiPeMinut() << " rotatii pe minut si clasa energetica " << masina->getClasaEnergetica()
             << " are id-ul " << produs->getId() << ", numele " << produs->getNume() << " si pretul " << produs->getPret() << ".\n";
    }

    else if(frigider) {

        out << "Frigider cu volumul " << frigider->getVolum() << " si ";
        if(frigider->getCongelator()) {
            out << "are congelator.";
        } else {
            out << "nu are congelator.";
        }
        out << "Id-ul este " << produs->getId() << ", numele " << produs->getNume() << " si pretul " << produs->getPret() << ".\n";
    }

    return out;
}

void Magazin::adaugaProdus() {

    if(stocProduse == numarDeProduse) {throw MagazinPlinException();}

    char optiune;

    cout << "Ce produs doriti sa introduceti?\n";
    cout << "M - Masina de spalat;\n";
    cout << "F - Frigider.\n";

    cin >> optiune;
    if(optiune != 'M' && optiune != 'F'){throw optiuneInvalidaException();}

    int id;
    cout << "Introduceti id-ul produsului:\n";
    cin >> id;

    string nume;
    cout << "Introduceti numele produsului:\n";
    cin >> nume;

    double pret;
    cout << "Introduceti pretul produsului:\n";
    cin >> pret;

    MasinaDeSpalat* masina;
    Frigider* frigider;

    if (optiune == 'M') {
        int rotatii;
        string clasa;

        cout << "Introduceti numarul de rotatii pe minut.\n";
        cin >> rotatii;
        cout << "Introduceti clasa energetica.\n";
        cin >> clasa;

        masina = new MasinaDeSpalat(id, nume, pret, rotatii, clasa);
    } else if (optiune == 'F'){
        int volum;
        string optiuneCongelator;
        bool congelator;

        cout << "Introduceti volumul frigiderului:\n";
        cin >> volum;
        cout << "Introduceti daca frigiderul are sau nu congelator (DA/NU):\n";

        cin >> optiuneCongelator;

        if (optiuneCongelator == "DA") {
            congelator = true;
        } else {
            congelator = false;
        }

        frigider = new Frigider(id, nume, pret, volum, congelator);

    }

    for(int i = 0; i < numarDeProduse; i++) {
        if(locatii[i] == NULL) {
            if(optiune == 'M') {
                locatii[i] = masina;
                stocProduse++;
                return;
            } else {
                locatii[i] = frigider;
                stocProduse++;
                return;
            }
        }
    }

}

void Magazin::eliminaProdus() {
    int idProdus;
    cout << "Introduceti id-ul produsului pe care doriti sa il eliminati:\n";
    cin >> idProdus;
    bool produsEliminat = false;

    for(int i = 0; i < numarDeProduse; i++) {
        if(locatii[i] != NULL && locatii[i]->getId() == idProdus) {
            locatii[i] = NULL;
            produsEliminat = true;
            stocProduse--;
            return;
        }
    }

    if(produsEliminat == false) throw ProdusInexistentException();
}

void Magazin::cautaProdus() {
    int id;
    cout << "Introduceti id-ul produsului pe care il cautati:\n";
    cin >> id;
    bool produsGasit = false;

    for(int i = 0; i < numarDeProduse; i++) {
        if(locatii[i] != NULL && locatii[i]->getId() == id) {
            cout << "Produsul se afla in magazin pe pozitia " << (i + 1) << ".\n";
            listeazaInformatiiProdus(locatii[i]);
            produsGasit = true;
            return;
        }
    }

    if(produsGasit == false) throw ProdusInexistentException();
}

void Magazin::numaraMasiniDeSpalat() {
    int numarMasiniDeSpalat = 0;
    for(int i = 0; i < numarDeProduse; i++) {
        if(locatii[i] != NULL) {
            MasinaDeSpalat* masina = dynamic_cast<MasinaDeSpalat*>(locatii[i]);

            if(masina) {
                numarMasiniDeSpalat++;
            }
        }
    }

    cout << "In magazin se afla " << numarMasiniDeSpalat << " masini de spalat.";
}

void Magazin::listeazaInformatiiProdus(Produs *produs) {
    cout << produs;
}

void Magazin::scrieProduse() {
    for(int i = 0; i < numarDeProduse; i++) {
        if(locatii[i] != NULL) {
            listeazaInformatiiProdus(locatii[i]);
        }
    }
}

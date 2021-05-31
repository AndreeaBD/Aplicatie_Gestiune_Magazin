#include <iostream>
#include <string>
#include "produs.h"
#include "Frigider.h"
#include "MasinaDeSpalat.h"
#include "Magazin.h"
#include "Exceptii.h"

using namespace std;

void Meniu()
{
    cout << "\nIntroduceti operatia pe care vreti sa o efectuati: \n";
    cout << " A - Adauga produs in magazin;\n";
    cout << " L - Listare produse din magazin;\n";
    cout << " E - Elimina produs din magazin;\n";
    cout << " C - Cauta produs in magazin;\n";
    cout << " N - Afiseaza numarul masinilor de spalat din magazin;\n";
    cout << " Q - Inchidere meniu.\n";
}

int main()
{
    int capacitate;
    cout << "Introduceti capacitatea de stocare a magazinului.\n";
    cin >> capacitate;


    Magazin magazin(capacitate);

    char op;

        do
        {
            try {
            Meniu();
            cin >> op;

            switch(op)
            {
            case 'A':
                cout << "Adauga produs: \n";
                magazin.adaugaProdus();
                cout << "\n";
                break;
            case 'L':
                cout << "Listare produse: \n";
                magazin.scrieProduse();
                cout << "\n";
                break;
            case 'E':
                cout << "Elimina produs: \n";
                magazin.eliminaProdus();
                cout << "\n";
                break;
            case 'C':
                cout << "Cauta produs: \n";
                magazin.cautaProdus();
                cout << "\n";
                break;
            case 'N':
                cout << "Afiseaza numarul masinilor de spalat: \n";
                magazin.numaraMasiniDeSpalat();
                cout << "\n";
                break;
            case 'Q':
                cout << "La revedere!\n";
                cout << "\n";
                break;
            default:
                cout << "Operatie invalida!\n";
                cout << "\n";
                break;
            }
        } catch (MagazinPlinException exceptie) {
            cout << "Magazinul este plin!\n";
        } catch (ProdusInexistentException exceptie) {
            cout << "Produsul nu exista in magazin.\n";
        } catch (optiuneInvalidaException exceptie) {
            cout << "Optiunea nu este valida.\n";
        }

    } while(op != 'Q');


    return 0;
}

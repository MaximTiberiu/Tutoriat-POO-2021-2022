#include "Meniu.h"

void aplicatie() {
    int option = 0;
    Meniu *meniu = Meniu::getInstance();
    do {
        meniu->meniu();
        std::cout << "Introduceti numarul optiunii: ";
        std::cin >> option;

        switch(option) {
            case 1: {
                meniu->adaugareCopii();
                break;
            }
            case 2: {
                meniu->afisareCopii();
                break;
            }
            case 3: {
                std::string numeCopil;
                std::cout << "Numele copilului cautat este: ";
                std::cin >> numeCopil;
                meniu->cautaCopil(numeCopil);
                break;
            }
            case 4: {
                meniu->ordonareVarsta();
                break;
            }
            case 5: {
                meniu->ordonareFapteBune();
                break;
            }
            case 6: {
                int id, numarFapteBune;
                std::cout << "ID-ul copilui este: ";
                std::cin >> id;
                std::cout << "Numarul de fapte bune adaugate: ";
                std::cin >> numarFapteBune;
                meniu->adaugareFapteBune(id, numarFapteBune);
            }
            case 7: {
                meniu->raportJucarii();
            }
            case 0: {
                std::cout << "Iesire din aplicatie...\n";
                break;
            }
            default: {
                std::cout << "Nu exista aceasta optiune!\n";
            }
        }
    } while (option != 0);
}

int main() {
    aplicatie();
    return 0;
}
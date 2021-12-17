#include "Meniu.h"
#include "CopilCuminte.h"
#include "CopilNeastamparat.h"
#include <string>

Meniu* Meniu::instance = nullptr;

Meniu *Meniu::getInstance() {
    if (instance == nullptr) {
        instance = new Meniu();
    }
    return instance;
}

void Meniu::meniu() {
    std::cout << "-----------------------------\n";
    std::cout << "\tMENIU\tALEGETI O OPTIUNE: \n";
    std::cout << "1. Citire Copii\n";
    std::cout << "2. Afisare Copii\n";
    std::cout << "0 . Iesire\n";
    std::cout << "-----------------------------\n";
}

void Meniu::adaugareCopii() {
    int numarCopii;
    std::cout << "Numarul de copii este: ";
    std::cin >> numarCopii;

    for (int i = 0; i < numarCopii; i++) {
        unsigned int option, conditieCitire = 0;
        std::shared_ptr<Copil> tempCopil;
        while (conditieCitire == 0) {
            std::cout << "Tip copil (1-Cuminte, 2-Neastamparat): ";
            std::cin >> option;
            try {
                conditieCitire = 1;
                switch (option) {
                    case 1: {
                        tempCopil = std::make_shared<CopilCuminte>();
                        break;
                    }
                    case 2: {
                        tempCopil = std::make_shared<CopilNeastamparat>();
                        break;
                    }
                    default: {
                        throw option;
                    }
                }
                tempCopil->read(std::cin);
                copii.push_back(tempCopil);
            } catch (unsigned int &e) {
                std::cout << "Eroare: Optiune invalida!\n";
                conditieCitire = 0;
            }
        }
    }
}

void Meniu::afisareCopii() {
    for (auto &copil : copii) {
        copil->print(std::cout);
    }
}

void Meniu::cautaCopil(const std::string &numeCopil) {
    std::size_t found;
    for (auto &copil : copii) {
        found = copil->getNume().find(numeCopil);
        if (found != std::string::npos) {
            copil->print(std::cout);
        }
    }
}

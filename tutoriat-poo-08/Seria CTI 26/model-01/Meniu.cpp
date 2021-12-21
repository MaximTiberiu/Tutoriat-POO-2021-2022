#include "Meniu.h"
#include "CopilCuminte.h"
#include "CopilNeastamparat.h"
#include "JucarieClasica.h"
#include "JucarieEducativa.h"
#include "JucarieElectronica.h"
#include "JucarieModerna.h"
#include <algorithm>

Meniu* Meniu::instance = nullptr;

Meniu *Meniu::getInstance() {
    if (instance == nullptr) {
        instance = new Meniu();
    }
    return instance;
}

void Meniu::meniu() {
    std::cout << "-------------------------------\n";
    std::cout << "\tMENIU\tALEGETI O OPTIUNE:\n";
    std::cout << "1. Citire Copii\n";
    std::cout << "2. Afisare Copii\n";
    std::cout << "3. Cautare Copil\n";
    std::cout << "0. Iesire\n";
    std::cout << "-------------------------------\n";
}

void Meniu::adaugareCopii() {
    unsigned int numarCopii;
    std::cout << "Numarul de copii este: ";
    std::cin >> numarCopii;

    for (int i = 0 ; i < numarCopii ; i++) {
        unsigned int option, conditieCitire = 0;
        std::shared_ptr<Copil> tempCopil;
        while (conditieCitire == 0) {
            std::cout << "Tip copil (1-Cuminte, 2-Neastamparat): ";
            std::cin >> option;
            conditieCitire = 1;
            try {
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
            } catch(...) {
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

void Meniu::ordonareVarsta() {
    std::sort(copii.begin(), copii.end(), [](const std::shared_ptr<Copil>& a, const std::shared_ptr<Copil>& b) -> bool {
        return a->getVarsta() > b->getVarsta();
    });
    afisareCopii();
}

void Meniu::ordonareFapteBune() {
    std::sort(copii.begin(), copii.end(), [](const std::shared_ptr<Copil>& a, const std::shared_ptr<Copil>& b) -> bool {
        return a->getNumarFapteBune() < b->getNumarFapteBune();
    });
    afisareCopii();
}

void Meniu::adaugareFapteBune(int idCopil, int numarFapteBune) {
    for (auto &copil : copii) {
        if (copil->getIdCopil() == idCopil) {
            copil->setNumarFapteBune(copil->getNumarFapteBune() + numarFapteBune);
            std::vector<std::shared_ptr<Jucarie>> jucarii = copil->getJucarii();
            for (int i = 0 ; i < numarFapteBune ; i++) {
                std::shared_ptr<Jucarie> tempJucarie;
                unsigned int option, conditieCitire = 0;
                while (conditieCitire == 0) {
                    std::cout << "Tip jucarie (1-clasica, 2-educativa, 3-electronica, 4-moderna): ";
                    std::cin >> option;
                    conditieCitire = 1;
                    try {
                        if (option < 1 || option > 4) {
                            throw option;
                        }
                        switch (option) {
                            case 1: {
                                tempJucarie = std::make_shared<JucarieClasica>();
                                break;
                            }
                            case 2: {
                                tempJucarie = std::make_shared<JucarieEducativa>();
                                break;
                            }
                            case 3: {
                                tempJucarie = std::make_shared<JucarieElectronica>();
                                break;
                            }
                            case 4: {
                                tempJucarie = std::make_shared<JucarieModerna>();
                                break;
                            }
                        }
                        tempJucarie->read(std::cin);
                        jucarii.push_back(tempJucarie);
                    } catch (...) {
                        std::cout << "Eroare: Optiune invalida!\n";
                        conditieCitire = 0;
                    }
                }
            }
            copil->setJucarii(jucarii);
        }
    }
}

void Meniu::raportJucarii() {
    int numarJucarii = 0;
    int frecventaJucarii[4] = {0, 0, 0, 0};
    for (auto &copil : copii) {
        std::vector<std::shared_ptr<Jucarie>> jucarii = copil->getJucarii();
        numarJucarii += jucarii.size();
        for (auto &jucarie : jucarii) {
            if (std::dynamic_pointer_cast<std::shared_ptr<JucarieClasica>>(jucarie)) {
                frecventaJucarii[0]++;
            } else if (std::dynamic_pointer_cast<std::shared_ptr<JucarieEducativa>>(jucarie)) {
                frecventaJucarii[1]++;
            } else if (std::dynamic_pointer_cast<std::shared_ptr<JucarieElectronica>>(jucarie)) {
                frecventaJucarii[2]++;
            } else {
                frecventaJucarii[3]++;
            }
        }
    }
    std::cout << "Numarult totatl de jucarii este " << numarJucarii << " dintre care " << frecventaJucarii[0] << " sunt clasice, "
                << frecventaJucarii[1] << " sunt educative, " << frecventaJucarii[2] << " sunt electronice, " << frecventaJucarii[3]
                << " sunt moderne.\n"
}

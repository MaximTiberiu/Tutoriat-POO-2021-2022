#include <limits>
#include <ios>
#include "CopilCuminte.h"
#include "JucarieClasica.h"
#include "JucarieEducativa.h"
#include "JucarieElectronica.h"
#include "JucarieModerna.h"

CopilCuminte::CopilCuminte(const std::string &_nume, const std::string &_prenume, const std::string &_adresa,
                           unsigned int _varsta, unsigned int _numarFapteBune, const std::vector<std::shared_ptr<Jucarie>> &_jucarii,
                           int _numarDulciuri) : Copil(_nume, _prenume, _adresa, _varsta, _numarFapteBune, _jucarii) {
    this->numarDulciuri = _numarDulciuri;
}

void CopilCuminte::read(std::istream &in) {
    std::cout << "Nume: ";
    in >> nume;

    std::cout << "Prenume: ";
    in >> prenume;

    std::cout << "Adresa: ";
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(in, adresa);

    std::cout << "Varsta: ";
    in >> varsta;

    std::cout << "Numar fapte bune: ";
    in >> numarFapteBune;
    // este corect, dar pentru testare ramane comentat
//    while(numarFapteBune < 10) {
//        std::cout << "Numar fapte bune gresit! Numarul de fapte bune trebuie sa fie >= 10!\n";
//        std::cout << "Numar fapte bune: ";
//        in >> numarFapteBune;
//    }
    std::cout << "Numar dulciuri: ";
    in >> numarDulciuri;

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
}

void CopilCuminte::print(std::ostream &out) const {
    Copil::print(out);
    out << "Numar dulciuri: " << numarDulciuri << "\n";
}

#include "Copil.h"
#include "JucarieClasica.h"
#include "JucarieEducativa.h"
#include "JucarieElectronica.h"
#include "JucarieModerna.h"

int Copil::static_idCopil = 0;

Copil::Copil(const std::string &_nume, const std::string &_prenume, const std::string &_adresa, unsigned int _varsta,
             unsigned int _numarFapteBune, const std::vector<std::shared_ptr<Jucarie>> &_jucarii) {
    idCopil = ++static_idCopil;
    this->nume = _nume;
    this->prenume = _prenume;
    this->adresa = _adresa;
    this->varsta = _varsta;
    this->numarFapteBune = _numarFapteBune;
    this->jucarii = _jucarii;
}

void Copil::read(std::istream &in) {
    std::cout << "Nume: ";
    in >> nume;

    std::cout << "Prenume: ";
    in >> prenume;

    std::cout << "Adresa: ";
    in >> adresa;

    std::cout << "Varsta: ";
    in >> varsta;

    std::cout << "Numar fapte bune: ";
    in >> numarFapteBune;

    for (int i = 0 ; i < numarFapteBune ; i++) {
        std::shared_ptr<Jucarie> tempJucarie;
        unsigned int option;
        std::cout << "Tip jucarie (1-clasica, 2-educativa, 3-electronica, 4-moderna): ";
        std::cin >> option;
        try {
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
                default: {
                    std::cout << "Optiune invalida!\n";
                    break;
                }
            }
            tempJucarie->read(std::cin);
            jucarii.push_back(tempJucarie);
        } catch (std::runtime_error &e) {
            std::cout << "Eroare: " << e.what() << "\n";
        }
    }
}

void Copil::print(std::ostream &out) const {
    out << "ID: " << idCopil << "\n";
    out << "Nume si Prenume: " << nume << " " << prenume << "\n";
    out << "Adresa: " << adresa << "\n";
    out << "Varsta: " << varsta << "\n";
    out << "Numar fapte bune: " << numarFapteBune << "\n";
    out << "Jucarii:\n";
    for (auto &jucarie : jucarii) {
        jucarie->print(out);
    }
}

std::istream &operator>>(std::istream &in, Copil &copil) {
    copil.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Copil &copil) {
    copil.print(out);
    return out;
}

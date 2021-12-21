#include "Copil.h"
#include "JucarieClasica.h"
#include "JucarieEducativa.h"
#include "JucarieElectronica.h"
#include "JucarieModerna.h"

#include <limits>
#include <ios>

int Copil::static_idCopil = 0;

Copil::Copil() : idCopil(++static_idCopil) {}

Copil::Copil(const std::string &_nume, const std::string &_prenume, const std::string &_adresa, unsigned int _varsta,
             unsigned int _numarFapteBune, const std::vector<std::shared_ptr<Jucarie>> &_jucarii) : idCopil(++static_idCopil) {
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
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(in, adresa);

    std::cout << "Varsta: ";
    in >> varsta;

    std::cout << "Numar fapte bune: ";
    in >> numarFapteBune;

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

const std::string &Copil::getNume() const {
    return nume;
}

unsigned int Copil::getVarsta() const {
    return varsta;
}

unsigned int Copil::getNumarFapteBune() const {
    return numarFapteBune;
}

//Copil Copil::operator+(unsigned int x) {
//    this->numarFapteBune += x;
//    return (*this);
//}

const int Copil::getIdCopil() const {
    return idCopil;
}

void Copil::setNumarFapteBune(unsigned int numarFapteBune) {
    Copil::numarFapteBune = numarFapteBune;
}

void Copil::setJucarii(const std::vector<std::shared_ptr<Jucarie>> &jucarii) {
    Copil::jucarii = jucarii;
}

const std::vector<std::shared_ptr<Jucarie>> &Copil::getJucarii() const {
    return jucarii;
}

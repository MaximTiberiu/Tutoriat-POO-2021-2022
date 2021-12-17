#include "CopilNeastamparat.h"

CopilNeastamparat::CopilNeastamparat(const std::string &_nume, const std::string &_prenume, const std::string &_adresa, int _varsta, int _numarFapteBune,
                           const std::vector<std::shared_ptr<Jucarie>> &_jucarii, int _numarCarbuni)
        : Copil(_nume, _prenume, _adresa, _varsta, _numarFapteBune, _jucarii) {
    this->numarCarbuni = _numarCarbuni;
}

void CopilNeastamparat::read(std::istream &in) {
    Copil::read(in);
    std::cout << "Numar carbuni: ";
    in >> numarCarbuni;
}

void CopilNeastamparat::print(std::ostream &out) const {
    out << "Copil cuminte:\n";
    Copil::print(out);
    out << "Numar carbuni: " << numarCarbuni << "\n";
}


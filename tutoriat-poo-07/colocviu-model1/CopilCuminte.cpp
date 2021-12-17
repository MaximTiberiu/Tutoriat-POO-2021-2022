#include "CopilCuminte.h"

CopilCuminte::CopilCuminte(const std::string &_nume, const std::string &_prenume, const std::string &_adresa, int _varsta, int _numarFapteBune,
                           const std::vector<std::shared_ptr<Jucarie>> &_jucarii, int _numarDulciuri)
                           : Copil(_nume, _prenume, _adresa, _varsta, _numarFapteBune, _jucarii) {
    this->numarDulciuri = _numarDulciuri;
}

void CopilCuminte::read(std::istream &in) {
    Copil::read(in);
    std::cout << "Numar dulciuri: ";
    in >> numarDulciuri;
}

void CopilCuminte::print(std::ostream &out) const {
    out << "Copil cuminte:\n";
    Copil::print(out);
    out << "Numar dulciuri: " << numarDulciuri << "\n";
}

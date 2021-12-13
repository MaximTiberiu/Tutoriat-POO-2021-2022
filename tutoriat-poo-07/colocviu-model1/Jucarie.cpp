#include "Jucarie.h"

Jucarie::Jucarie(const std::string &_denumire, float _dimensiune, const std::string &_tip) {
    this->denumire = _denumire;
    this->dimensiune = _dimensiune;
    this->tip = _tip;
}

std::istream &operator>>(std::istream &in, Jucarie &jucarie) {
    jucarie.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Jucarie &jucarie) {
    jucarie.print(out);
    return out;
}

void Jucarie::read(std::istream &in) {
    std::cout << "Denumire: ";
    in >> denumire;

    std::cout << "Dimensiune: ";
    in >> dimensiune;

    std::cout << "Tip: ";
    in >> tip;
}

void Jucarie::print(std::ostream &out) const {
    out << "Denumire: " << denumire << "\n";
    out << "Dimenisune: " << dimensiune << "\n";
    out << "Tip: " << tip << "\n";
}



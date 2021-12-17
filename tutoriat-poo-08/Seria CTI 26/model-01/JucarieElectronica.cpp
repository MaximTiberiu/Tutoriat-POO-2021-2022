#include "JucarieElectronica.h"

JucarieElectronica::JucarieElectronica(const std::string &_denumire, float _dimensiune, const std::string &_tip,
                                       int _numarBaterii) : Jucarie(_denumire, _dimensiune, _tip) {
    this->numarBaterii = _numarBaterii;
}

void JucarieElectronica::read(std::istream &in) {
    Jucarie::read(in);

    std::cout << "Numar baterii: ";
    in >> numarBaterii;
}

void JucarieElectronica::print(std::ostream &out) const {
    Jucarie::print(out);
    out << "Numar baterii: " << numarBaterii << "\n";
}

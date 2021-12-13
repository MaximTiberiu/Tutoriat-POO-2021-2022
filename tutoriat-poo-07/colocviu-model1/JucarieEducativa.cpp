//
// Created by Tiberiu on 12/10/2021.
//

#include "JucarieEducativa.h"

JucarieEducativa::JucarieEducativa(const std::string &_denumire, float _dimensiune, const std::string &_tip,
                                   const std::string &_abilitate) :Jucarie(_denumire, _dimensiune, _tip) {
    this->abilitate = _abilitate;
}

void JucarieEducativa::read(std::istream &in) {
    Jucarie::read(in);
    std::cout << "Abilitate: ";
    in >> abilitate;
}

void JucarieEducativa::print(std::ostream &out) const {
    Jucarie::print(out);
    out << abilitate << "\n";
}

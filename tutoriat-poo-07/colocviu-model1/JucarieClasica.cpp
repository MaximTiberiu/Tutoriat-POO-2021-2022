//
// Created by Tiberiu on 12/10/2021.
//

#include "JucarieClasica.h"

JucarieClasica::JucarieClasica(const std::string &_denumire, float dimensiune, const std::string &_tip, const std::string &_material,
                               const std::string &_culoare) : Jucarie(denumire, dimensiune, tip) {
    this->material = _material;
    this->culoare = _culoare;
}

void JucarieClasica::read(std::istream &in) {
    Jucarie::read(in);

    std::cout << "Material: ";
    in >> material;

    std::cout << "Culoare: ";
    in >> culoare;
}

void JucarieClasica::print(std::ostream &out) const {
//    out << "Jucarie Clasica:\n";
    Jucarie::print(out);
    out << "Material: " << material << "\n";
    out << "Culoare: " << culoare << "\n";
}

#include "JucarieClasica.h"

JucarieClasica::JucarieClasica(const std::string &_denumire, float _dimensiune, const std::string &_tip,
                               const std::string &_material, const std::string &_culoare)
                               : Jucarie(_denumire, _dimensiune, _tip) {
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
    Jucarie::print(out);
    out << "Material: " << material << "\n";
    out << "Culoare: " << culoare << "\n";
}

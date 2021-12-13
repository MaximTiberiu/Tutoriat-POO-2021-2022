#include "JucarieModerna.h"

JucarieModerna::JucarieModerna(const std::string &_denumire, float _dimensiune, const std::string &_tip, const std::string & _brand,
                               const std::string &_model) : Jucarie(_denumire, _dimensiune, _tip), JucarieEducativa(_denumire, _dimensiune, _tip, "generala"),
                                                            JucarieElectronica(_denumire, _dimensiune, _tip, 1) {
    this->brand = _brand;
    this->model = _model;
}

void JucarieModerna::read(std::istream &in) {
    std::cout << "Denumire: ";
    in >> denumire;

    std::cout << "Dimensiune: ";
    in >> dimensiune;

    std::cout << "Tip: ";
    in >> tip;

    std::cout << "Brand: ";
    in >> brand;

    std::cout << "Model: ";
    in >> model;
}

void JucarieModerna::print(std::ostream &out) const {
    JucarieEducativa::print(out);
    out << "Numar baterii: " << numarBaterii << "\n";
    out << "Brand: " << brand << "\n";
    out << "Model: " << model << "\n";
}

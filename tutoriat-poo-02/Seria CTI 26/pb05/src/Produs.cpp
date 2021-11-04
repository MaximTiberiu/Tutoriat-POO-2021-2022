#include "../headers/Produs.h"

Produs::Produs(std::string _denumire, float _pret) {
    this->denumire = _denumire;
    this->pret = _pret;
}

const std::string &Produs::getDenumire() const {
    return denumire;
}

void Produs::setDenumire(const std::string &denumire) {
    Produs::denumire = denumire;
}

float Produs::getPret() const {
    return pret;
}

void Produs::setPret(float pret) {
    Produs::pret = pret;
}

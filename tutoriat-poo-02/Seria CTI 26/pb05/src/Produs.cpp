#include "../headers/Produs.h"

Produs::Produs(std::string _denumire, float _pret, int _numar_produse) {
    this->denumire = _denumire;
    this->pret = _pret;
    this->numar_produse = _numar_produse;
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

int Produs::getNumarProduse() const {
    return numar_produse;
}

void Produs::setNumarProduse(int numarProduse) {
    numar_produse = numarProduse;
}

//std::ostream &operator<<(std::ostream & out, const Produs &produs) {
//    out << produs.denumire << " " << produs.pret << " " << produs.numar_produse << "\n";
//    return out;
//}

#include "Zbor.h"

int Zbor::static_idZbor = 0;

Zbor::Zbor() : idZbor(++static_idZbor) {}

Zbor::Zbor(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret) :
    idZbor(++static_idZbor) {
    this->destinatie = _destinatie;
    this->dataOraPlecare = _dataOraPlecare;
    this->durataZbor = _durataZbor;
}

#include "ZborLowCost.h"

ZborLowCost::ZborLowCost(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret,
                         float _greutateBagajCala, float _pretPerKg) : Zbor(_destinatie, _dataOraPlecare, _durataZbor, _pret) {
    this->greutateBagajCala = _greutateBagajCala;
    this->pretPerKg = _pretPerKg;
}

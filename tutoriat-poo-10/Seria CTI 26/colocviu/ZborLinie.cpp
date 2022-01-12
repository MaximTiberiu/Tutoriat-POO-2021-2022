#include "ZborLinie.h"

ZborLinie::ZborLinie(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret,
                     const std::vector<std::string> &_escale) : Zbor(_destinatie, _dataOraPlecare, _durataZbor, _pret) {
    this->escale = _escale;
}

#include "ZborCharter.h"

ZborCharter::ZborCharter(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret,
                         const std::string &_pachetServiciiSol, float _diferentaAferentaPachet) :
                         Zbor(_destinatie, _dataOraPlecare, _durataZbor, _pret) {
    this->pachetServiciiSol = _pachetServiciiSol;
    this->diferentaAferentaPachet = _diferentaAferentaPachet;
}

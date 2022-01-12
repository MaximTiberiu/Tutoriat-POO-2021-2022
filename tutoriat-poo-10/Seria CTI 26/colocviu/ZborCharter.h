#ifndef COLOCVIU_ZBORCHARTER_H
#define COLOCVIU_ZBORCHARTER_H

#include "Zbor.h"

class ZborCharter : public Zbor {
private:
    std::string pachetServiciiSol;
    float diferentaAferentaPachet{};

public:
    ZborCharter() = default;
    ~ZborCharter() = default;

    ZborCharter(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret,
                const std::string &_pachetServiciiSol, float _diferentaAferentaPachet);
};


#endif //COLOCVIU_ZBORCHARTER_H

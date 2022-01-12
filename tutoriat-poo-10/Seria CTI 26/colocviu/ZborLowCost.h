#ifndef COLOCVIU_ZBORLOWCOST_H
#define COLOCVIU_ZBORLOWCOST_H

#include "Zbor.h"

class ZborLowCost : public Zbor {
private:
    float greutateBagajCala{};
    float pretPerKg{};

public:
    ZborLowCost() = default;
    ~ZborLowCost() = default;

    ZborLowCost(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret,
                float _greutateBagajCala, float _pretPerKg);
};


#endif //COLOCVIU_ZBORLOWCOST_H

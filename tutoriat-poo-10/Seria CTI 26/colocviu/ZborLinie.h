#ifndef COLOCVIU_ZBORLINIE_H
#define COLOCVIU_ZBORLINIE_H

#include "Zbor.h"
#include <vector>

class ZborLinie : public Zbor {
private:
    std::vector<std::string> escale;

public:
    ZborLinie() = default;
    ~ZborLinie() = default;

    ZborLinie(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret,
              const std::vector<std::string> &_escale);
};


#endif //COLOCVIU_ZBORLINIE_H

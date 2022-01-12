#ifndef COLOCVIU_ZBOR_H
#define COLOCVIU_ZBOR_H

#include <iostream>

struct DataOra {
    unsigned int ora{};
    unsigned int minut{};
    unsigned int ziua{};
    unsigned int luna{};
    unsigned int anul{};
};

class Zbor {
protected:
    static int static_idZbor;
    const int idZbor{};
    std::string destinatie;
    DataOra dataOraPlecare;
    int durataZbor{};
    float pret{};

public:
    Zbor();
    ~Zbor() = default;

    Zbor(const std::string &_destinatie, const DataOra &_dataOraPlecare, int _durataZbor, float _pret);

};


#endif //COLOCVIU_ZBOR_H

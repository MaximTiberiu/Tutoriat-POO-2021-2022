#ifndef PB05_CLIENT_H
#define PB05_CLIENT_H

#include <string>
#include <vector>
#include "Produs.h"

class Client {
private:
    std::string nume;
    char id;
    float suma_maxima;
    std::vector<Produs> produse;

public:
    Client() = default;
    Client(const std::string &_nume, char _id, float _suma_maxima);
    Client(const std::string &_nume, char _id, float _suma_maxima, const std::string &_lista_cumparaturi);

    void afisare();
};

#endif //PB05_CLIENT_H

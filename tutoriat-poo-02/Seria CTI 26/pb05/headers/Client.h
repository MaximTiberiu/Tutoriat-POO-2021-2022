#ifndef P05_CLIENT_H
#define P05_CLIENT_H

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
    Client(std::string _nume, char _id, float _suma_maxima);
    Client(std::string _nume, char _id, float _suma_maxima, std::string lista_cumparaturi); // lista_cumparaturi - cale catre fisierul .txt

    void afisare();
};



#endif //P05_CLIENT_H

#include <iostream>
#include "Casa.h"


Casa::Casa(int numarCasa, const std::vector<Client> &clienti) : numarCasa(numarCasa), clienti(clienti) {}

void Casa::serveste() {
    for (auto & client : this->clienti) {
        if (client.totalPlata() != -1) {
            std::cout << "Achitat!\n";
        } else {
            std::cout << "Nu se poate face plata!\n";
        }
    }
}

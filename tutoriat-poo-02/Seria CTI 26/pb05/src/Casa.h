#ifndef P05_CASA_H
#define P05_CASA_H

#include <vector>
#include "../headers/Client.h"

class Casa {
private:
    int numarCasa;
    std::vector<Client> clienti;

public:
    Casa() = default;
    ~Casa() = default;
    Casa(int numarCasa, const std::vector<Client> &clienti);

    void serveste();
};

#endif //P05_CASA_H

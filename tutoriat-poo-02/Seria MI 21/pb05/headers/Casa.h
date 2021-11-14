#ifndef PB05_CASA_H
#define PB05_CASA_H

#include "Client.h"

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

#endif //PB05_CASA_H

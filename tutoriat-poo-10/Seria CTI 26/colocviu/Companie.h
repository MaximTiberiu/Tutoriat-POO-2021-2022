#ifndef COLOCVIU_COMPANIE_H
#define COLOCVIU_COMPANIE_H

#include <iostream>
#include <vector>
#include <memory>
#include "Zbor.h"

class Companie {
private:
    std::string denumireCompanie;
    int anInfiintare{};
    std::string sediu;
    std::string codICAO;
    std::string codIATA;
    std::string tipCompanie; // low-cost, linie
    std::vector<std::string> destinatii;
    std::vector<std::shared_ptr<Zbor>> zboruri;

public:
    Companie() = default;
    ~Companie() = default;

    Companie(const std::string &_denumireCompanie, int _anInfiintare, const std::string &_sediu, const std::string &_codICAO,
             const std::string &_codIATA, const std::vector<std::string> &_destinatii, const std::vector<std::shared_ptr<Zbor>> &_zboruri);

    void setTipCompanie(const std::string &_tipCompanie);

    friend std::istream& operator>>(std::istream & in, Companie& companie);
    friend std::ostream& operator<<(std::ostream & out, const Companie &companie);

    void read(std::istream& in);
    void print(std::ostream  &out) const;
};


#endif //COLOCVIU_COMPANIE_H

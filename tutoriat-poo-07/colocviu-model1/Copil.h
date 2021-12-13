#ifndef COLOCVIU_MODEL1_COPIL_H
#define COLOCVIU_MODEL1_COPIL_H

#include <vector>
#include <memory>
#include "Jucarie.h"

class Copil {
protected:
    static int s_idCopil;
    const int idCopil{};
    std::string nume;
    std::string prenume;
    std::string adresa;
    int varsta{};
    int numarFapteBune{};
    std::vector<std::shared_ptr<Jucarie>> jucarii;

public:
    Copil() = default;
    virtual ~Copil() = default;

    Copil(const std::string&, const std::string&, const std::string&, int, int, const std::vector<std::shared_ptr<Jucarie>>&);
    Copil(const Copil&) = default;
    Copil & operator=(const Copil&) = default;

    friend std::istream& operator>>(std::istream&, Copil&);
    friend std::ostream& operator<<(std::ostream&, const Copil&);

    virtual void read(std::istream&);
    virtual void print(std::ostream&) const;


};


#endif //COLOCVIU_MODEL1_COPIL_H

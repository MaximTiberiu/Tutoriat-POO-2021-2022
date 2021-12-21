#ifndef MODEL_01_COPIL_H
#define MODEL_01_COPIL_H

#include <memory>
#include <vector>
#include "Jucarie.h"

class Copil {
protected:
    static int static_idCopil;
    const int idCopil{};
    std::string nume;
    std::string prenume;
    std::string adresa;
    unsigned int varsta{};
    unsigned int numarFapteBune{};
    std::vector<std::shared_ptr<Jucarie>> jucarii; // echivalent cu: std::vector<Jucarie*> jucarii;
public:
    Copil();
    virtual ~Copil() = default;
    Copil(const std::string& _nume, const std::string &_prenume, const std::string &_adresa, unsigned int _varsta,
          unsigned int _numarFapteBune, const std::vector<std::shared_ptr<Jucarie>>& _jucarii);
    Copil(const Copil&) = default;
    Copil &operator=(const Copil&) = default;
//    Copil operator+(unsigned int x);

    friend std::istream& operator>>(std::istream& in, Copil& copil);
    friend std::ostream& operator<<(std::ostream& out, const Copil& copil);

    virtual void read(std::istream& in);
    virtual void print(std::ostream& out) const;

    void setNumarFapteBune(unsigned int numarFapteBune);

    const std::string &getNume() const;

    unsigned int getVarsta() const;

    void setJucarii(const std::vector<std::shared_ptr<Jucarie>> &jucarii);

    unsigned int getNumarFapteBune() const;

    const std::vector<std::shared_ptr<Jucarie>> &getJucarii() const;

    const int getIdCopil() const;
};


#endif //MODEL_01_COPIL_H

#include <iostream>
#include <vector>

// Implementarea clasei Curs - nr ore, titular si grupa si sa citeasca datele a n cursuri si sa se afiseze.

class Curs {
private:
    int nrOre;
    std::string titular;
    int grupa;

public:
    Curs(int _nrOre, const std::string &_titular, int _grupa) {
        this->nrOre = _nrOre;
        this->grupa = _grupa;
        this->titular = _titular;
    }

    Curs() = default;
    ~Curs() = default;

    int getNrOre() const;
    void setNrOre(int nrOre);

    const std::string &getTitular() const;
    void setTitular(const std::string &titular);

    int getGrupa() const;
    void setGrupa(int grupa);

    void afisare();
};

int Curs::getNrOre() const {
    return nrOre;
}

void Curs::setNrOre(int _nrOre) {
    Curs::nrOre = _nrOre;
}

const std::string &Curs::getTitular() const {
    return titular;
}

void Curs::setTitular(const std::string &_titular) {
    Curs::titular = _titular;
}

int Curs::getGrupa() const {
    return grupa;
}

void Curs::setGrupa(int _grupa) {
    Curs::grupa = _grupa;
}

void Curs::afisare() {
    std::cout << this->nrOre << " " << this->titular << " " << this->grupa << "\n";
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Curs> cursuri;

    for(int i = 0 ; i < n ; i++) {
        int _nrOre, _grupa;
        std::string _titular;
        std::cin >> _nrOre >> _titular >> _grupa;
        Curs temp(_nrOre, _titular, _grupa);
        cursuri.push_back(temp);
    }

    for(int i = 0 ; i < n ; i++) {
        cursuri[i].afisare();
    }

    return 0;
}

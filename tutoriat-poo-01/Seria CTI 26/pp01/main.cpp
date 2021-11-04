#include <iostream>
#include <vector>

// Implementarea clasei Curs - nr ore, titular si grupa si sa citeasca datele a n cursuri si sa se afiseze.

class Curs {
private:
    int nrOre;
    std::string titular;
    int grupa;
public:
    Curs(int nrOre, const std::string &titular, int grupa) {
        this->nrOre = nrOre;
        this->titular = titular;
        this->grupa = grupa;
        std::cout << "Constructor apelat!" << "\n";
    }
    ~Curs(){
        std::cout << "Destructor apelat!" << "\n";
    };

    int getNrOre() const {
        return nrOre;
    }

    const std::string &getTitular() const {
        return titular;
    }

    int getGrupa() const {
        return grupa;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Curs> cursuri;

    for (int i = 0 ; i < n ; i++) {
        int _nrOre, _grupa;
        std::string _titular;
        std::cin >> _nrOre >> _titular >> _grupa;
        Curs temp(_nrOre, _titular, _grupa);
        cursuri.push_back(temp);
    }

    for(int i = 0 ; i < n ; i++) {
        std::cout << cursuri[i].getNrOre() << " " << cursuri[i].getTitular() << " " << cursuri[i].getGrupa() << "\n";
    }

    return 0;
}

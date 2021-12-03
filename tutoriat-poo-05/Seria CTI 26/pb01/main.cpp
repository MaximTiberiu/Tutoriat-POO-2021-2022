#include <iostream>
#include <vector>

class Produs {
protected:
    std::string numeProdus;
    float pret{};
public:
    Produs() = default;
    ~Produs() = default;
    Produs(const std::string &_numeProdus, float _pret = 0) {
        this->numeProdus = _numeProdus;
        this->pret = _pret;
    }

    virtual void afisare() {
        std::cout << numeProdus << " " << pret << " ";
    }
};

class Perisabil : virtual public Produs {
protected:
    std::string dataExpirare;

public:
    Perisabil() = default;
    ~Perisabil() = default;
    Perisabil(const std::string & _numeProdus, float _pret, const std::string &_dataExpirare) : Produs(_numeProdus, _pret) {
        this->dataExpirare = _dataExpirare;
    }

    void afisare() override {
        Produs::afisare();
        std::cout << dataExpirare << " ";
    };
};

class Promotie : virtual public Produs {
protected:
    float reducere{};

public:
    Promotie() = default;
    ~Promotie() = default;
    Promotie(const std::string & _numeProdus, float _pret, float _reducere) : Produs(_numeProdus, _pret) {
        this->reducere = _reducere;
    }

    void afisare() override  {
        Produs::afisare();
        std::cout << reducere << " ";
    }
};

class PerisabilPromotie : public Perisabil, public Promotie {
public:
    PerisabilPromotie() = default;
    ~PerisabilPromotie() = default;
    PerisabilPromotie(const std::string & _numeProdus, float _pret, const std::string &_dataExpirare, float _reducere)
    : Produs(_numeProdus, _pret), Perisabil(_numeProdus, _pret, _dataExpirare), Promotie(_numeProdus, _pret, _reducere) {
        this->reducere = _reducere;
    }

    void afisare() override {
        Perisabil::afisare();
        std::cout << reducere << " ";
    }
};

class Interfata {
private:
    unsigned int opt{};
    std::vector <Produs*> produse;

    static void showOptions() {
        std::cout << "1. Produs\n";
        std::cout << "2. Produs Perisabil\n";
        std::cout << "3. Produs la Promotie\n";
        std::cout << "4. Produs Persiabil la Promotie\n";
        std::cout << "0. Iesire\n";
    };
public:
    void showMenu() {
        std::cout << "Alegeti o optiune din meniul de mai jos:\n";
        showOptions();

        std::cin >> opt;
        std::string numeProdus, dataExpirare;
        float pret, reducere;

        while (opt) {
            if (opt == 1) {
                std::cout << "Nume produs: ";
                std::cin >> numeProdus;

                std::cout << "Pret: ";
                std::cin >> pret;

                produse.push_back(new Produs(numeProdus, pret));
            } else if (opt == 2) {
                std::cout << "Nume produs: ";
                std::cin >> numeProdus;

                std::cout << "Pret: ";
                std::cin >> pret;

                std::cout << "Data Expirare: ";
                std::cin >> dataExpirare;

                produse.push_back(new Perisabil(numeProdus, pret, dataExpirare));
            } else if (opt == 3) {
                std::cout << "Nume produs: ";
                std::cin >> numeProdus;

                std::cout << "Pret: ";
                std::cin >> pret;

                std::cout << "Reducere: ";
                std::cin >> reducere;

                produse.push_back(new Promotie(numeProdus, pret, reducere));
            } else if (opt == 4) {
                std::cout << "Nume produs: ";
                std::cin >> numeProdus;

                std::cout << "Pret: ";
                std::cin >> pret;

                std::cout << "Data Expirare: ";
                std::cin >> dataExpirare;

                std::cout << "Reducere: ";
                std::cin >> reducere;

                produse.push_back(new PerisabilPromotie(numeProdus, pret, dataExpirare, reducere));
            } else {
                std::cout << "Optiunea aleasa este gresita! Incercati din nou!\n";
            }

            std::cout << "\n--------";
            showOptions();
            std::cin >> opt;
        }
    }

    void afisareProduse() {
        for (auto & produs : produse) {
            produs->afisare();
            std::cout << "\n";
        }
    }

    void afisareProdusePerisabile() {
        int cnt = 0;
        for (auto & produs : produse) {
            if(dynamic_cast<Perisabil*>(produs)) {
                cnt++;
                produs->afisare();
                std::cout << "\n";
            }
        }
        std::cout << "Sunt " << cnt << " produse perisabile!\n";
    }
};

int main() {
    Interfata i;
    i.showMenu();

    std::cout << "\n--------------------------\nToate produsele: ";
    i.afisareProduse();

    std::cout << "\n--------------------------\nToate produsele perisabile: ";
    i.afisareProdusePerisabile();
    return 0;
}

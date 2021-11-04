#include <iostream>

class Fruct {
private:
    int greutate;
    std::string culoare;
public:
    Fruct() = default;
    ~Fruct() = default;

    Fruct(int _greutate, const std::string &_culoare);

    int getGreutate() const;
    void setGreutate(int greutate);

    const std::string &getCuloare() const;
    void setCuloare(const std::string &culoare);

    void afisare_fruct();
    friend void afisare_fruct_friend(const Fruct& fruct);
};

Fruct::Fruct(int _greutate, const std::string &_culoare) {
    this->greutate = _greutate;
    this->culoare = _culoare;
}

int Fruct::getGreutate() const {
    return greutate;
}

void Fruct::setGreutate(int _greutate) {
    Fruct::greutate = _greutate;
}

const std::string &Fruct::getCuloare() const {
    return culoare;
}

void Fruct::setCuloare(const std::string &_culoare) {
    Fruct::culoare = _culoare;
}

void Fruct::afisare_fruct() {
    std::cout << "Culoare: " << this->culoare << " si greutate: " << this->greutate << "\n";
}

void afisare_fruct_friend(const Fruct& fruct) {
    std::cout << "Culoare: " << fruct.culoare << " si greutate: " << fruct.greutate << "\n";
}

int main() {
    Fruct mar(125, "rosu");
    std::cout << mar.getGreutate() << " " << mar.getCuloare() << "\n";
    mar.setGreutate(130);
    mar.afisare_fruct();
    mar.setCuloare("galben");
    afisare_fruct_friend(mar);
    return 0;
}

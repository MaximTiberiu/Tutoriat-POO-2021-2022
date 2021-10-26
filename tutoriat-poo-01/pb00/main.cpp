#include <iostream>

class Fruct {
private:
    int greutate{};
    std::string culoare;
public:
    Fruct() = default;
    Fruct(int _greutate, const std::string & _culoare);
    ~Fruct() = default;
    Fruct(const Fruct& Fruct);

    int getGreutate() const {
        return greutate;
    }

    void setGreutate(int greutate);

    const std::string &getCuloare() const;

    void setCuloare(const std::string &culoare);

    void afisare_fruct();
    friend void afisare_fruct_friend(Fruct fruct);
};

Fruct::Fruct(int _greutate, const std::string & _culoare) {
    this->greutate = _greutate;
    this->culoare = _culoare;
}

Fruct::Fruct(const Fruct &fruct) {
    this->greutate = fruct.greutate;
    this->culoare = fruct.culoare;
}

void Fruct::setGreutate(int greutate) {
    Fruct::greutate = greutate;
}

const std::string &Fruct::getCuloare() const {
    return culoare;
}

void Fruct::setCuloare(const std::string &culoare) { //
    Fruct::culoare = culoare;
}

void Fruct::afisare_fruct() {
    std::cout << "Culoare: " << this->culoare << " si greutate: " << this->greutate << "\n";
}

void afisare_fruct_friend(Fruct fruct) {
    std::cout << "Culoare: " << fruct.culoare << " si greutate: " << fruct.greutate << "\n";
}

int main() {
    Fruct mar(125, "rosu");
    std::cout << mar.getGreutate() << "\n";
    mar.setGreutate(130);
    mar.setCuloare("verde");
    mar.setCuloare("galben");
    mar.afisare_fruct();
    afisare_fruct_friend(mar);
    return 0;
}

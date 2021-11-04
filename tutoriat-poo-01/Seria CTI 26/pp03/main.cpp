#include <iostream>
#include <vector>
#include <algorithm>

// Implementarea clasei Participare – la fiecare curs participa maxim 100 studenti din diferite grupe: citire, afisare, sortare dupa grupa si in fiecare grupa alfabetic.

class Participare {
private:
    int grupa;
    std::string nume;
public:
    Participare(int grupa, const std::string &nume);
    ~Participare() = default;

    Participare(const Participare& student) {
        this->grupa = student.grupa;
        this->nume = student.nume;
    }

    void citire() {
        std::cin >> grupa >> nume;
    }

    void afisare() {
        std::cout << grupa << " " << nume << "\n";
    }

    int getGrupa() const;

    const std::string &getNume() const;
};

Participare::Participare(int grupa, const std::string &nume) : grupa(grupa), nume(nume) {
}

int Participare::getGrupa() const {
    return grupa;
}

const std::string &Participare::getNume() const {
    return nume;
}

bool comparator(const Participare& a, const Participare& b) {
    if(a.getGrupa() == b.getGrupa()) {
        // nume alfabetic
        return a.getNume() < b.getNume();
    }
    // grupa crescatoare
    return a.getGrupa() < b.getGrupa();
}

int main() {
    std::vector<Participare> participare;
    participare.reserve(100);
    participare.emplace_back(264, "Mupetrei");
    participare.emplace_back(261, "Nupetrei");
    participare.emplace_back(261, "Apetrei");
    participare.emplace_back(262, "Zupetrei");
    participare.emplace_back(263, "Cupetrei");
    participare.emplace_back(262, "Bupetrei");

    std::sort(participare.begin(), participare.end(), &comparator); // varianta clasica cu comparator
    for(auto it = participare.begin() ; it != participare.end(); it++) { // for clasic cu iterator
        std::cout << it->getGrupa() << " " << it->getNume() << "\n";
    }

    std::sort(participare.begin(), participare.end(), [](const Participare& a, const Participare& b) { // varianta cu lambda function
        if(a.getGrupa() == b.getGrupa()) {
            // nume alfabetic
            return a.getNume() < b.getNume();
        }
        // grupa crescatoare
        return a.getGrupa() < b.getGrupa();
    });

    for(auto & it : participare) { // for cu auto-loop
        std::cout << it.getGrupa() << " " << it.getNume() << "\n";
    }
    return 0;
}

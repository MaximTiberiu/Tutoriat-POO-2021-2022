#include <iostream>
#include <vector>
#include <typeindex>

enum class Type {Persoana, Angajat, Student, Bugetar, Muncitor, StudentBursier};

class Persoana {
protected:
    std::string nume;

public:
    Persoana() = default;
    virtual ~Persoana() = default;

    Persoana(const std::string &_nume) {
        this->nume = _nume;
    }

    virtual void printInfo() {
        std::cout << "PERSOANA:\n";
        std::cout << "\tNume: " << nume << "\n";
    }

    virtual Type type() const {
        return Type::Persoana;
    }
};

class Angajat : public Persoana {
protected:
    std::string numeFirma;
    int cui{};

public:
    Angajat() = default;
    ~Angajat() override = default;

    Angajat(const std::string &_nume, const std::string &_numeFirma, int _cui) : Persoana(_nume) {
        this->numeFirma = _numeFirma;
        this->cui = _cui;
    }

    void printInfo() override {
        std::cout << "ANGAJAT:\n";
        std::cout << "\tNume: " << nume << "\n";
        std::cout << "\tNume firma: " << numeFirma << "\n";
        std::cout << "\tCUI: " << cui << "\n";
    }

    Type type() const override {
        return Type::Angajat;
    }
};

class Student : public Persoana {
protected:
    std::string universitate;
    std::string facultate;

public:
    Student() = default;
    ~Student() = default;

    Student(const std::string &_nume, const std::string &_universitate, const std::string &_facultate) : Persoana(_nume) {
        this->universitate = _universitate;
        this->facultate = _facultate;
    }

    void printInfo() override {
        std::cout << "STUDENT:\n";
        std::cout << "\tNume: " << nume << "\n";
        std::cout << "\tUniversitate: " << universitate << "\n";
        std::cout << "\tFacultate: " << facultate << "\n";
    }

    Type type() const override {
        return Type::Student;
    }
};

class Bugetar : public Angajat {
private:
    float salariuBazaFix{};

public:
    Bugetar() = default;
    ~Bugetar() = default;

    Bugetar(const std::string &_nume, const std::string &_numeFirma, int _cui, float _salariuBazaFix) : Angajat(_nume, _numeFirma, _cui) {
        this->salariuBazaFix = _salariuBazaFix;
    }

    void printInfo() override {
        std::cout << "BUGETAR:\n";
        std::cout << "\tNume: " << nume << "\n";
        std::cout << "\tNume firma: " << numeFirma << "\n";
        std::cout << "\tCUI: " << cui << "\n";
        std::cout << "\tSalariu de baza fix: " << salariuBazaFix << "\n";
    }

    Type type() const override {
        return Type::Bugetar;
    }
};

class Muncitor : public Angajat {
private:
    int numarOre{};
    float tarifOra{};

public:
    Muncitor() = default;
    ~Muncitor() = default;

    Muncitor(const std::string &_nume, const std::string &_numeFirma, int _cui, int _numarOre, float _tarifOra) : Angajat(_nume, _numeFirma, _cui) {
        this->numarOre = _numarOre;
        this->tarifOra = _tarifOra;
    }

    void printInfo() override {
        std::cout << "MUNCITOR:\n";
        std::cout << "\tNume: " << nume << "\n";
        std::cout << "\tNume firma: " << numeFirma << "\n";
        std::cout << "\tCUI: " << cui << "\n";
        std::cout << "\tNumar ore: " << numarOre << "\n";
        std::cout << "\tTarif ora: " << tarifOra << "\n";
    }

    Type type() const override {
        return Type::Muncitor;
    }
};

class StudentBursier : public Student {
private:
    float cuantumBursa{};

public:
    StudentBursier() = default;
    ~StudentBursier() = default;

    StudentBursier(const std::string &_nume, const std::string &_universitate, const std::string &_facultate, float _cuantumBursa) : Student(_nume, _universitate, _facultate) {
        this->cuantumBursa = _cuantumBursa;
    }

    void printInfo() override {
        std::cout << "STUDENT BURSIER:\n";
        std::cout << "\tNume: " << nume << "\n";
        std::cout << "\tUniversitate: " << universitate << "\n";
        std::cout << "\tFacultate: " << facultate << "\n";
        std::cout << "\tCuantum bursa: " << cuantumBursa << "\n";
    }

    Type type() const override {
        return Type::StudentBursier;
    }
};

int main() {
    auto *p1 = new Persoana("Ion");
//    p1->printInfo();
    auto *a1 = new Angajat("Mircea", "Mgazin Mixt SRL", 145267);
//    a1->printInfo();
    auto *s1 = new Student("Pascu", "UniBuc", "FMI");
//    s1->printInfo();
    auto *b1 = new Bugetar("Dan", "PMB", 893652, 3506.25);
//    b1->printInfo();
    auto *m1 = new Muncitor("Gica", "Gica SRL", 123456, 40, 160.56);
//    m1->printInfo();
    auto *sb1 = new StudentBursier("Laur", "UniBuc", "FMI", 760);
//    sb1->printInfo();

//    auto *p2 = new Persoana();
//    p2 = s1;
//    s1->printInfo();
//    p2->printInfo();

    std::vector<Persoana*> persoane;
    persoane.push_back(p1);
    persoane.push_back(a1);
    persoane.push_back(s1);
    persoane.push_back(b1);
    persoane.push_back(m1);
    persoane.push_back(sb1);

    // citire persoane
//    int n;
//    std::cin >> n;
//
//    for (int i = 0 ; i < n ; i++) {
//        int opt;
//        std::cout << "1. Persoana\n";
//        std::cout << "2. Angajat\n";
//        std::cout << "3. Student\n";
//        std::cout << "4. Bugetar\n";
//        std::cout << "5. Muncitor\n";
//        std::cout << "6. Student bursier\n";
//
//        std::cin >> opt;
//
//        if (opt == 1) {
//            std::string nume;
//            std::cin >> nume;
//            auto *p = new Persoana(nume);
//            persoane.push_back(p);
//        } else if (opt == 2) {
//            std::string nume, numeFirma;
//            int cui;
//            std::cin >> nume >> numeFirma >> cui;
//            auto *a = new Angajat(nume, numeFirma, cui);
//            persoane.push_back(a);
//        } else if (opt == 3) {
//            std::string nume, universitsate, facultate;
//            std::cin >> nume >> universitsate >> facultate;
//            auto *s = new Student(nume, universitsate, facultate);
//            persoane.push_back(s);
//        } else if (opt == 4) {
//            std::string nume, numeFirma;
//            int cui;
//            float salariuBazaFix;
//            std::cin >> nume >> numeFirma >> cui >> salariuBazaFix;
//            auto *b = new Bugetar(nume, numeFirma, cui, salariuBazaFix);
//            persoane.push_back(b);
//        } else if (opt == 5) {
//            std::string nume, numeFirma;
//            int cui, numarOre;
//            float tarifOra;
//            std::cin >> nume >> numeFirma >> cui >> numarOre >> tarifOra;
//            auto *m = new Muncitor(nume, numeFirma, cui, numarOre, tarifOra);
//            persoane.push_back(m);
//        } else if (opt == 6) {
//            std::string nume, universitsate, facultate;
//            float cuantumBursa;
//            std::cin >> nume >> universitsate >> facultate >> cuantumBursa;
//            auto *sb = new StudentBursier(nume, universitsate, facultate, cuantumBursa);
//            persoane.push_back(sb);
//        } else {
//            std::cout << "Optiune gresita!\n";
//        }
//    }

    // afisare persoane in ordinea citirii
    for (auto & persoana : persoane) {
        persoana->printInfo();
    }

    std::cout << "VARIANTA 1 ---------------------\n";
    for (auto & persoana : persoane) {
        if (persoana->type() == Type::Muncitor) {
            persoana->printInfo();
        }
    }

    for (auto & persoana : persoane) {
        if (persoana->type() == Type::StudentBursier) {
            persoana->printInfo();
        }
    }

    std::cout << "VARIANTA 2 ---------------------\n";
    for (auto & persoana : persoane) {
        std::type_index typeIndex(typeid(*persoana));
        if (typeIndex == std::type_index(typeid(Muncitor))) {
            persoana->printInfo();
        }
    }

    for (auto & persoana : persoane) {
        std::type_index typeIndex(typeid(*persoana));
        if (typeIndex == std::type_index(typeid(StudentBursier))) {
            persoana->printInfo();
        }
    }

    std::cout << "VARIANTA 3 ---------------------\n";
    for (auto & persoana : persoane) {
        if (dynamic_cast<Muncitor*>(persoana)) {
            persoana->printInfo();
        }
    }

    for (auto & persoana : persoane) {
        if (dynamic_cast<StudentBursier*>(persoana)) {
            persoana->printInfo();
        }
    }

    // eliberare memorie
    for (auto & persoana : persoane) {
        delete persoana;
    }
    persoane.clear();

//    delete p1;
//    delete a1;
//    delete s1;
//    delete b1;
//    delete m1;
//    delete sb1;
    return 0;
}

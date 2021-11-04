#include <iostream>
#include <vector>

// Implementarea clasei Student – id, grupa, nume, functii de citire si afisare

class Student {
private:
    int id;
    std::string nume;
    int grupa;
public:
    Student(int id, const std::string &nume, int grupa) {
        this->id = id;
        this->nume = nume;
        this->grupa = grupa;
        std::cout << "Constructor apelat!" << "\n";
    }

    Student(int id) {
        this->id = id;
    }

    ~Student(){
        std::cout << "Destructor apelat!" << "\n";
    };

    Student(const Student& student);

    int getId() const;
    void setId(int id);

    const std::string &getNume() const;
    void setNume(const std::string &nume);

    int getGrupa() const;
    void setGrupa(int grupa);
};

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    Student::id = id;
}

const std::string &Student::getNume() const {
    return nume;
}

void Student::setNume(const std::string &nume) {
    Student::nume = nume;
}

int Student::getGrupa() const {
    return grupa;
}

void Student::setGrupa(int grupa) {
    Student::grupa = grupa;
}

Student::Student(const Student &student) {
    this->id = student.id;
    this->grupa = student.grupa;
    this->nume = student.nume;
    std::cout << "CC\n";
}

int main() {
    std::vector<Student> studenti;
    studenti.reserve(3);
    studenti.emplace_back(101, "Popa", 211);
    studenti.emplace_back(102, "Ioan", 212);
    studenti.emplace_back(103, "Popescu", 212);

    return 0;
}


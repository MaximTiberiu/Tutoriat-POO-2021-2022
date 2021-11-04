#include <iostream>
#include <vector>


class Student {
private:
    int id;
    int grupa;
    std::string nume;
public:
    Student(int id, int grupa, const std::string &nume);
    ~Student() {
//        std::cout << "destructor apelat\n";
    };

    Student(const Student& student) {
        this->id = student.id;
        this->grupa = student.grupa;
        this->nume = student.nume;
        std::cout << "constructor de copiere\n";
    }

    void citire() {
        std::cin >> id >> grupa >> nume;
    }

    void afisare() {
        std::cout << id << " " << grupa << " " << nume << "\n";
    }
};

Student::Student(int id, int grupa, const std::string &nume) : id(id), grupa(grupa), nume(nume) {
    std::cout << "constructor apelat\n";
}

int main() {
    std::vector<Student> studenti;
    studenti.reserve(3);

    studenti.emplace_back(101, 261, "Popescu");
    std::cout << "\n";
    studenti.emplace_back(102, 262, "Ionescu");
    return 0;
}

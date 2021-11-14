#include <iostream>
#include <vector>

/*
  Un student este caracterizat de un nume si o serie. Un curs are un nume si un numar oarecare de studenti
  (se utilizeaza si o structura de date care sa retina studentii). Implementati aceste clase, astfel incat, demo-ul de mai jos sa functioneze:
    int main() {
        curs C1, C2,C3;
        cin>>C1;
        cout<<C1;

        student s;
        cin>>s;
        C1=C1+s;   // se adauga un nou student la curs
        cout<<C1;
        cin>>C2;

        C3=C1+C2;    // daca cele 2 cursuri au aceeasi denumire, se “concateneaza” listele de studenti, // altfel nu se face nimic (se returneaza C1).
        cout<<C3;

        if(C1==C2)  // verifica daca 2 cursuri sunt identice ca denumire si lista de studenti
            cout<<"Cursuri identice";
        else
            cout<<"Cursuri diferite";

        return 0;
}
 */

class Student {
private:
    std::string numeStudent;
    int serie;

public:
    Student() = default;
    ~Student() = default;
    Student(const std::string &numeStudent, int serie) : numeStudent(numeStudent), serie(serie) {}
    Student(const Student &student) {
        this->numeStudent = student.numeStudent;
        this->serie = student.serie;
    }

    friend std::istream& operator>>(std::istream& in, Student &student) {
        in >> student.numeStudent >> student.serie;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student &student) {
        out << student.numeStudent << " " << student.serie << "\n";
        return out;
    }

    const std::string &getNumeStudent() const {
        return numeStudent;
    }

    int getSerie() const {
        return serie;
    }
};

class Curs {
private:
    std::string numeCurs;
    std::vector<Student> studenti;

public:
    Curs() = default;
    ~Curs() = default;
    Curs(const std::string &numeCurs, const std::vector<Student> &studenti) : numeCurs(numeCurs), studenti(studenti) {}
    Curs(const Curs &curs) {
        this->numeCurs = curs.numeCurs;
        this->studenti = curs.studenti;
    }

    friend std::istream& operator>> (std::istream& in, Curs &curs) {
        in >> curs.numeCurs;
        std::cout << "Numar studenti inscrisi: ";
        int n;
        in >> n;

        for (int i = 0; i < n ; i++) {
            Student tempStud;
            in >> tempStud;
            curs.studenti.emplace_back(tempStud);
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Curs &curs) {
        out << curs.numeCurs << "\nSTUDENTI:\n";
        for(auto & student : curs.studenti) {
            out << student;
        }
        return out;
    }

    Curs operator+(const Student &student) {
        this->studenti.emplace_back(student);
        return (*this);
    }

    Curs operator+(const Curs &curs) {
        if (this->numeCurs == curs.numeCurs) {
            Curs tempCurs = *this;
            for (auto & student : curs.studenti) {
                tempCurs.studenti.emplace_back(student);
            }
            return tempCurs;
        }
        return (*this);
    }

    bool operator==(const Curs &curs) const {
        if (numeCurs != curs.numeCurs) {
            return false;
        }
        if(studenti.size() != curs.studenti.size()) {
            return false;
        }

        for (int i = 0 ; i < studenti.size() ; i++) {
            if (studenti[i].getNumeStudent() != curs.studenti[i].getNumeStudent() || studenti[i].getSerie() != curs.studenti[i].getSerie()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Student s1("popa", 26), s2("popa", 26);
    Curs c1("OOP", {s1});
    Curs c2("OOP", {s2});
    Curs c3 = c1 + c2;
    std::cout << c3;

    if(c1 == c2) {
        std::cout << "Cursurile sunt identice!\n";
    } else {
        std::cout << "Cursurile difera!\n";
    }
    return 0;
}

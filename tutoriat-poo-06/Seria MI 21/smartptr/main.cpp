#include <iostream>
#include <memory>

/*
 * Smart pointers - Containers / Wrappers pentru raw pointers (clasici)
 * Avantaje: memoria se dezaloca automat => fara memory leaks (nu mai avem nevoie de new si nici de delete)
 * 3 tipuri: unique_ptr, shared_ptr, weak_ptr
 */

class smartptr {
public:
    smartptr() {
        std::cout << "Constructor apelat!\n";
    }

    ~smartptr() {
        std::cout << "Destructor apelat!\n";
    }

    void fun() {
        std::cout << "fun() apelat!\n";
    }
};

int main() {
    /*
     * UNIQUE_PTR - scoped pointer (cand acesta ramane fara scop / utilitate, disapre)
     * NU poti copia un unique_ptr (unique) - va pointa mereu catre aceeasi zona de memorie =>
     * => cand unul dintre ei moare, celalalt ramane fara zona de memorie la care sa pointeze
     */

//    std::unique_ptr<smartptr> uniquePtr(new smartptr()); // nerecomandata - apar exceptii!
    {
        std::unique_ptr<smartptr> uniquePtr = std::make_unique<smartptr>();
//        std::unique_ptr<smartptr> uniquePtr1 = uniquePtr; // - nu se poate face copie (putem folosi std::move() - pentru a muta pointerul)
        uniquePtr->fun();
    }
    std::cout << "Bla bla..\n";

    std::cout << "\n\n\n\n\n---------------------\n";


    /*
     * SHARED_PTR - rezolva problema copierii lui unique_ptr (se bazeaza pe reference counting)
     * Ref. counting - cand contorul ajunge la 0, se sterge
     *               - metoda .use_count() -> vedem cate copii sunt active la momentul apelului
     */
    {
        std::shared_ptr<smartptr> sharedPtr1;
        {
            std::shared_ptr<smartptr> sharedPtr = std::make_shared<smartptr>();
//            std::shared_ptr<smartptr> sharedPtr(new smartptr()); // SUPER GRESIT - ref. count = 2
            std::cout << sharedPtr.use_count() << "\n";
            sharedPtr->fun();
            sharedPtr1 = sharedPtr;
            std::cout << sharedPtr.use_count() << "\n";
        }
        sharedPtr1->fun();
    }

    std::cout << "\n\n\n\n\n---------------------\n";

    /*
     * WEAK_PTR - lucreaza impreuna cu SHARED_PTR
     * Cand se face o copie a unui shared_ptr intr-un weak_ptr, ref. countul nu creste
     */

    {
        std::weak_ptr<smartptr> weakPtr;
        {
            std::shared_ptr<smartptr> sharedPtr = std::make_shared<smartptr>();
//            std::shared_ptr<smartptr> sharedPtr(new smartptr()); // SUPER GRESIT - ref. count = 2
            std::cout << sharedPtr.use_count() << "\n";
            sharedPtr->fun();
            weakPtr = sharedPtr; // strong ref.
            std::cout << sharedPtr.use_count() << "\n";
        }
//        weakPtr->fun(); // EROARE: weak ref.
    }

    std::unique_ptr<int> intPtr = std::make_unique<int>(25);
    std::cout << *intPtr << "\n";
    return 0;
}

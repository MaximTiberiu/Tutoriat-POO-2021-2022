# Tutoriat POO 2021-2022

> Tutoriatul #01

## Curpins
* [Introducere](#introducere)
* [De ce OOP?](#de-ce-oop)
* [Principiile OOP](#principiile-oop)
* [Constructori și destructori](#constructori-și-destructori)
* [Funcții friend](#funcții-friend)

## Introducere
*Bine ai venit la tutoriatul de Programare Orientată pe Obiecte!*

Pentru această disciplină îți recomand recomand un IDE de la JetBrains pentru C/C++. Acesta este [CLion](https://www.jetbrains.com/clion/download/?source=google&medium=cpc&campaign=11964013813&gclid=Cj0KCQjwiNSLBhCPARIsAKNS4_c23wCEt3CXrmWDisLsUrtY4SBUm3jP6SDEdLGXAlqd-L9EbHrza7saAqtMEALw_wcB#section=windows) și **necesită licență**. Cu adresa instituțională (@s.unibuc.ro) ai posibilitatea să îți activezi o licență anuală ca să beneficiezi de toate softurile celor de la JetBrains.

## De ce OOP?
Programarea Orientată pe Obiecte are câteva avantaje:

 - un program bazat pe OOP este mai rapid și mai ușor de executat;
 - prin OOP, programul este structurat într-un mod organizat și foarte ușor de înțeles;
 - codul poate fi reutilizat în alte aplicații fără a veni cu foarte multe modificări;
 - ne ajută să obținem un cod DRY („Don't Repeat Yourself”).

## Principiile OOP

 1. Clasa - definește atribute și metode; (ex: clasa Fruct, definită prin culoare și mărime)
 2. Obiectul - instanță a unei clase (ex. obiectele măr și banană, cu atributele specifice clasei Fruct);
 3. Incapsularea - protecția datelor unui obiect; contopirea datelor cu codul;
 4. Agregarea - compunerea unui obiect din mai multe obiecte simple („”has a);
 5. Moștenirea - extinderea unei clase prin adăugarea unor atribute, metode de la alte clase („is a”);
 6. Ascunderea informației - prin specificatorii de acces (public, protected, private);
 7. Polimorfismul - posibilitatea claselor de a avea mai multe metode cu același nume, dar cu efecte și rezultate diferite (supraîncărcare de funcții/operatori, suprascrierea funcțiilor, funcții virtuale)

## Constructori și destructori
Constructorul reprezintă un mecanism prin care datele membre ale unui obiect dintr-o clasă primesc valori la instanțierea (declararea/crearea) obiectului.

Constructorul de copiere creează un obiect inițilizândul cu un alt obiect, din aceeași clasă, care există deja. 

Clasele au un constructor de copiere implicit, care realizează copierea _bit-cu-bit_ a conținutului obiectului. Acest mod de copiere nu este corect atunci când obiectul conține date alocate dinamic, caz în care este mecesară definirea unui constructor de copiere explicit.

Destructorul este o metodă publică care se apelează la eliminarea din memorie a unui obiect. O clasă poate avea un singur destructor, iar numele lui este identic cu al metodei, dar precedat de caracterul `~`.

EXEMPLU:

    #include <iostream>
	
	class Fruct {
	private:
		int greutate;
		std::string culoare;
	public:
		// Constructor default
		// dacă nu declarăm un constructor cu parametri, nu e  nevoie să îl mai declarăm
		Fruct() = default;
		~Fruct() = default; // destructor default (nu este obligatoriu să fie declarat)
		
		// CONSTRUCTOR PARAMETRIZAT
		Fruct(int greutate, const std::string& culoare) {
			this->greutate = greutate;
			this->culoare = culoare;
		} 
		
		// CONSTRUCTOR DE COPIERE
		Fruct(const Fruct& fruct) {
			this->greutate = fruct.greutate;
			this->culoare = fruct.culoare;
		}
	}    

    int main() {
	    // niște cod pentru clasa noastră
	    return 0;
    }

## Funcții friend

Uneori este necesar ca din interiorul unor funcții care nu sunt metode ale unui obiect să accesăm membrii privați ai acestuia. Acest lucru poate fi realizat prin intermediul **funcțiilor friend**. Ele:

-   sunt declarate în interiorul clasei; prototipul lor este precedat de cuvântul cheie  `friend`;
-   funcția prieten are un parametru de tipul clasei; în funcție se pot accesa membrii privați ai acesteia;
-   funcțiile prietene nu sunt metode ale clasei; ele nu pot accesa direct membrii clasei, ci numai membrii parametrului de tipul clasei.

EXEMPLU:

    #include <iostream>
	
	class Fruct {
	private:
		int greutate;
		std::string culoare;
	public:
		// cod cod cod
		friend void printFruct(Fruct fruct) {
			std::cout << "Culoare: " << fruct.culoare << " si greutate: " << fruct.greutate << "\n";
		}
	}    

    int main() {
	    Fruct mar(125, "rosu");
	    printFruct(mar);
	    return 0;
    }

## Probleme propuse
1.  Implementarea clasei Curs - nr ore, titular si grupa si sa citeasca datele a n cursuri si sa se afiseze.
    
2.  Implementarea clasei Student – id, grupa, nume, functii de citire si afisare.
    
3.  Implementarea clasei Participare – la fiecare curs participa maxim 100 studenti din diferite grupe: citire, afisare, sortare dupa grupa si in fiecare grupa alfabetic.
    
4.  Implementarea clasei Fractie – citire, afisare, suma.
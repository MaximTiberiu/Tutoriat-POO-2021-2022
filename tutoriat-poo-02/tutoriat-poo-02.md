
# Tutoriat POO 2021-2022

> Tutoriatul #02

## Probleme propuse - Modelarea Claselor
   
1.  Implementarea clasei **Fractie** – citire, afișare, sumă.
2. Să se definească o clasă **Punct**. Un punct este caracterizat de o abscisă și de o ordonată. Dreptunghi. Clasa va avea doi constructori: unul fără argumente și un altul care va primi ca argumente valorile celor doua coordonate. Se vor implementa metodele de accesare și setare a variabilelor private. Se va implementa, de asemenea și destructorul clasei.
3. Să se definească o clasă **Dreptunghi**. Un dreptunghi poate fi definit cunoscându-se coordonatele punctelor din două colțuri opuse. 
	 - Se vor implementa constructori, astfel:
		- Constructor fără argumente.
		- Constructor care va primi ca argumente coordonatele punctelor.
	- Se va implementa destructorul clasei precum și o metodă pentru calcul arie.
4. Să se definească o clasă **Complex** pentru operații cu numere complexe și să se testeze metodele implementate. 
	- Clasa va avea doi constructori astfel:
		- cu două argumente (partea reala și imaginară)
		- fără argumente
	- Metodele necesare sunt: adunare, înmulțire, “equals”.
	- Exemplu cod:

	``` c++
	Complex *c1 = new Complex(1,2);
	Complex *c2 = new Complex(2,3);
	cout << c1->aduna(c2); // afiseaza „3.0 + 5.0i”
	cout << c1->equals(c2)); // afiseaza „false”
	```

5. Într-un magazin există clienți și case de marcat. Un client este caracterizat de un nume, de un id (‚F’ pentru client fidel și ‚R’ pentru client obișnuit) și de o sumă maximă de bani pe care o poate cheltui. Fiecare client poate să adauge produse de pe raft sau să renunțe la produse deja adăugate (un produs este caracterizat de nume și pret). De asemenea, un client poate să își incarce produsele dintr-o listă de cumparaturi.
Fiecare casă de marcat are câte o coadă de clienți. Casa de marcat are posibilitatea de a primi un client în coada sau de a servi un client. În cadrul procesului de servire client se va calcula și afișa suma de plată pentru produsele selectate de client. În cazul depășirii sumei maxime se va afișa un mesaj corespunzător. Pentu clienții fideli se va aplica o reducere de 10%. Există posibilitatea ca o casă să fie închisă. În acest caz, clienții se vor muta la o altă casă nou creată sau cu o coada de asteptare deja creată.
Exemplu cod:
``` c++
void main()
{
	Client C1(„client1”, ’R’), C2(„client2”, ’F’), C3, C4(„client4” „lista.txt”), C5(„client5”, „lista1.txt”), C6(„client6”, „lista2.txt”);
	
	C1.addProdus(„apa”,3.5,2); //nume, pret, numar produse
	C2.addProdus(„suc”,2,5);
	C2.removeProdus(„suc”,1); //nume, numar produse
	
	Casa *K1, *K2, *K3;
	K1 = new Casa;
	K2 = new Casa(C1);
	K2->add(C2);
	K2->add(C3);
	K1->add(C4);
	K1->add(C5);
	K1->Show(); //afiseaza coada de clienti;
	K2->Show();
	K2->serveste();
	K1->serveste();
	K2->copy(K1);
	K2->Show();
	delete K1;
	K2->serveste();
	K3 = new Casa(K2);
	delete K2;
	K3->serveste();
	K3->serveste();
}
```
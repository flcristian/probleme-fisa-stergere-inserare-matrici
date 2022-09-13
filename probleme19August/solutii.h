#include "functii.h"

// Se consideră o matrice pătratică A=(ai,j)de ordin n, 
// elementele sale fiind cifre în baza 10. Pentru fiecare 
// element ai,j al matricei definim drumul de la elementul
// a1,1 la elementul ai,j ca fiind format din elementele: a1,1,
// a2,1, …, ai,1, ai,2, ai,3, …, ai,j. Pentru fiecare element 
// ai,j al matricei, se cere să se calculeze suma produselor 
// oricăror două elemente situate pe drumul de la elementul 
// a1,1 la elementul ai,j.

void solutiepb1() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	int pos1, pos2;
	cout << endl << "Introduceti randul : ";
	cin >> pos1;
	cout << "Introduceti coloana : ";
	cin >> pos2;
	cout << endl << sumaProdDistanta(x, m, n, pos1 - 1, pos2 - 1);
}

// *** STERGERI ***
// a) Stergeti linia si coloana tuturor elementelor ce au
// exact 3 cifre egale intre ele.
// b) Stergeti linia si coloana pe care se afla al doilea 
// numar prim din matrice. Daca matricea nu contine
// cel putin 2 numere prime, se va afisa mesajul
// "NU EXISTA".
// c) Stergeti linia ce are cel mai rar cifra k in componenta
// elementelor (k citit de la tastatura)
// d) Sa se stearga linia si coloana elementului cu frecventa
// maxima.
// e) Stergeti toate liniile ce nu au elementele ordonate
// (crescator sau descrescator)
// f) Realizati frecventa fiecarei cifre in parte. Stergeti
// toate elementele ce au in componenta cifra cu cea
// mai mare frecventa. Daca exista mai multe cifre in
// aceasta situatie, va fi considerata cifra maxima.

// STERGERI - a
// Stergeti linia si coloana tuturor elementelor ce au
// exact 3 cifre egale intre ele.

void solutiepbStergeriA() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	stergereLiniiColoanePbStergeriA(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// STERGERI - b
// Stergeti linia si coloana pe care se afla al doilea 
// numar prim din matrice. Daca matricea nu contine
// cel putin 2 numere prime, se va afisa mesajul
// "NU EXISTA".

void solutiepbStergeriB() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	if (stergereLinieColoanaAl2LeaPrim(x, m, n) == 2) {
		cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
		afisareMatrice(x, m, n);
	}
	else {
		cout << endl << "Matricea nu are doua numere prime." << endl;
	}
}

// STERGERI - c
// Stergeti linia ce are cel mai rar cifra k in componenta
// elementelor (k citit de la tastatura)

void solutiepbStergeriC() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	int k = 0;
	cout << "Introduceti k : ";
	cin >> k;
	stergereLinieMaxAparitiiK(x, m, n, k);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// STERGERI - D
// Sa se stearga linia si coloana elementului cu frecventa
// maxima.

void solutiepbStergeriD() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	stergereLiniiColoaneMaxFrec(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// STERGERI - E
// Stergeti toate liniile ce nu au elementele ordonate
// (crescator sau descrescator)

void solutiepbStergeriE() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	stergereLiniiNeordonate(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// STERGERI - F
// Realizati frecventa fiecarei cifre in parte. Stergeti
// toate elementele ce au in componenta cifra cu cea
// mai mare frecventa. Daca exista mai multe cifre in
// aceasta situatie, va fi considerata cifra maxima.

void solutiepbStergeriF() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	stergereLinieCifraMaxFreq(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// *** INSERARI ***
// a) Inserati dupa a doua coloana ce contine cel putin un patrat perfect,
// rasturnatul fiecarui element din acesta. In caz ca nu avem o astfel
// de coloana, se va afisa mesajul "NU".
// b) Sa se insereze dupa linia cu cele mai multe elemente pare,
// dublul ei.
// c) Sa se insereze inainte de coloana pe care se afla cele mai multe
// elemente de maxim, cifra minima dintre toate elementele vectorului.
// Daca exista mai multe coloane cu acelasi numar de aparitii
// se va lua in considerare ultima coloana.
// d) Inserati dupa fiecare coloana ce este formata din elemente in care
// fiecare cifra (0-9) apare cel putin o data, cifra de control a fiecarui element.
// e) Inserati dupa linia pe care se gaseste primul element palindrom ce are intre
// 3 si 5 divizori proprii, dublul ei.
// f) Inserati dupa prima coloana ce are toate elementele prime intre ele cu pozitia
// liniei pe care stau, cifra de control a elementelor.

// INSERARI - A
// Inserati dupa a doua coloana ce contine cel putin un patrat perfect,
// rasturnatul fiecarui element din acesta. In caz ca nu avem o astfel
// de coloana, se va afisa mesajul "NU".

void solutiepbInserariA() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	int c = inserarePBInserareA(x, m, n);
	if (c == 2) {
		cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
		afisareMatrice(x, m, n);
	}
	else {
		cout << endl << "Matricea nu contine doua coloane care sa aiba patrate perfecte." << endl;
	}
}

// INSERARI - B
// Sa se insereze dupa linia cu cele mai multe elemente pare,
// dublul ei.

void solutiepbInserariB() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	inserarePBInserareB(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// INSERARI - C
// Sa se insereze inainte de coloana pe care se afla cele mai multe
// elemente de maxim, cifra minima dintre toate elementele vectorului.
// Daca exista mai multe coloane cu acelasi numar de aparitii
// se va lua in considerare ultima coloana.

void solutiepbInserariC() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	inserarePBInserareC(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// INSERARI - D
// Inserati dupa fiecare coloana ce este formata din elemente in care
// fiecare cifra (0-9) apare cel putin o data, cifra de control a fiecarui element.

void solutiepbInserariD() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	inserarePBInserareD(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// INSERARI - E
// Inserati dupa linia pe care se gaseste primul element palindrom ce are intre
// 3 si 5 divizori proprii, dublul ei.

void solutiepbInserariE() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	inserarePBInserareE(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// INSERARI - F
// Inserati dupa prima coloana ce are toate elementele prime intre ele cu pozitia
// liniei pe care stau, cifra de control a elementelor.

void solutiepbInserariF() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	inserarePBInserareF(x, m, n);
	afisareMatrice(x, m, n);
}

// *** INTERSCHIMBARI ***
// a) Inserati prima linie ce are elementele in ordine crescatoare cu
// urmoatoarea linie. In cazul in care nu exista, sortati crescator
// prima linie si interschimbati-o cu ultima.
// b) Interschimbati linia pe care se afla minimul cu linia pe care
// se afla maximul. Daca elementul minim si maxim se afla pe
// aceeasi linie, afisati mesajul: "Nu putem interschimba!".
// c) Interschimbati intre ele liniile a.i. prima coloana
// sa aiba elementele in ordine crescatoare.

// INTERSCHIMBARI - A
// Inserati prima linie ce are elementele in ordine crescatoare cu
// urmoatoarea linie. In cazul in care nu exista, sortati crescator
// prima linie si interschimbati-o cu ultima.

void solutiepbInterschimbariA() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	interschimbarePbA(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// INTERSCHIMBARI - B
// Interschimbati linia pe care se afla minimul cu linia pe care
// se afla maximul. Daca elementul minim si maxim se afla pe
// aceeasi linie, afisati mesajul: "Nu putem interschimba!".

void solutiepbInterschimbariB() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	if (interschimbarePbB(x, m, n) == 0) {
		cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
		afisareMatrice(x, m, n);
	}
}

// INTERSCHIMBARI - C
// Interschimbati intre ele liniile a.i. prima coloana
// sa aiba elementele in ordine crescatoare.

void solutiepbInterschimbariC() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	bubbleSortColoanePbInterschimbareC(x, m, n);
	cout << endl << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}
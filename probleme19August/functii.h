#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Citire matrice din fisier.

void citireFisier(int x[100][100], int& m, int& n) {
	ifstream f("numere.txt");
	f >> m, f >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			f >> x[i][j];
		}
	}
}

// Afisare matrice.

void afisareMatrice(int x[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		cout << "{";
		int c = n;
		for (int j = 0; j < n; j++) {
			cout << x[i][j];
			if (c > 1) {
				cout << ", ";
				c--;
			}
			else {
				cout << "}" << endl;
			}
		}
	}
}

// Afisare vector.

void afisareVector(int x[], int d) {
	cout << "x[" << d << "] = {";
	int c = d;
	for (int i = 0; i < d; i++) {
		cout << x[i];
		if (c > 1) {
			cout << ", ";
			c--;
		}
		else {
			cout << "}" << endl;
		}
	}
}

// Suma produselor oricaror elementelor situate pana la pozitia dorita.

int sumaProdDistanta(int x[100][100], int m, int n, int pos1, int pos2) {
	int y[100];
	int k = 0, s = 0;
	for (int i = 0; i <= pos1; i++) {
		y[k] = x[i][0];
		k++;
	}
	for (int j = 1; j <= pos2; j++) {
		y[k] = x[pos1][j];
		k++;
	}
	afisareVector(y, k);
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			s += y[i] * y[j];
		}
	}
	return s;
}

// Stergere linie din matrice.

void stergereLinieMatrice(int x[100][100], int& m, int n, int linie) {
	for (int i = linie; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = x[i + 1][j];
		}
	}
	m--;
}

// Stergere coloana din matrice.

void stergereColoanaMatrice(int x[100][100], int m, int& n, int coloana) {
	for (int j = coloana; j < n - 1; j++) {
		for (int i = 0; i < m; i++) {
			x[i][j] = x[i][j + 1];
		}
	}
	n--;
}

// Inserare linie in matrice.

void inserareLinieMatrice(int x[100][100], int y[], int& m, int n, int linie) {
	m++;
	for (int i = m - 1; i > linie; i--) {
		for (int j = 0; j < n; j++) {
			x[i][j] = x[i - 1][j];
		}
	}
	for (int j = 0; j < n; j++) {
		x[linie][j] = y[j];
	}
}

// Inserare coloana in matrice.

void inserareColoanaMatrice(int x[100][100], int y[], int m, int& n, int coloana) {
	n++;
	for (int j = n - 1; j > coloana; j--) {
		for (int i = 0; i < m; i++) {
			x[i][j] = x[i][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		x[i][coloana] = y[i];
	}
}

// Interschimbare coloane in matrice.

void interschimbareLiniiMatrice(int x[100][100], int m, int n, int linie1, int linie2) {
	int y[100];
	for (int j = 0; j < n; j++) {
		y[j] = x[linie1][j];
	}
	for (int j = 0; j < n; j++) {
		x[linie1][j] = x[linie2][j];
	}
	for (int j = 0; j < n; j++) {
		x[linie2][j] = y[j];
	}
}

// Interschimbare coloane in matrice.

void interschimbareColoaneMatrice(int x[100][100], int m, int n, int coloana1, int coloana2) {
	int y[100];
	for (int i = 0; i < m; i++) {
		y[i] = x[i][coloana1];
	}
	for (int i = 0; i < m; i++) {
		x[i][coloana1] = x[i][coloana2];
	}
	for (int i = 0; i < m; i++) {
		x[i][coloana2] = y[i];
	}
}

// Are numarul 3 cifre egale intre ele?

bool are3CifreEgaleIntreEle(int n) {
	if (n == 0) {
		return false;
	}
	int c = 1, old = n % 10;
	n /= 10;
	while (n != 0) {
		if (c == 3) {
			return false;
		}
		if (old != n % 10) {
			return false;
		}
		n /= 10;
		c++;
	}
	if (c != 3) {
		return false;
	}
	return true;
}

// Stergere linile si coloanele numerelor
// ce au 3 cifre egale intre ele.

void stergereLiniiColoanePbStergeriA(int x[100][100], int& m, int& n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (are3CifreEgaleIntreEle(x[i][j])) {
				stergereLinieMatrice(x, m, n, i);
				stergereColoanaMatrice(x, m, n, j);
				i--, j--;
			}
		}
	}
}

// Cati divizori are numarul?

int countDivizori(int n) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			c++;
		}
	}
	return c;
}

// Este prim numarul?

bool estePrim(int n) {
	if (countDivizori(n) == 2) {
		return true;
	}
	return false;
}

// Stergerea linii si coloanei celui de-al doilea numar prim.

int stergereLinieColoanaAl2LeaPrim(int x[100][100], int& m, int& n) {
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (estePrim(x[i][j])) {
				c++;
			}
			if (c == 2) {
				stergereLinieMatrice(x, m, n, i);
				stergereColoanaMatrice(x, m, n, j);
				i--, j--;
				return 2;
			}
		}
	}
	return c;
}

// De cate ori apare cifra in numar.

int countAparitiiCifraNumar(int n, int cifra) {
	int c = 0;
	while (n != 0) {
		if (n % 10 == cifra) {
			c++;
		}
		n /= 10;
	}
	return c;
}

// De cate ori apare cifra pe aceasta linie?

int countAparitiiCifraLinie(int x[100][100], int n, int linie, int k) {
	int c = 0;
	for (int j = 0; j < n; j++) {
		c += countAparitiiCifraNumar(x[linie][j], k);
	}
	return c;
}

// Stergerea liniei unde apare k de max ori.

void stergereLinieMaxAparitiiK(int x[100][100], int& m, int n, int k) {
	int max = 0, linie = 0;
	for (int i = 0; i < m; i++) {
		int count = countAparitiiCifraLinie(x, n, i, k);
		if (count > max) {
			max = count;
			linie = i;
		}
	}
	stergereLinieMatrice(x, m, n, linie);
}

// Atribuire 0 la valoriile vectorului frecventa.

void atribuire0(int x[], int d) {
	for (int i = 0; i < d; i++) {
		x[i] = 0;
	}
}

// Afisare frecventa.

void afisareFrecventa(int x[], int d) {
	for (int i = 0; i < d; i++) {
		if (x[i] > 0) {
			cout << "Numarul " << i << " apare de " << x[i] << " ori." << endl;
		}
	}
}

// Care este numarul maxim al matricei?

int maxMatrice(int x[100][100], int m, int n) {
	int max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] > max) {
				max = x[i][j];
			}
		}
	}
	return max;
}

// Frecventa elementelor (NUMERE MAXIM PANA LA 10000);

void frecventaElementeMatrice(int x[100][100], int frecventa[], int& d, int m, int n) {
	d = maxMatrice(x, m, n) + 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			frecventa[x[i][j]]++;
		}
	}
}

// Care este numarul cu frecventa maxima?

int numarMaxFrecventa(int x[], int d) {
	int maxFrec = 0, maxNumar = 0;
	for (int i = d; i > -1; i--) {
		if (x[i] > maxFrec) {
			maxNumar = i;
			maxFrec = x[i];
		}
	}
	return maxNumar;
}

// Eliminare linii si coloane unde 
// se gaseste numarul cu cea mai mare frecventa.

void stergereLiniiColoaneMaxFrec(int x[100][100], int& m, int& n) {
	int frecventa[10000];
	int d = 10000;
	atribuire0(frecventa, d);
	frecventaElementeMatrice(x, frecventa, d, m, n);
	int numar = numarMaxFrecventa(frecventa, d);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] == numar) {
				stergereLinieMatrice(x, m, n, i);
				stergereColoanaMatrice(x, m, n, j);
				i--, j--;
			}
		}
	}
}

// Stergere linii neordonate.

void stergereLiniiNeordonate(int x[100][100], int& m, int n) {
	for (int i = 0; i < m; i++) {
		int c = 0, r = 0;
		for (int j = 0; j < n - 1; j++) {
			if (x[i][j] >= x[i][j + 1]) {
				c++;
			}
		}
		if (c == n - 1) {
			r++;
		}
		c = 0;
		for (int j = 0; j < n - 1; j++) {
			if (x[i][j] <= x[i][j + 1]) {
				c++;
			}
		}
		if (c == n - 1) {
			r++;
		}
		if (r == 0) {
			stergereLinieMatrice(x, m, n, i);
			i--;
		}
	}
}

// Contine cifra numarul?

bool contineCifraNr(int n, int c) {
	while (n != 0) {
		if (n % 10 == c) {
			return true;
		}
		n /= 10;
	}
	return false;
}

// Frecventa cifrelor din matrice.

void frecventaCifreMatrice(int x[100][100], int m, int n, int frecventa[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int n = x[i][j];
			while (n != 0) {
				frecventa[n % 10]++;
				n /= 10;
			}
		}
	}
}

// Stergere linie element ce are in componenta cifra cu cea mai mare frecventa.

void stergereLinieCifraMaxFreq(int x[100][100], int& m, int n) {
	int frecventa[10];
	atribuire0(frecventa, 10);
	frecventaCifreMatrice(x, m, n, frecventa);
	int c = numarMaxFrecventa(frecventa, 10);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (contineCifraNr(x[i][j], c)) {
				stergereLinieMatrice(x, m, n, i);
				i--;
				j = -1;
			}
		}
	}
}

// Este patrat perfect?

bool estePatratPerfect(int n) {
	double x = sqrt(n);
	if (x == ceil(x)) {
		return true;
	}
	return false;
}

// Rasturnatul numarului.

int rasturnat(int n) {
	int r = 0;
	while (n != 0) {
		r = r * 10 + (n % 10);
		n /= 10;
	}
	return r;
}

// Inserare coloana rasturnata celei dinainte.

void inserareRasturnataPrecedenta(int x[100][100], int m, int& n, int p) {
	for (int j = n; j > p; j--) {
		if (j == p + 1) {
			for (int i = 0; i < m; i++) {
				x[i][p + 1] = rasturnat(x[i][p]);
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				x[i][j] = x[i][j - 1];
			}
		}
	}
	n++;
}

// Inserare pentru problema A - INSERARI

int inserarePBInserareA(int x[100][100], int m, int& n) {
	int c = 0;
	for (int j = 0; j < n, c != 2; j++) {
		int countPP = 0;
		for (int i = 0; i < m; i++) {
			if (estePatratPerfect(x[i][j])) {
				countPP++;
			}
		}
		if (countPP > 0) {
			c++;
		}
		if (c == 2) {
			inserareRasturnataPrecedenta(x, m, n, j);
		}
	}
	return c;
}

// Inserare dupa linia cu cele mai multe numere pare dublul ei.

void inserareDublulLiniei(int x[100][100], int& m, int n, int p) {
	for (int i = m; i > p; i--) {
		if (i == p + 1) {
			for (int j = 0; j < n; j++) {
				x[i][j] = x[i - 1][j] * 2;
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				x[i][j] = x[i - 1][j];
			}
		}
	}
	m++;
}

// Inserare pentru problema B - INSERARI

void inserarePBInserareB(int x[100][100], int& m, int n) {
	int maxPare = 0, linieMaxPare = 0;
	for (int i = 0; i < m; i++) {
		int countPare = 0;
		for (int j = 0; j < n; j++) {
			if (x[i][j] % 2 == 0) {
				countPare++;
			}
		}
		if (countPare > maxPare) {
			maxPare = countPare;
			linieMaxPare = i;
		}
	}
	inserareDublulLiniei(x, m, n, linieMaxPare);
}

// Algoritmul de inserare pentru problema C - INSERARI

void inserareC(int x[100][100], int m, int& n, int p, int y) {
	for (int j = n; j > p - 1; j--) {
		if (j == p) {
			for (int i = 0; i < m; i++) {
				x[i][j] = y;
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				x[i][j] = x[i][j - 1];
			}
		}
	}
	n++;
}

// Inserare pentru problema C - INSERARI

void inserarePBInserareC(int x[100][100], int m, int& n) {
	int max = 0, min = x[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] > max) {
				max = x[i][j];
			}
			if (x[i][j] < min) {
				min = x[i][j];
			}
		}
	}
	int maxCount = 0, coloanaMaxCount = 0;
	for (int j = 0; j < n; j++) {
		int count = 0;
		for (int i = 0; i < m; i++) {
			if (x[i][j] == max) {
				count++;
			}
		}
		if (count > maxCount) {
			maxCount = count;
			coloanaMaxCount = j;
		}
	}
	inserareC(x, m, n, coloanaMaxCount, min);
}

// Adaugare cifre la frecventa.

void adaugareCifreFrecventa(int n, int frecventa[]) {
	while (n != 0) {
		frecventa[n % 10]++;
		n /= 10;
	}
}

// Cifra de control

int cifraControl(int n) {
	while ((n / 10) != 0) {
		int s = 0;
		while (n != 0) {
			s += n % 10;
			n /= 10;
		}
		n = s;
	}
	return n;
}

// Inserare cifra de control dupa coloana.

void inserareCifraControlColoana(int x[100][100], int m, int& n, int p) {
	for (int j = n; j > p; j--) {
		if (j == p + 1) {
			for (int i = 0; i < m; i++) {
				x[i][j] = cifraControl(x[i][j - 1]);
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				x[i][j] = x[i][j - 1];
			}
		}
	}
	n++;
}

// Este palindrom?

bool estePalindrom(int n) {
	if (n == rasturnat(n)) {
		return true;
	}
	return false;
}

// Inserare pentru problema D - INSERARI

void inserarePBInserareD(int x[100][100], int m, int& n) {
	for (int j = 0; j < n; j++) {
		int frecventa[100];
		atribuire0(frecventa, 10);
		for (int i = 0; i < m; i++) {
			adaugareCifreFrecventa(x[i][j], frecventa);
		}
		int c = 0;
		for (int i = 0; i < 10; i++) {
			if (frecventa[i] == 0) {
				c++;
			}
		}
		if (c == 0) {
			inserareCifraControlColoana(x, m, n, j);
		}
	}
}

// Inserare pentru problema E - INSERARI

void inserarePBInserareE(int x[100][100], int& m, int n) {
	int y = 0, c = 0;
	for (int i = 0; i < m && c == 0; i++) {
		for (int j = 0; j < n && c == 0; j++) {
			int numar = x[i][j];
			if (estePalindrom(numar) && countDivizori(numar) >= 3 && countDivizori(numar) <= 5){
				c++;
				y = i;
			}
		}
	}
	if (c > 0) {
		inserareDublulLiniei(x, m, n, y);
	}
}

// Cel mai mare divizor comun.

int cmmdc(int n, int m) {
	if (n > m) {
		int r = n;
		n = m;
		m = r;
	}

	for (int i = n; i > 0; i--) {
		if (n % i == 0 && m % i == 0) {
			return i;
		}
	}
}

// Sunt prime intre ele?

bool primeIntreEle(int n, int m) {
	int c = cmmdc(n, m);
	if (c == 1) {
		return true;
	}
	return false;
}

// Inserare coloana cu cifrele de control ale numerelor de pe coloana precedenta.

void inserareColoanaCifraControl(int x[100][100], int m, int& n, int y) {
	n++;
	for (int j = n; j > y; j--) {
		if (j == y + 1) {
			for (int i = 0; i < m; i++) {
				x[i][j] = cifraControl(x[i][y]);
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				x[i][j] = x[i][j - 1];
			}
		}
	}
}

// Inserare pentru problema Inserari F

void inserarePBInserareF(int x[100][100], int m, int& n) {
	int y = -1, c = 0;
	for (int j = 0; j < n && c == 0; j++) {
		int count = 0;
		for (int i = 0; i < m && c == 0; i++) {
			if (primeIntreEle(i + 1, x[i][j])) {
				count++;
			}
			cout << endl;
		}
		if (count == m) {
			y = j;
			c++;
		}
	}
	if (c > 0) {
		inserareColoanaCifraControl(x, m, n, y);
	}
}

// Interschimbare 2 linii.

void interschimbareLinii(int x[100][100], int m, int n, int l1, int l2) {
	int y[100];
	for (int j = 0; j < n; j++) {
		y[j] = x[l1][j];
	}
	for (int j = 0; j < n; j++) {
		x[l1][j] = x[l2][j];
	}
	for (int j = 0; j < n; j++) {
		x[l2][j] = y[j];
	}
}

// Sortare linie matrice.

void sortareLinieMatrice(int x[100][100], int m, int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[m][i] > x[m][i + 1]) {
				int r = x[m][i];
				x[m][i] = x[m][i + 1];
				x[m][i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

// Interschimbare pentru problema A.

void interschimbarePbA(int x[100][100], int m, int n) {
	int y = -1, z = -1, c = 0;
	for (int i = 0; i < m && c < 2; i++) {
		int count = 0;
		for (int j = 0; j < n - 1; j++) {
			if (x[i][j] < x[i][j + 1]) {
				count++;
			}
		}
		if (count == n - 1) {
			if (c == 0) {
				y = i;
				c++;
			}
			else {
				z = i;
				c++;
			}
		}
	}
	if (c < 2) {
		sortareLinieMatrice(x, 0, n);
		interschimbareLinii(x, m, n, 0, n - 1);
	}
	else {
		interschimbareLinii(x, m, n, y, z);
	}
}

// Linia minimului matricei.

int linieMinMatrice(int x[100][100], int m, int n) {
	int minim = x[0][0], linie = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] < minim) {
				linie = i;
				minim = x[i][j];
			}
		}
	}
	return linie;
}

// Linia maximului matricei.

int linieMaxMatrice(int x[100][100], int m, int n) {
	int maxim = x[0][0], linie = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i][j] > maxim) {
				linie = i;
				maxim = x[i][j];
			}
		}
	}
	return linie;
}

// Interschimbare pentru problema B.

int interschimbarePbB(int x[100][100], int m, int n) {
	int l1 = linieMinMatrice(x, m, n), l2 = linieMaxMatrice(x, m, n);
	if (l1 == l2) {
		cout << endl << "Nu putem interschimba!" << endl;
		return 1;
	}
	else {
		interschimbareLinii(x, m, n, l1, l2);
	}
	return 0;
}

// Bubble sort coloane astfel incat prima linie sa aiba elementele in ordine crescatoarea.

void bubbleSortColoanePbInterschimbareC(int x[100][100], int m, int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[0][i] > x[0][i + 1]) {
				interschimbareColoaneMatrice(x, m, n, i, i + 1);
				flag = false;
			}
		}
	} while (flag == false);
}

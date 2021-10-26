// zad1.cpp : 
// Napisati funkciju koja raèuna najveæi i najmanji broj u nizu od n prirodnih brojeva. 
// Funkcija vraæa tražene brojeve pomoæu referenci

#include <iostream>
using namespace std;

void array_min_max (int n, int niz[], int& m, int& M)
{
	m = M = niz[0];
	for (int i = 0; i < n; i++) {
		if (niz[i] > M) {
			M = niz[i];
		}
		else if (niz[i] < m) {
			m = niz[i];
		}
	}
}

int main ()
{
	int n = 5, minimum, maximum;
	int niz[] = { -1,3,-4,5,0 };
	array_min_max(n, niz, minimum, maximum);
	cout << minimum << '\n' << maximum;
}

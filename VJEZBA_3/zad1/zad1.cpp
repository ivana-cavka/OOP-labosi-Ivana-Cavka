// zad1.cpp : 
/* Napisati funkcije za unos i ispis vektora brojeva. 
Prototipove funkcija staviti u .hpp datoteke, a implementaciju u.cpp datoteke.
Za unos vektora napisati dvije funkcije :
• funkcija èiji su parametri referenca na vektor i broj elemenata vektora,
• funkcija èiji su parametri referenca na vektor i granice intervala u kojem trebaju biti elementi vektora.
Elementi vektora se unose u funkciji, sve dok se ne unese broj koji nije u danom intervalu */

#include "zad1.hpp"

int main()
{
	vector<int> test;
	vector_in(test, -4, 10);
	vector_out(test, test.size());
}

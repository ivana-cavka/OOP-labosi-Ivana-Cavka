// zad3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Napisati iterativnu funkciju za traženje najveæeg i najmanjeg broja u nizu.

#include <iostream>
using namespace std;

void array_min_max(int n, int niz[], int& m, int& M)
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
int main()
{
    int n = 5, minimum, maximum;
    int niz[] = { -1,3,-4,5,0 };
    array_min_max(n, niz, minimum, maximum);
    cout << minimum << '\n' << maximum;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

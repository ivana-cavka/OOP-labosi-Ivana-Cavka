//zad1.cpp : Napišite template funkciju za sortiranje niza. Napišite specijalizaciju te
//funkcije za niz char - ova u kojoj neæe biti razlike izmeðu malih i velikih slova.
//Napomena: Odvojite suèelje i implementaciju u razlièite.cpp i.h datoteke

#include <iostream>
#include "template.hpp"
using namespace std;

int main()
{
    int niz1[] = { 1,2,3,4,9,8,7,6,5,4 };
    sorting(niz1, 10);
    for (int i = 0; i < 10; i++)
        cout << niz1[i] << " ";
    char niz2[] = { 'A', 'b', 'E', 'K', 'n', 'y', 'X', 'z', 'o', 'H' };
    sorting(niz2,10);
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << niz2[i] << " ";
}

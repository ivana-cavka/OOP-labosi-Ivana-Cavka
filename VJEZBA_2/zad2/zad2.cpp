// zad2.cpp : 
// Napisati funkciju koja vra�a referencu na neki element niza.
// Koriste�i povratnu vrijednost funkcije kao lvalue uve�ajte i-ti element niza za jedan.

#include <iostream>
using namespace std;

int& point_to_element (int array[], int x)
{
    int& n = array[x - 1];
    return n;
}

int main ()
{
    int i, niz[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "i = ";
    cin >> i;
    point_to_element(niz, i) ++;  //lvalue
    cout << niz[i];
}


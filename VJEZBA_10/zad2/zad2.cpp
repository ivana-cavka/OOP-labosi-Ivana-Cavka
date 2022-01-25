//zad2.cpp : Napišite template klasu Stack. Implementirajte funkcije èlanove za operacije push, pop i is_empty.
//Napomena: Odvojite suèelje i implementaciju u razlièite.cpp i.h datoteke

#include <iostream>
#include "template.hpp"
using namespace std;

int main()
{
    Stack<char> test;
    cout << test.is_empty() << endl << endl;
    test.push('a');
    test.push('b');
    int i = 0;
    while (!test.is_empty()) {
        cout << test.getStack()[i];
        i++;
    }
    test.pop();
    cout << endl ;
    i = 0;
    while (!test.is_empty()) {
        cout << test.getStack()[i];
        i++;
    }
}

//zad2.cpp : Napi�ite template klasu Stack. Implementirajte funkcije �lanove za operacije push, pop i is_empty.
//Napomena: Odvojite su�elje i implementaciju u razli�ite.cpp i.h datoteke

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

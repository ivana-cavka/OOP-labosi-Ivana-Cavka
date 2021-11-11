// zad4.cpp : 
//Napisati funkciju u za uklanjanje elementa iz vektora sa što manje operacija. Poredak elemenata u vektoru nije bitan

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void remove_from_vector(vector<int>& v, vector<int>::iterator it) {
    if (it < v.end()) {
        if (it != v.end() - 1) {
            *it = *(v.end() - 1);
        }
        v.pop_back();
    }
    //it = v.erase(it);
    //vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
}

void vector_out(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> test;
    for (unsigned int i = 0; i < 10; i++) {
        test.push_back(rand() % 10);
    }
    vector_out(test, test.size());
    remove_from_vector(test, test.begin() + 3);
    vector_out(test, test.size());
}

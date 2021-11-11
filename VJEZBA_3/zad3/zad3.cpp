// zad3.cpp : 
//Koristeæi STL funkcije sortirajte vektor, ubacite 0 ispred najmanjeg elementa, 
//te sumu svih elemenata iza najveæeg elementa.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <time.h>
using namespace std;

void inject_0(vector<int>& v) {
    int m = *min_element(v.begin(), v.end());
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        if (*it == m) {
            it = v.insert(it, 0);
            return;
        }
    }
}

void inject_max(vector<int>& v) {
    int sum = 0;
    int M = *max_element(v.begin(), v.end());
    vector<int>::iterator it;
    accumulate(v.begin(), v.end(), sum);
    for (it = v.begin(); it != v.end(); ++it) {
        if (*it == M && it != (v.end() - 1)) {
            it = v.insert(it + 1, sum);
            return;
        }
        else if (*it == M && it == (v.end() - 1)) {
            v.push_back(*it);
            return;
        }
    }
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
    inject_0(test);
    inject_max(test);
    vector_out(test, test.size());
}


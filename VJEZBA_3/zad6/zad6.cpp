// zad6.cpp : 
//Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova,
//svaki string preokrene te sortira vektor po preokrenutim stringovima.

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> sort_new_strings(int n) {
    string str;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cout << "new line: ";
        getline(cin, str);
        reverse(str.begin(),str.end()); 
        v.push_back(str);
    }
    sort(v.begin(),v.end());
    return v;
}

void vector_out(vector<string>& v) {
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
}

int main()
{
    vector<string> test = sort_new_strings(5);
    vector_out(test);
}

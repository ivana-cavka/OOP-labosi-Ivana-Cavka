// zad5.cpp : 
//Napisati funkciju koja broji koliko pojavljivanja danog podstringa ima u stringu koristeæi funkcije standardne biblioteke.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int count_substring(string s, string& sub) {
    int flag = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (s.compare(s.size() - (s.size() - i), sub.size(), sub) == 0) {
            flag++;
        }
    }
    return flag;
}

int main()
{
    string str = "helloblahello blabla he bl llo a";
    string substr = "hello";
    cout << "string >>" << substr << "<< is repeated " << count_substring(str, substr) << " times";
}

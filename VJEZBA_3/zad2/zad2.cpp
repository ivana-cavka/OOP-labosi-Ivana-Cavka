// zad2.cpp : 
//Koristeæi funkcije iz prvog zadatka unijeti dva vektora i formirati novi vektor koji
//se sastoji od elemenata iz prvog vektora koji nisu u drugom vektoru

#include "zad1.hpp"
#include <algorithm>

vector<int> vector_a_minus_b(vector<int>& a, vector<int>& b) {
	vector<int> rez;
	unsigned int flag;
	for (unsigned int i = 0; i < a.size(); i++) {
		if (find(b.begin(),b.end(),a.at(i)) == b.end()) {
			rez.push_back(a.at(i));
		}
	}
	return rez;
}

int main()
{
	vector<int> test1, test2, test3;
	vector_in(test1, -10, 10);
	vector_out(test1, test1.size());
	vector_in(test2, -10, 10);
	vector_out(test2, test2.size());
	test3 = vector_a_minus_b(test1, test2);
	vector_out(test3,test3.size());
}

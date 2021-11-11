#include <iostream>
#include <vector>
using namespace std;

void vector_out(vector<int>& v, int n);
void vector_in(vector<int>& v, int a, int b);

void vector_out(vector<int>& v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
}

void vector_in(vector<int>& v, int a, int b) {
	int x;
	cout << endl << "new item: ";
	cin >> x;
	if (x <= a && x >= b || x <= b && x >= a) {
		v.push_back(x);
		vector_in(v, a, b);
	}
	else {
		return;
	}
}

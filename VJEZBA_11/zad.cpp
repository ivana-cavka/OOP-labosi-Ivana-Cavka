/*Napisati funkciju koja iz datoteke numbers.txt èita prirodne brojeve. 
Koristeæi standardne algoritme:
1. baci iznimku ako ne postoji datoteka,
2. napuni vektor brojevima iz datoteke,
3. prebroji sve brojeve vece od 500,
4. naði minimalni i maximalni element,
5. iz vektora izbaci brojeve manje od 300,
6. preostale brojeve sortiraj silazno.*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> readNumbers() {
	ifstream file("numbers.txt");
	vector<int> v;
	try {
		istream_iterator<int> is(file), end;
		copy(is, end, back_inserter(v));
		return v;
	}
	catch(ios_base::failure& e) {
		if (!file.eof()) {
			throw ios_base::failure(e.what());
		}
	}
}

int countNumbersOver500(vector<int>& v) {
	int counter = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)	{
		if ((*it) > 500) {
			counter++;
		}
	}
	return counter;
}

void minAndMax(int& min, int& max, vector<int>& v) {
	min = max = *v.begin();
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)	{
		if ((*it) > max) {
			max = *it;
		}
		if ((*it) < min) {
			min = *it;
		}
	}
}

void flushNumbersUnder300(vector<int>& v) {
	vector<int>::iterator it = v.begin();
	while(it != v.end()) {
		if ((*it) < 300) {
			v.erase(it);
		}
		else {
			it++;
		}
	}
}

void sortFromMaxToMin(vector<int>& v) {
	sort(v.begin(), v.end(), greater<int>());
}

void printNumbers(vector<int>& v) {
	cout << "Printing numbers: " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			cout << *it << "\t";
	}
}

int main()
{
	vector<int> numbers = readNumbers();
	printNumbers(numbers);
	int num = countNumbersOver500(numbers);
	cout << "There is " << num << " numbers over 500" << endl;
	int min, max;
	minAndMax(min, max, numbers);
	cout << "Min = " << min << " Max = " << max << endl;
	flushNumbersUnder300(numbers);
	printNumbers(numbers);
	sortFromMaxToMin(numbers);
	cout << endl << "Sorted: " << endl;
	printNumbers(numbers);
}


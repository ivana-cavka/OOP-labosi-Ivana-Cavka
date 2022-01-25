#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class TYPE> void sorting(TYPE array[], int arraySize) {
	sort(array, array + arraySize);
}

void ArrayToLower(char array[], int arraySize) {
	char temp;
	for (int i = 0; i < arraySize; i++) {
		temp=tolower(array[i]);
		array[i] = temp;
	}
}

template <> void sorting<char>(char array[], int arraySize) {
	ArrayToLower(array, arraySize);
	sort(array, array + arraySize);
}

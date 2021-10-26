// zad4.cpp : 
// Definirati strukturu koja opisuje vektor. Struktura se sastoji od niza int elemenata, logièke i fizièke velièine niza.
// Fizièka velièina je inicijalno init, a kada se ta velièina napuni vrijednostima, alocira se duplo. 
// Napisati funkcije vector_new, vector_delete, vector_push_back, vector_pop_back, vector_front, vector_back i vector_size.
// Funkcije su èlanovi strukture.

#include <iostream>
using namespace std;

struct vector {
    int* elements;
    int logical_size;
    int physical_size;

    void vector_delete();
    void vector_push_back();
    void vector_pop_back(vector* v);
    int& vector_front(vector* v);
    int& vector_back(vector* v);
    int vector_size(vector* v);
};

vector* vector_new () {
    vector* v = new vector;
    v->elements = NULL;
    v->logical_size = 0;
    v->physical_size = 0;  //init
    return v;
}

void vector_delete (vector* v) {
    delete[] v;
    //delete v;
}

void vector_push_back (vector* x, const int step) {
    if (x->physical_size == x->logical_size)
    {
        int* y = new int[x->physical_size * 2];
        memcpy(y, x->elements, x->logical_size); 
        x->physical_size *= 2;
        delete[] x->elements;
        x->elements = y;
    }
    x->elements[x->logical_size ++] = step;
}

void vector_pop_back (vector* v) {
    v->elements[v->logical_size --] = 0;
}

int& vector_front (vector* v) {
    return v->elements[0];
}

int& vector_back (vector* v) {
    return v->elements[v->logical_size - 1];
}

int vector_size (vector* v) {
    return v->logical_size;
}

int main ()
{
    vector* test = vector_new ();
    vector_push_back(test, 1);
    vector_push_back(test, 2);
    vector_push_back(test, 3);
    cout << "demo push back" << endl;
    for (int i = 0; i < test->logical_size; i++) {
        cout << "element[" << i + 1 << "] = " << test->elements[i] << endl;
    }
    cout << "front: " << vector_front(test);
    cout << endl << "back: " << vector_back(test);
    cout << endl << "logical size: " << vector_size(test) << " physical: " << test->physical_size << endl;
    vector_pop_back(test);
    cout << endl << "demo pop back" << endl;
    for (int i = 0; i < test->logical_size; i++) {
        cout << "element[" << i + 1 << "] = " << test->elements[i] << endl;
    }
    cout << endl << "logical size: " << vector_size(test) << " physical: " << test->physical_size << endl;
    vector_delete(test);
}

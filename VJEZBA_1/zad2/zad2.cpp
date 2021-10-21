// zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Definirati strukturu koja opisuje matricu. Napisati program za osnovne
operacije s matricama èiji su elementi decimalni brojevi (float). 
Program treba imati sljedeæe funkcije:
• funkciju za unos matrice mxn,
• funkciju za generiranje matrice mxn s elementima u rasponu [a,b],
• funkcije za zbrajanje, oduzimanje, množenje matrica,
• funkciju za trasponiranje matrice,
• funkciju za ispisivanje matrice. Elementi matrice se ispisuju na èetiri decimale, poravnati udesno.
*/
//int [][] matrix;
//int col;
//int row;
//struct + funkcije
//! pribacit u strukturu
//! random
//! pazit na { }

#include <iostream>
#include <time.h>
using namespace std;

struct matrix {
	int col;
	int row;
	float** M;

	void new_matrix(int rows, int cols, matrix A);
	void matrix_generate(matrix A);
	void input_matrix(matrix A);
	void matrix_add(matrix* A, matrix* B, matrix C);
	void matrix_multiply(matrix* A, matrix* B, matrix C);
	void matrix_subtract(matrix* A, matrix* B, matrix C);
	void matrix_transponse(matrix* A, matrix B);
	void print_matrix(matrix* A);
	void delete_matrix(matrix* A);
};

void matrix::new_matrix(int rows, int cols, matrix A) {
	A.row = rows;
	A.col = cols;
	A.M = new float* [rows];
	for (int i = 0; i < rows; i++) {
		A.M[i] = new float[cols];
	}
}

void matrix::matrix_generate(matrix A) {
	int rows, cols;
	float a, b;
	cout << "rows: ";
	cin >> rows;
	cout << "columns: ";
	cin >> cols;
	A.new_matrix(rows, cols, A);
	cout << "elements range: ";
	cin >> a;
	cout << " to ";
	cin >> b;
	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++) {
			A.M[i][j] = a + rand() % (int)(b - a + 1);
		}
	}
}

void matrix::input_matrix(matrix A) {
	int rows, cols;
	cout << "rows: ";
	cin >> rows;
	cout << "columns: ";
	cin >> cols;
	A.new_matrix(rows, cols, A);
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++) {
			cout << "[" << i << "]" << "[" << j << "] = ";
			cin >> A.M[i][j];
		}
}

void matrix::matrix_add(matrix* A, matrix* B, matrix C) {
	if ((A->row != B->row) || (A->col != B->col)) {
		cout << "matrices not compatible" << endl;
		return;
	}
	C.new_matrix(A->row, A->col, C);
	for (int i = 0; i < A->row; i++) {
		for (int j = 0; j < A->col; j++) {
			C.M[i][j] = A->M[i][j] + B->M[i][j];
		}
	}
}

void matrix::matrix_multiply(matrix* A, matrix* B, matrix C) {
	if (A->col != B->row) {
		cout << "matrices not compatible" << endl;
		return;
	}
	C.new_matrix(A->row, B->col, C);
	for (int i = 0; i < A->row; i++)
		for (int j = 0; j < B->col; j++) {
			float sum = 0;
			for (int k = 0; k < A->col; k++) {
				sum += (A->M[i][k] * B->M[k][j]);
			}
			C.M[i][j] = sum;
		}
}

void matrix::matrix_subtract(matrix* A, matrix* B, matrix C) {
	if ((A->row != B->row) || (A->col != B->col)) {
		cout << "matrices not compatible" << endl;
		return;
	}
	C.new_matrix(A->row, A->col, C);
	for (int i = 0; i < A->row; i++) {
		for (int j = 0; j < A->col; j++) {
			C.M[i][j] = A->M[i][j] - B->M[i][j];
		}
	}
}

void matrix::matrix_transponse(matrix* A, matrix B) {
	B.new_matrix(A->row, A->col, B);
	for (int i = 0; i < A->row; ++i) {
		for (int j = 0; j < A->col; ++j) {
			B.M[i][j] = A->M[j][i];
		}
	}
}

void matrix::print_matrix(matrix* A) {
	for (int i = 0; i < A->row; i++) {
		for (int j = 0; j < A->col; j++) {
			cout << A->M[i][j];
		}
		cout << endl;
	}
}

void matrix::delete_matrix(matrix* A) {
	for (int i = 0; i < A->row; i++) {
		delete A->M[i];
	}
	delete A->M;
}

int main()
{
	matrix test1, test2, result1, result2, result3, result4;
	test1.input_matrix(test1);
	test2.matrix_generate(test2);
	cout << "generated matrix: " << endl;
	test2.print_matrix(&test2);

	cout << "addition: " << endl;
	result1.matrix_add(&test1, &test2, result1);
	result1.print_matrix(&result1);

	cout << "multiplication: " << endl;
	result2.matrix_multiply(&test1, &test2, result2);
	result2.print_matrix(&result2);

	cout << "subtraction: " << endl;
	result3.matrix_subtract(&test1, &test2, result3);
	result3.print_matrix(&result3);

	cout << "transponded: " << endl;
	result4.matrix_transponse(&test1, result4);
	result4.print_matrix(&result4);

	result1.delete_matrix(&result1);
	result2.delete_matrix(&result2);
	result3.delete_matrix(&result3);
	result4.delete_matrix(&result4);
	test1.delete_matrix(&test1);
	test2.delete_matrix(&test2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

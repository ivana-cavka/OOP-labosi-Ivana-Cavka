#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <time.h>
#include <vector>
#include "ships.hpp"
#include "player.hpp"
using namespace std;

struct Point {
	int x;
	int y;
};

Point inputPoint() {
	Point p;
	do {
		cout << endl << "Pick a spot. Both coordinates must be in range from 0 to 9:";
		cout << endl << "row = ";
		cin >> p.x;
		cout << "column = ";
		cin >> p.y;
	} while (!(p.x <= 9 && p.x >= 0 && p.y <= 9 && p.x >= 0));
	return p;
}

Point generatePoint() {
	Point p;
	//srand((unsigned)time(NULL));
	p.x = rand() % 9 + 1;
	p.y = rand() % 9 + 1;
	return p;
}

class Board {
private:
	const static int rows = 10;  //point.x
	const static int columns = 10;  //point.y
	char grid[rows][columns]; 

public:
	Board();
	void updateBoard(Point p, bool flag);
	void printBoard();
	bool checkPoint(Point p);
};

Board::Board() {
	for (int x = 0; x < this->rows; x++) {
		for (int y = 0; y < this->columns; y++) {
			grid[x][y] = ' ';
		}
	}
}

void Board::updateBoard(Point p, bool flag) {
	if (flag) { 
		this->grid[p.x][p.y] = 'X'; 
	}
	else { 
		this->grid[p.x][p.y] = '0'; 
	}
}

void Board::printBoard() {
	cout << endl;
	for (int x = 0; x < this->rows * 2; x++) {
		for (int y = 0; y < this->columns * 2; y++) {
			if (y % 2 == 1) {
				cout << '|';
			}
			else if (x % 2 == 1) {
				cout << '-';
			}
			else if (y == 0) { //prvi stupac ima brojeve
				cout << x/2;  
			}
			else if (x == 0) { //prvi red ima brojeve
				cout << y/2; 
			}
			else { //parna mjesta imaju mjesto za pogaðanje
				cout << grid[x/2][y/2];
			}
		}
		cout << endl;
	}
}

//provjera mjesta - true if empty
bool Board::checkPoint(Point p) { 
	return (this->grid[p.x][p.y] == ' ');
}

//generiranje left/right/up/down
char generateDirection() { 
	char dir;
	//srand((unsigned)time(NULL));
	int x = rand() % 4;
	switch (x) {
	case 0:
		dir = 'L';
		break;
	case 1:
		dir = 'R';
		break;
	case 2:
		dir = 'U';
		break;
	default:
		dir = 'D';
		break;
	}
	return dir;
}

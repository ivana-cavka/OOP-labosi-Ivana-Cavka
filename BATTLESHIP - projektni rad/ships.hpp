#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <time.h>
#include <vector>
#include "Board.hpp"
using namespace std;

class Battleship {
private:
	Point coord;
	int length;
	char direction;

public:
	Battleship() { coord.x = 0; coord.y = 0; length = 0; direction = NULL; }
	~Battleship() { } //CHECKIRAT
	virtual const Point getCoord() { return this->coord; }
	virtual void setCoord(const Point p) { this->coord = p; }
	virtual const int getLength() { return this->length; }
	virtual const char getDirection() { return this->direction; }
	virtual void setDirection(char newDirection) { this->direction = newDirection; }
	virtual void inputShip(Board& board) {}
	virtual void generateShip(Board& board) {}
	virtual bool fillTheShipByDirection(Board& board, Point p) { return true; }
	virtual void printShipInfo() {}
};

class Trajekt : public Battleship {
private:
	Point coord;
	int length = 5;
	char direction;

public:
	Trajekt() { }
	const Point getCoord() { return this->coord; }
	void setCoord(const Point p) { this->coord = p; }
	const int getLength() { return this->length; }
	const char getDirection() { return this->direction; }
	void setDirection(char newDirection) { this->direction = newDirection; }
	void inputShip(Board& board);
	void generateShip(Board& board);
	bool fillTheShipByDirection(Board& board, Point p);
	void printShipInfo();
};

class Vapor : public Battleship {
private:
	Point coord;
	int length = 4;
	char direction;

public:
	Vapor() { }
	const Point getCoord() { return this->coord; }
	void setCoord(const Point p) { this->coord = p; }
	const int getLength() { return this->length; }
	const char getDirection() { return this->direction; }
	void setDirection(char newDirection) { this->direction = newDirection; }
	void inputShip(Board& board);
	void generateShip(Board& board);
	bool fillTheShipByDirection(Board& board, Point p);
	void printShipInfo();
};

class Barka : public Battleship {
private:
	Point coord;
	int length = 3;
	char direction;

public:
	Barka() {}
	const Point getCoord() { return this->coord; }
	void setCoord(const Point p) { this->coord = p; }
	const int getLength() { return this->length; }
	const char getDirection() { return this->direction; }
	void setDirection(char newDirection) { this->direction = newDirection; }
	void inputShip(Board& board);
	void generateShip(Board& board);
	bool fillTheShipByDirection(Board& board, Point p);
	void printShipInfo();
};

class Kaic : public Battleship {
private:
	Point coord;
	int length = 2;
	char direction;

public:
	Kaic() { }
	const Point getCoord() { return this->coord; }
	void setCoord(const Point p) { this->coord = p; }
	const int getLength() { return this->length; }
	const char getDirection() { return this->direction; }
	void setDirection(char newDirection) { this->direction = newDirection; }
	void inputShip(Board& board);
	void generateShip(Board& board);
	bool fillTheShipByDirection(Board& board, Point p);
	void printShipInfo();
};

class Bova : public Battleship {
private:
	Point coord;
	int length = 1;
	char direction = NULL;

public:
	Bova() { }
	const Point getCoord() { return this->coord; }
	void setCoord(const Point p) { this->coord = p; }
	const int getLength() { return this->length; }
	const char getDirection() { return this->direction; }
	void setDirection(char newDirection) { this->direction = newDirection; }
	void inputShip(Board& board);
	void generateShip(Board& board);
	bool fillTheShipByDirection(Board& board, Point p);
	void printShipInfo();
};

void Trajekt::printShipInfo() {
	cout << endl << "TRAJEKT = a ferry; designed to transfer people, veichles or goods" << endl;
	cout << "value: 5 spots / 5 points" << endl;
}

bool Trajekt::fillTheShipByDirection(Board& board, Point p) {
	int n = 0;
	Point copy1 = p;
	Point copy2 = p;
	do {
		switch (this->getDirection()) {
		case 'L':
			if (0 >= (copy1.y - this->getLength()) && n == 0) { 
				n = 0; 
				return false; 
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y--;
			break;
		case 'R':
			if (9 < (copy1.y + this->getLength()) && n == 0) { 
				n = 0; 
				return false; 
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y++;
			break;
		case 'U':
			if (0 >= (copy1.x - this->getLength()) && n == 0) { 
				n = 0; 
				return false; 
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x--;
			break;
		default:
			if (9 < (copy1.x + this->getLength()) && n == 0) { 
				n = 0; 
				return false; 
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x++;
			break;
		}
		n++;
	} while (n < this->getLength());
	return true;
}

void Trajekt::inputShip(Board& board) {
	Point p;
	char dir;
	bool flag = true;
	do {
		this->printShipInfo();
		cout << endl << "Pick your starting point in the grid: ";
		p = inputPoint();
		do {
			cout << endl << "Pick the direction of the ship " << endl;
			cout << "(type L for left of the ship, R for right of the ship, U for upwards and D for downwards): ";
			cin >> dir;
		} while (!(dir != 'L' || dir != 'R' || dir != 'U' || dir != 'D'));
		this->setDirection(dir);
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Trajekt::generateShip(Board& board) {
	Point p;
	bool flag = true;
	int seed = 0;
	do {
		srand(seed++);
		p = generatePoint();
		this->setDirection(generateDirection());
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
		seed++;
	} while (!flag);
}

void Barka::printShipInfo() {
	cout << endl << "BARKA = a small boat; usually for one to two people" << endl;
	cout << "value: 3 spots / 3 points" << endl;
}

bool Barka::fillTheShipByDirection(Board& board, Point p) {
	int n = 0;
	Point copy1 = p;
	Point copy2 = p;
	do {
		switch (this->getDirection()) {
		case 'L':
			if (0 >= (copy1.y - this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y--;
			break;
		case 'R':
			if (9 < (copy1.y + this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y++;
			break;
		case 'U':
			if (0 >= (copy1.x - this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x--;
			break;
		default:
			if (9 < (copy1.x + this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x++;
			break;
		}
		n++;
	} while (n < this->getLength());
	return true;
}

void Barka::inputShip(Board& board) {
	Point p;
	char dir;
	bool flag = true;
	do {
		this->printShipInfo();
		cout << endl << "Pick your starting point in the grid: ";
		p = inputPoint();
		do {
			cout << endl << "Pick the direction of the ship " << endl;
			cout << "(type L for left of the ship, R for right of the ship, U for upwards and D for downwards): ";
			cin >> dir;
		} while (!(dir != 'L' || dir != 'R' || dir != 'U' || dir != 'D'));
		this->setDirection(dir);
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Barka::generateShip(Board& board) {
	Point p;
	bool flag = true;
	do {
		p = generatePoint();
		this->setDirection(generateDirection());
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Vapor::printShipInfo() {
	cout << endl << "VAPOR = a middle-size ship; usually used for transport of people or merchandise" << endl;
	cout << "value: 4 spots / 4 points" << endl;
}

bool Vapor::fillTheShipByDirection(Board& board, Point p) {
	int n = 0;
	Point copy1 = p;
	Point copy2 = p;
	do {
		switch (this->getDirection()) {
		case 'L':
			if (0 >= (copy1.y - this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y--;
			break;
		case 'R':
			if (9 < (copy1.y + this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y++;
			break;
		case 'U':
			if (0 >= (copy1.x - this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x--;
			break;
		default:
			if (9 < (copy1.x + this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x++;
			break;
		}
		n++;
	} while (n < this->getLength());
	return true;
}

void Vapor::inputShip(Board& board) {
	Point p;
	char dir;
	bool flag = true;
	do {
		this->printShipInfo();
		cout << endl << "Pick your starting point in the grid: ";
		p = inputPoint();
		do {
			cout << endl << "Pick the direction of the ship " << endl;
			cout << "(type L for left of the ship, R for right of the ship, U for upwards and D for downwards): ";
			cin >> dir;
		} while (!(dir != 'L' || dir != 'R' || dir != 'U' || dir != 'D'));
		this->setDirection(dir);
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Vapor::generateShip(Board& board) {
	Point p;
	bool flag = true;
	do {
		p = generatePoint();
		this->setDirection(generateDirection());
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Kaic::printShipInfo() {
	cout << endl << "KAICH = a one-man boat; usually with paddles" << endl;
	cout << "value: 2 spots / 2 points" << endl;
}

bool Kaic::fillTheShipByDirection(Board& board, Point p) {
	int n = 0;
	Point copy1 = p;
	Point copy2 = p;
	do {
		switch (this->getDirection()) {
		case 'L':
			if (0 >= (copy1.y - this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y--;
			break;
		case 'R':
			if (9 < (copy1.y + this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.y++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.y++;
			break;
		case 'U':
			if (0 >= (copy1.x - this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x--;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x--;
			break;
		default:
			if (9 < (copy1.x + this->getLength()) && n == 0) {
				n = 0;
				return false;
			}
			else if (n == 0) {
				for (int i = 0; i < this->getLength(); i++) {
					if (!board.checkPoint(copy2)) { return false; }
					copy2.x++;
				}
			}
			board.updateBoard(p, board.checkPoint(p));
			p.x++;
			break;
		}
		n++;
	} while (n < this->getLength());
	return true;
}

void Kaic::inputShip(Board& board) {
	Point p;
	char dir;
	bool flag = true;
	do {
		this->printShipInfo();
		cout << endl << "Pick your starting point in the grid: ";
		p = inputPoint();
		do {
			cout << endl << "Pick the direction of the ship " << endl;
			cout << "(type L for left of the ship, R for right of the ship, U for upwards and D for downwards): ";
			cin >> dir;
		} while (!(dir != 'L' || dir != 'R' || dir != 'U' || dir != 'D'));
		this->setDirection(dir);
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Kaic::generateShip(Board& board) {
	Point p;
	bool flag = true;
	do {
		p = generatePoint();
		this->setDirection(generateDirection());
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Bova::printShipInfo() {
	cout << endl << "BOVA = a bobber/float/cork; a floating mark on the surface of the sea" << endl;
	cout << "value: 1 spot / 1 point" << endl;
}

bool Bova::fillTheShipByDirection(Board& board, Point p) {
	if (board.checkPoint(p)) {
		board.updateBoard(p, board.checkPoint(p));
		return true;
	}
	return false;
}

void Bova::inputShip(Board& board) {
	Point p;
	bool flag = false;
	do {
		this->printShipInfo();
		cout << endl << "Pick your point in the grid: " << endl;
		p = inputPoint();
		this->setCoord(p);
		flag = this->fillTheShipByDirection(board, p);
	} while (!flag);
}

void Bova::generateShip(Board& board) {
	Point p;
	do {
		p = generatePoint();
	} while (!board.checkPoint(p));
	this->setCoord(p);
	this->fillTheShipByDirection(board, p);
}
#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <time.h>
#include <vector>
#include "ships.hpp"
#include "board.hpp"
using namespace std;

class Player {
private:
	int lives = 15; //= not hit ship points
	int maxLives = 15; //= max not hit ship points (5+4+3+2+1)

public:
	Player() {}
	~Player() {} // CHECKIRAT
	virtual void setLives(int newLives) { this->lives = newLives; }
	virtual int getLives() const { return this->lives; }
	virtual int getMaxLives() const { return this->maxLives; }
};

class HumanPlayer : public Player {
private:
	int lives = 15; //= not hit ship points
	int maxLives = 15; //= max not hit ship points (5+4+3+2+1)

public:
	void setLives(int newLives) { this->lives = newLives; }
	int getLives() const { return this->lives; }
	int getMaxLives() const { return this->maxLives; }
};

class ComputerPlayer : public Player {
private:
	int lives = 15; //= not hit ship points
	int maxLives = 15; //= max not hit ship points (5+4+3+2+1)

public:
	void setLives(int newLives) { this->lives = newLives; }
	int getLives() const { return this->lives; }
	int getMaxLives() const { return this->maxLives; }
};
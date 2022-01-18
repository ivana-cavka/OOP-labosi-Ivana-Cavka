#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class Player {
private:
	string name;
	int pickedSum;
	int points;
public:
	Player() { this->name = "newPlayer"; this->pickedSum = 0; this->points = 0; };
	Player(string newName) { this->name = newName; this->pickedSum = 0; this->points = 0; };
	~Player() {};
	void setName(string newName);
	string getName();
	void setPickedSum(int newPickedSum);
	int getPickedSum();
	void setPoints(int newPoints);
	int getPoints();
	void addPoints();
	void printPlayerStatus();
	void PickCoins();
};

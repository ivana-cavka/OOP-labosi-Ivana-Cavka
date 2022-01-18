#include "player.hpp"

void Player::setName(string newName) {
	this->name = newName;
}

string Player::getName() {
	return this->name;
}

void Player::setPickedSum(int newPickedSum) {
	this->pickedSum = newPickedSum;
}

int Player::getPickedSum() {
	return this->pickedSum;
}

void Player::setPoints(int newPoints) {
	this->points = newPoints;
}

int Player::getPoints() {
	return this->points;
}

void Player::addPoints() {
	this->points += 1;
}

void Player::printPlayerStatus() {
	cout << "Player " << this->name << " picked sum of " << this->pickedSum << " and has " << this->points;
}

void Player::PickCoins() {
	this->setPickedSum(0);
}
#pragma once
#include "player.hpp"

class HumanPlayer : public Player {
public:
	HumanPlayer() { this->setName("Guest"); this->setPickedSum(0); this->setPoints(0); } ;
	HumanPlayer(string newName) { this->setName(newName); this->setPickedSum(0); this->setPoints(0); } ;
	void PickCoins();
};


#pragma once
#include "player.hpp"
#include <time.h>

class ComputerPlayer : public Player {
public:
	ComputerPlayer() { this->setName("RoboGuest"); this->setPickedSum(0); this->setPoints(0); };
	ComputerPlayer(string newName) { this->setName(newName); this->setPickedSum(0); this->setPoints(0); };
	void PickCoins();
	int TakeAGuess();
};

#include "computerPlayer.hpp"

void ComputerPlayer::PickCoins() {
	srand(time(NULL));
	int x = (int)(rand() % 9);
	if (x != 4) {
		this->setPickedSum(x);
		return;
	}
	else {
		this->PickCoins();
	}
}

int ComputerPlayer::TakeAGuess() {
	srand(time(NULL));
	int x = (int)(rand() % 9);
	if (x != 4) {
		return x;
	}
	else {
		this->TakeAGuess();
	}
}
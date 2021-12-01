#pragma once
#include "model.hpp"

Hangman player;

char userEntry() {
	char x;
	cout << "Guess a letter:\t";
	cin >> x;
	return toupper(x);
}

bool checkLetter(char X) {
	string temp;
	temp.push_back(X);
	if (player.getMovie().find(temp) != string::npos) {
		player.setGuessMovie(X);
		return true;
	}
	player.setUsedLetters(X);
	return false;
}

void updateLives(bool check) {
	if (check == false) {
		player.setLives(player.getLives() - 1);
	}
}

bool checkIfGameIsOver() {
	if (player.getGuessMovie().find("_") == string::npos) {
		player.setInGame(false);
	}
	else if (player.getLives() == 0) {
		player.setInGame(false);
	}
	return player.getInGame();
}
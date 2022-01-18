#include "game.hpp"

void Game::setPlayers(int numOfPlayers) {
	Player temp;
	string tempstr;
	for (int i = 0; i < numOfPlayers; i++)
	{
		cout << "Player name: " << endl;
		getline(cin, tempstr);
		temp.setName(tempstr);
		temp.setPickedSum(0);
		temp.setPoints(0);
		this->players.push_back(temp);
	}
}

vector<Player> Game::getPlayers() {
	return this->players;
}

void Game::setTarget(int newTarget) {
	this->target = newTarget;
}

int Game::getTarget() {
	return this->target;
}

void Game::addPlayer(Player newPlayer) {
	this->players.push_back(newPlayer);
}

int Game::sumAllPlayers() {
	int sum;
	for (int i = 0; i < this->players.size(); i++) {
		sum += this->players[i].getPickedSum();
	}
}

bool Game::checkWinner() {
	for (int i = 0; i < this->players.size(); i++) {
		if (this->players[i].getPoints() == this->getTarget()) {
			return true;
		}
	}
	return false;
}

Player Game::findWinner() {
	for (int i = 0; i < this->players.size(); i++) {
		if (this->players[i].getPoints() == this->getTarget()) {
			return this->players[i];
		}
	}
}

void Game::printAllPlayers() {
	for (int i = 0; i < this->players.size(); i++) {
		this->players[i].printPlayerStatus();
	}
}

void Game::run() {
	int plyrnum, trgt;
	cout << "How many players in this game? " << endl;
	cin >> plyrnum;
	cout << "What's the target of the game? " << endl;
	cin >> trgt;
	char plyr;
	for (int i = 0; i < plyrnum; i++) {
		cout << "New player input ------------------ " << endl;
		cout << "Type C for computer or H for human: " << endl;
		cin >> plyr;
		if (plyr == 'C') {
			ComputerPlayer computer("robo" + to_string(i));
			computer.PickCoins();
			addPlayer(computer);
		}
		else if (plyr == 'H') {
			string plyrname;
			int pickedsum;
			cout << "Your name: " << endl;
			getline(cin, plyrname);
			HumanPlayer human(plyrname);
			human.PickCoins();
			addPlayer(human);
		}
	}
	do {
		for (int i = 0; i < this->getPlayers().size(); i++) {
			if (this->sumAllPlayers() == this->players[i].getPickedSum()) {
				this->players[i].addPoints();
			}
		}
		if (this->checkWinner()) {
			cout << "The winner is: ";
			this->findWinner().printPlayerStatus();
			break;
		}
		else {
			for (int i = 0; i < this->getPlayers().size(); i++) {
				if (typeid(this->players[i]) == typeid(ComputerPlayer)) {
					this->players[i].PickCoins();
				}
				else {
					this->players[i].PickCoins();
				}
			}
		}
	} while (true);
}
#pragma once
#include "player.hpp"
#include "computerPlayer.hpp"
#include "humanPlayer.hpp"
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <typeinfo>

class Game {
private:
	vector<Player> players;
	int target;
	void setPlayers(int numOfPlayers);
	vector<Player> getPlayers();
	void setTarget(int newTarget);
	int getTarget();
	void addPlayer(Player newPlayer);
	int sumAllPlayers();
	bool checkWinner();
	Player findWinner();
	void printAllPlayers();
public:
	Game() { this->target = 0; };
	~Game() {};
	void run();
};

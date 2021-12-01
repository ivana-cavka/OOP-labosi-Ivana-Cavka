#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <time.h>
#include <fstream>
#include <streambuf>
using namespace std;

class Hangman {

private:
	string movie; //movie.txt
	string guessMovie; //user's guess
	string maskedMovie; //masked title
	int lives; //user's lives
	int maxLives = 8;
	string usedLetters;
	bool inGame;

public: 
	Hangman();
	void setMovie();
	string getMovie() const;
	void setGuessMovie(string newGuess);
	void setGuessMovie(char X);
	string getGuessMovie() const;
	void setMaskedMovie();
	string getMaskedMovie() const;
	void setLives(int newLives);
	int getLives() const;
	int getMaxLives() const;
	void setUsedLetters(char X);
	string getUsedLetters() const;
	void setInGame(bool Status);
	bool getInGame();
};

void Hangman::setMovie() {
	ifstream file("movie.txt");
	string line;
	srand(time(NULL));
	if (file.is_open()) {
		string buffer;
		int count = 0;
		while (!file.eof() && count < (int)(0 + rand() % 38))
		{
			getline(file, buffer, '\n');
			count++;
		}
		getline(file, line, '\n');
		file.close();
	}
	string temp;
	for (size_t i = 0; i < line.length(); i++) {
		if (isalpha(line.at(i))) {
			temp.push_back((char)toupper(line.at(i)));
		}
		else {
			temp.push_back(line.at(i));
		}
	}
	this->movie = temp;
}

string Hangman::getMovie() const {
	return this->movie;
}

void Hangman::setGuessMovie(string newGuess) {
	this->guessMovie = newGuess;
}

void Hangman::setGuessMovie(char X) {
	string temp;
	temp.push_back(X);
	size_t found = this->movie.find(temp);
	while (found != string::npos) {
		this->guessMovie.replace(found, temp.length(), temp);
		found = this->movie.find(temp, found + 1);
	}
}

string Hangman::getGuessMovie() const {
	return this->guessMovie;
}

void Hangman::setMaskedMovie() {
	string temp;
	for (size_t i = 0; i < this->movie.length(); i++) {
		if (isalpha(this->movie.at(i))) {
			temp.push_back('_');
		}
		else {
			temp.push_back(this->movie.at(i));
		}
	}
	this->maskedMovie = temp;
}

string Hangman::getMaskedMovie() const {
	return this->maskedMovie;
}

void Hangman::setLives(int newLives) {
	this->lives = newLives;
}

int Hangman::getLives() const {
	return this->lives;
}

int Hangman::getMaxLives() const {
	return this->maxLives;
}

void Hangman::setUsedLetters(char X) {
	this->usedLetters.push_back(X);
}

string Hangman::getUsedLetters() const {
	return this->usedLetters;
}

void Hangman::setInGame(bool status) {
	this->inGame = status;
}

bool Hangman::getInGame() {
	return this->inGame;
}

Hangman::Hangman() {
	setMovie();
	setMaskedMovie();
	setGuessMovie(getMaskedMovie());
	setLives(getMaxLives());
	setInGame(true);
}

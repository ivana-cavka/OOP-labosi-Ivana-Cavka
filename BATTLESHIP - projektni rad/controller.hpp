#pragma once
#include "view.hpp"
#include "player.hpp"
#include "ships.hpp"
#include "board.hpp"

void runTheGame() { 
	/*START*/
	displayTitle();
	displayRules();
	HumanPlayer hp;
	ComputerPlayer cp;
	Board humanPlayingBoard = Board(); //unesena ploca
	Board computerPlayingBoard = Board(); //generirana ploca
	Board humanShowBoard = Board(); 
	Board computerShowBoard = Board();
	cout << endl << "This is your strategy board... Time to draw in some ships!" << endl;
	humanShowBoard.printBoard();

	/*SHIP INPUT FOR HUMAN PLAYER*/
	Trajekt humanTrajekt = Trajekt();
	Vapor humanVapor = Vapor();
	Barka humanBarka = Barka();
	Kaic humanKaic = Kaic();
	Bova humanBova = Bova();
	humanTrajekt.inputShip(humanPlayingBoard);
	humanPlayingBoard.printBoard();
	humanVapor.inputShip(humanPlayingBoard);
	humanPlayingBoard.printBoard();
	humanBarka.inputShip(humanPlayingBoard);
	humanPlayingBoard.printBoard();
	humanKaic.inputShip(humanPlayingBoard);
	humanPlayingBoard.printBoard();
	humanBova.inputShip(humanPlayingBoard);
	humanPlayingBoard.printBoard();
	cout << endl << "Your input is finished. Now it's time to start the game..." << endl;

	/*SHIP GENERATING FOR COMPUTER PLAYER*/
	Trajekt computerTrajekt = Trajekt();
	Vapor computerVapor = Vapor();
	Barka computerBarka = Barka();
	Kaic computerKaic = Kaic();
	Bova computerBova = Bova();
	computerTrajekt.generateShip(computerPlayingBoard);
	computerVapor.generateShip(computerPlayingBoard);
	computerBarka.generateShip(computerPlayingBoard);
	computerKaic.generateShip(computerPlayingBoard);
	computerBova.generateShip(computerPlayingBoard);

	/*ATTACKS*/
	Point p1, p2;
	int temp;
	do {
		if (cp.getLives() > 0 && hp.getLives() > 0) {
			cout << endl << "Your turn!" << endl;
			p1 = inputPoint();
			computerShowBoard.updateBoard(p1, !computerPlayingBoard.checkPoint(p1));
			if (!computerPlayingBoard.checkPoint(p1)) { 
				temp = cp.getLives(); 
				cp.setLives(temp - 1); 
			}
			p2 = generatePoint();
			humanShowBoard.updateBoard(p2, !humanPlayingBoard.checkPoint(p2));
			if (!humanPlayingBoard.checkPoint(p2)) {
				temp = hp.getLives();
				hp.setLives(temp - 1);
			}
			cout << endl << "Current status: (X = hit spot, 0 = missed spot)" << endl;
			cout << endl << "HUMAN PLAYER FIELD" << endl;
			humanShowBoard.printBoard();
			cout << endl << "You have " << hp.getLives() << " spots left." << endl;
			cout << endl << "COMPUTER PLAYER FIELD" << endl;
			computerShowBoard.printBoard();
		}
		else if (cp.getLives() == 0) {
			cout << endl << "HUMAN PLAYER" << endl;
			humanShowBoard.printBoard();
			cout << endl << "COMPUTER PLAYER" << endl;
			computerShowBoard.printBoard();
			cout << endl << "Congradulations! You sank all the enemies' battleships!" << endl;
			break;
		}
		else if (hp.getLives() == 0) {
			cout << endl << "HUMAN PLAYER" << endl;
			humanShowBoard.printBoard();
			cout << endl << "COMPUTER PLAYER" << endl;
			computerShowBoard.printBoard();
			cout << "Sorry, you lose... your battleships are now turning into the coral reef." << endl;
			break;
		}
	} while (true);

}


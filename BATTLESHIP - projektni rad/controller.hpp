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

/*
if (cpu.Attack(cpuX, cpuY)) // checks the boolean output of the Attack function for the cpu
			{
				isTrueCpu = true; // sets isTrueCpu to true
				cpuFound++; // increments cpuFound
				cpuToGet--; // decrements cpuToGet
				cout << "The Computer has found one of your battleships at: " << "(" << cpuX << ", " << cpuY << ")" << endl; // outputs the position that the cpu found a battleship at.
			}
			else // anything else
			{
				isTrueCpu = false; // sets isTrueCpu to false
				cout << "The Computer did not find a battleship this time" << endl; // outputs that the cpu did not find a battleship this time.
			}
			position1 = 11; // sets position1 and position2 to 11
			position2 = 11; // so that the while loop will initiate below

			while (position1 > 9 || position2 > 9) // loops while position1 is more than 9 OR position 2  is more than 9.
			{
				if (cpuFound == 10 || found == 10)
				{
					break;
				}
				cout << "Please input the location on the grid you think a battleship is: "; // prompts the user to enter co-ordinates.

				cin >> position1 >> position2; // takes the keyboard input and stores it in position

				while (cin.fail()) // this will inintiate if the user enters a non integer input.
				{
					cin.clear(); // clears the cin.
					cin.ignore(); // ignores so it does not go in to an infinite loop
					cout << "not int, try again: "; cin >> position1 >> position2; // re prompts the user to enter their input
				}
			}

			if (human.Attack(position1, position2)) // checks if the boolean value for the Attack function is true
			{
				isTrue = true; // sets isTrue to true
				found++; // increments found
				toGo--; // decrements toGo
				cout << "You have found: " << found << " battleships, you have: " << toGo << " to go" << endl; // alerts the user of how many battleships they have found, and how many more they need to get.
			}
			else // anything else
			{
				isTrue = false; // sets isTrue to false
				cout << "there is no ship at that position, keep trying" << endl; // alerts the user that there is no ship in that position
			}

			cout << "There are: " << human.numberOfShips() << " left" << endl; // tells the user how many more ships there is
			cout << "would you like to surrender (y/n)?: "; cin >> which; // asks the user if they want to surrender and stores the input into char.

			system("CLS"); // clears the console to eliminate clutter

			humanBoard.updateBoards(isTrue, position1, position2); // updates the boards
			cpuBoard.updateBoards(isTrueCpu, cpuX, cpuY);

			cout << "Your Board: " << endl;
			humanBoard.PrintBoards(); // prints the new boards
			cout << "CPU's Board" << endl;
			cpuBoard.PrintBoards();

			if (which == 'y') // checks if which is equal to y
			{
				break; // breaks from the loop
			}
			else if (found == 10 || cpuFound == 10)
			{
				break;
			}

			cout << "Would you like to rerun, or exit (r/e)"; cin >> rerun; // ask the user if they want to rerun, is stored in rerun.
*/

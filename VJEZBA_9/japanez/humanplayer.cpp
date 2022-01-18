#include "humanPlayer.hpp"

void HumanPlayer::PickCoins() {
	int pickedsum;
	cout << "There 3 coins in front of you:" << endl << " (1)  (2)  (5) " << endl << "Pick 1, 2 or 3 coins. What's their sum? ";
	cin >> pickedsum;
	while (pickedsum > 8 || pickedsum == 4) {
		cout << "Sum invalid. Try again: " << endl;
		cin >> pickedsum;
	}
	this->setPickedSum(pickedsum);
}
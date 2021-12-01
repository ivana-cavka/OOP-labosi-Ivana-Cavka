#pragma once
#include "controller.hpp"
#include "model.hpp"

void displayTitle();
void displayRules();
void displayCurrentProgress();
void displayHangman();

void displayTitle() {
        cout << "\t *    *     **     **    *  *****   **   **     **     **    *" << endl;
        cout << "\t *    *    *  *    * *   * *        * * * *    *  *    * *   *" << endl;
        cout << "\t ******   ******   *  *  * *  ***** *  *  *   ******   *  *  *" << endl;
        cout << "\t *    *  *      *  *   * * *      * *     *  *      *  *   * *" << endl;
        cout << "\t *    * *        * *    **  ******  *     * *        * *    **" << endl << endl << endl;
}

void displayRules()
{
    cout << endl;
    cout << "\t\t\t HOW TO PLAY" << endl;
    cout << "\t\t\t-------------" << endl;
    cout << "Welcome to hangman." << endl;
    cout << "You have to guess a movie title." << endl;
    cout << "Each letter is represented by a _." << endl;
    cout << "You have to type only one letter in one try." << endl;
    cout << "You have 8 tries to try and guess the word." << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Press enter to continue." << endl;
    cin.ignore();
    //cin.get();
}

void displayHangman() {
    switch (player.getLives()) {
        case 0: 
            cout << endl << "   _______\n   | /   |\n   |/    O\n   |    /|\\\n   |     |\n   |    / \\\n   |\n___|____    ";
            break;
        case 1: 
            cout << endl << "   _______\n   | /   |\n   |/    O\n   |    /|\\\n   |     |\n   |    /\n   |\n___|____    ";
            break;
        case 2: 
            cout << endl << "   _______\n   | /   |\n   |/    O\n   |    /|\\\n   |     |\n   |\n   |\n___|____    ";
            break;
        case 3: 
            cout << endl << "   _______\n   | /   |\n   |/    O\n   |    /|\\\n   |\n   |\n   |\n___|____    ";
            break;
        case 4: 
            cout << endl << "   _______\n   | /   |\n   |/    O\n   |    /|\n   |\n   |\n   |\n___|____    ";
            break;
        case 5: 
            cout << endl << "   _______\n   | /   |\n   |/    O\n   |     |\n   |\n   |\n   |\n___|____    ";
            break;
        case 6: 
            cout << endl << "   _______\n   | /   |\n   |/    O\n   |\n   |\n   |\n   |\n___|____    ";
            break;
        case 7: 
            cout << endl << "   _______\n   | /   |\n   |/\n   |\n   |\n   |\n   |\n___|____    ";
            break;
        default: 
            cout << endl << "   _______\n   | /\n   |/\n   |\n   |\n   |\n   |\n___|____    ";
            break;
    }
}

void displayCurrentProgress() {
    if (checkIfGameIsOver() && player.getLives() > 0) {
        displayHangman();
        cout << "\t\t" << player.getGuessMovie() << endl << endl;
        cout << "You have " << player.getLives() << " guesses left." << endl;
        cout << "These are the letters you already used: " << player.getUsedLetters() << endl;
    }
    else if (!checkIfGameIsOver() && player.getLives() > 0) {
        displayHangman();
        cout << "\t" << player.getGuessMovie();
        cout << "\tCongradulations! You got it!" << endl;
    }
    else {
        displayHangman();
        cout << "Sorry, you lose...you've been hanged." << endl;
    }
}

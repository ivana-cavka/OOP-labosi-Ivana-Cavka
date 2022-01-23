#pragma once
#include <iostream>
using namespace std;

void displayTitle();
void displayRules();

void displayTitle() {
    cout << "########   ########     ##         ##      #          ########    #######     #    #    #     ######" << endl;
    cout << " ##    ##   ##    ##  #########  ########  ##         ##    ##   ##    ##    ##    ##  ##    ##    ## " << endl;
    cout << " ##    ##   ##    ##    #######    ######  ##         ##         ##    #     ##    ##  ##    ##    ## " << endl;
    cout << "########    ##    ##     ##   #     ##   # ##        ########    ###       #########   ##    ##    ## " << endl;
    cout << " ########  ##########    ##         ##     ##       ########     ########   #########  ##    #######  " << endl;
    cout << "  ##    ##  ##    ##     ##         ##     ##        ##               ###   ##    ##   ##    ## " << endl;
    cout << "  ##    ##  ##    ##     ##         ##     ###   #   ##    ##    #    ##    ##    ##   ##    ## " << endl;
    cout << " ########   #    #      ####       ####   ########   ########     ######    #     #    #    #### " << endl;
    cout << "  ___   _   _    __  __   _ _____ ___   _     ___ ___ ___ _____ ___ ___  _  _ " << endl;
    cout << " |   \\ /_\\ | |  |  \\/  | /_\\_   _|_ _| /_\\   | __|   \\_ _|_   _|_ _/ _ \\| \\| |" << endl;
    cout << " | |) / _ \\| |__| |\\/| |/ _ \\| |  | | / _ \\  | _|| |) | |  | |  | | (_) | .` |" << endl;
    cout << " |___/_/ \\_\\____|_|  |_/_/ \\_\\_| |___/_/ \\_\\ |___|___/___| |_| |___\\___/|_|\\_|" << endl << endl << endl;
}

void displayRules()
{
    cout << endl;
    cout << "Welcome to BattleShip - Dalmatia edition..." << endl;
    cout << "...where all the boats are named after Dalmatian dialect." << endl << endl;
    cout << "HOW TO PLAY" << endl;
    cout << "-------------" << endl;
    cout << "Each ship spot is represented by an X, and a missed spot by a 0." << endl;
    cout << "Firstly, you have to choose where to position all your ships." << endl;
    cout << "Then you start playing against the computer, trying to sink its battleships," << endl;
    cout << "while it is also trying to sink yours'." << endl << endl;
    cout << "Good luck, sailor! May the odds be in your favor!" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Press enter to continue." << endl;
    cin.ignore();
    //cin.get();
}

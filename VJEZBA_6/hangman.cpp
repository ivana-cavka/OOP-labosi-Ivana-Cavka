// hangman.cpp : 
/*Napišite igru ”vješala” implementirajuæi Model-View-Controller pattern. 
Rijeèi koje se pogaðaju mogu biti imena filmova dana u datoteci movie.txt, gdje se film odabire sluèajnim odabirom.
1. Klasa HangmanModel opisuje reèenicu koju treba pogoditi, trenutno stanje reèenice koju gradimo, slova koja su pogoðena i slièno.
2. Klasa HangmanView opisuje prikaz vješala, prikaz trenutnog stanja reèenice koja se gradi i prikaz pogoðenih/promašenih slova.
3. Klasa HangmanController omoguæuje i verificira unos, updatea prikaz, modificira model.
Odvojite implementaciju i suèelje klasa u razlièite datoteke. 
Za ispis vješala možete koristiti ovakvu sliku: 
   _______ 
   | /   |
   |/    O 
   |    /|\ 
   |     | 
   |    / \ 
   | 
___|____                            
*/

#include "view.hpp"
#include "controller.hpp"
//#include "model.hpp"

int main()
{
    char x;
    bool flag;
    displayTitle();
    displayRules();
    displayCurrentProgress();
    while (checkIfGameIsOver()) {
        x = userEntry();
        flag = checkLetter(x);
        updateLives(flag);
        displayCurrentProgress();
    }
    return 0;
}


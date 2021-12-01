// hangman.cpp : 
/*Napi�ite igru �vje�ala� implementiraju�i Model-View-Controller pattern. 
Rije�i koje se poga�aju mogu biti imena filmova dana u datoteci movie.txt, gdje se film odabire slu�ajnim odabirom.
1. Klasa HangmanModel opisuje re�enicu koju treba pogoditi, trenutno stanje re�enice koju gradimo, slova koja su pogo�ena i sli�no.
2. Klasa HangmanView opisuje prikaz vje�ala, prikaz trenutnog stanja re�enice koja se gradi i prikaz pogo�enih/proma�enih slova.
3. Klasa HangmanController omogu�uje i verificira unos, updatea prikaz, modificira model.
Odvojite implementaciju i su�elje klasa u razli�ite datoteke. 
Za ispis vje�ala mo�ete koristiti ovakvu sliku: 
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


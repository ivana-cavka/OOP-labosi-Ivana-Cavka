/* japanez.cpp :  
Napravite igru Japane�a za vi�e igra�a. U igri svaki igra� ima tri kovanice, od 1, 2 i 5 kuna. 
U svakoj ruci odabire od nula do tri kovanice i poga�a zbroj odabranih kovanica u rukama svih igra�a. 
Igra�i koji pogode zbroj dobiju po jedan bod. Igra� mo�e biti �ovjek ili kompjuter. 
Igra se igra dok jedan od igra�a ne postigne unaprijed zadani broj bodova. Klase koje trebate definirati: 
� Game, zadu�ena za logiku igre 
� Player, predstavlja igra�a. Iz te klase izvedite dvije klase: HumanPlayer i ComputerPlayer.
Napomena: Svaku klasu stavite u posebnu datoteku i to tako da definicije klasa stavljate u .h ili .hpp datoteku, 
a implementaciju klase u .cpp datoteku.
*/

#include <iostream>
#include "game.hpp"

int main()
{
    Game newGame;
    newGame.run();
}
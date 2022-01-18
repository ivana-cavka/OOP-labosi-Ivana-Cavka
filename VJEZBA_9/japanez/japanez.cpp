/* japanez.cpp :  
Napravite igru Japaneža za više igraèa. U igri svaki igraè ima tri kovanice, od 1, 2 i 5 kuna. 
U svakoj ruci odabire od nula do tri kovanice i pogaða zbroj odabranih kovanica u rukama svih igraèa. 
Igraèi koji pogode zbroj dobiju po jedan bod. Igraè može biti èovjek ili kompjuter. 
Igra se igra dok jedan od igraèa ne postigne unaprijed zadani broj bodova. Klase koje trebate definirati: 
· Game, zadužena za logiku igre 
· Player, predstavlja igraèa. Iz te klase izvedite dvije klase: HumanPlayer i ComputerPlayer.
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
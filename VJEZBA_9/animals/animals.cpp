/* animals.cpp: Definirajte interface Zivotinja sa metodama koje vraæaju broj nogu te vrstu (string). 
Izvedite klase životinja: Kukac, Pauk, Ptica, te iz njih neke klase za konkretne životinje. 
Napišite klasu Brojac koja prima životinje (ispisuje vrstu svake dodane) i raèuna ukupan broj nogu svih životinja. 
U glavnom programu napravite nekoliko životinja, pošaljite ih brojaèu i ispišite ukupan broj nogu. 
- primjer ispisa: 
dodan: tarantula 
dodan: zohar 
dodan: vrabac 
ukupno nogu: 16
Napomena: Svaku klasu stavite u posebnu datoteku i to tako da definicije klasa stavljate u .h ili .hpp datoteku, 
a implementaciju klase u .cpp datoteku. 
*/

#include <iostream>
#include "animal.hpp"
#include "counter.hpp"
#include "counter.cpp"

int main()
{
    Counter countingAllLegs;
    Owl o;
    countingAllLegs.addAnimal(o);
    Sparrow s;
    countingAllLegs.addAnimal(s);
    Pigeon p;
    countingAllLegs.addAnimal(p);
    Ladybug l;
    countingAllLegs.addAnimal(l);
    Mantis m;
    countingAllLegs.addAnimal(m);
    Tarantula t;
    countingAllLegs.addAnimal(t);
    BlackWidow bw;
    countingAllLegs.addAnimal(bw);
    countingAllLegs.print();
}
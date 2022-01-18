/* animals.cpp: Definirajte interface Zivotinja sa metodama koje vra�aju broj nogu te vrstu (string). 
Izvedite klase �ivotinja: Kukac, Pauk, Ptica, te iz njih neke klase za konkretne �ivotinje. 
Napi�ite klasu Brojac koja prima �ivotinje (ispisuje vrstu svake dodane) i ra�una ukupan broj nogu svih �ivotinja. 
U glavnom programu napravite nekoliko �ivotinja, po�aljite ih broja�u i ispi�ite ukupan broj nogu. 
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
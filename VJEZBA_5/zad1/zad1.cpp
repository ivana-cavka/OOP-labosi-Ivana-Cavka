/* zad1.cpp :  Napisati klasu za poziciju točke u prostoru koja ima tri double podatka: 
dužinu, širinu i visinu (x, y, z koordinate). Klasa ima sljedeće funkcije: 
◦ Funkciju za postavljanje vrijednosti članova (treba imati pretpostavljene vrijednosti 0). 
◦ Funkciju za postavljanje pseudorandom vrijednosti članova (granice intervala su parametri funkcije). 
◦ Funkciju za dohvaćanje vrijednosti članova. 
◦ Funkciju koja računa udaljenost do druge točke u 2D ravnini (zanemarujući z koordinatu). 
◦ Funkciju koja računa udaljenost do druge točke u 3D prostoru. 
U main funkciji postavite vrijednost za dvije točke u prostoru i ispišite obe udaljenosti.
Označite sa const funkcije i vrijednosti koje su konstantne.
*/

#include "zad1.hpp"

int main()
{
    point x, y;
    x.randomPoint(1,10);
    cout << "X(" << x.getX() << "," << x.getY() << "," << x.getZ() << ")" << endl;
    y.setPoint(x.getX() + 5, x.getY() + 5, x.getZ() + 5);
    cout << "X(" << y.getX() << "," << y.getY() << "," << y.getZ() << ")" << endl;
    cout << "distance 2D: " << x.pointDistance2D(y) << endl << "distance 3D: " << x.pointDistance3D(y);
}


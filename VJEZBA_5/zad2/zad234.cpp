/* zad234.cpp : 
2) Napisati klasu koja predstavlja oružje. 
Oružje ima svoj položaj u prostoru (jedna točka u prostoru), 
broj metaka koji stanu u jedno punjenje i trenutni broj metaka u punjenju. 
Može pucati (shoot) i ponovo se puniti (reload).
Označite sa const funkcije i vrijednosti koje su konstantne.
3) Napisati klasu koja predstavlja metu. 
Meta je oblika kvadra i zadana je donjom lijevom i gornjom desnom točkom. 
Ima dva stanja: pogođena i nepogođena.
Označite sa const funkcije i vrijednosti koje su konstantne.
4) Napisati program koji će generirati n meta i jednog pucača (oružje). 
Uz pretpostavku da je položaj oružja horizontalan i da se oružje može zakretati za 360◦, 
izračunati koliko je meta pogođeno jednim punjenjem.
Označite sa const funkcije i vrijednosti koje su konstantne.
*/

#include "zad234.hpp"

int main()
{
    weapon gun;
	gun.p.randomPoint(3, 8);
    //gun.shoot();
    gun.reload();
    target* multiTarget = new target[3]; 
    for (int i = 0; i < 3; i++) {
        point p1, p2;
        p1.randomPoint(1, 5);
        p2.randomPoint(5, 10);
        multiTarget[i].setTarget(p1, p2);
        cout << endl;
    }
    cout << "target shot " << gun.shootTargets(multiTarget, 3) << " times" << endl;
    return 0;
}

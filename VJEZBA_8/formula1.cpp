/*formula.cpp : 
1. Napišite klasu timer koja sadrži privatne èlanove h, m tipa int i s tipa double,
koja predstavlja rezultat u trci Formule 1. Napišite potrebne konstruktore
i operatore kako bi za grupu vozaèa izraèunali :
· prosjeènu brzinu svih vozaèa,
· postignuto vrijeme najbržeg vozaèa,
· razliku vremena do vremena najbržeg vozaèa(u sekundama),
· ispisati postignuta vremena u obliku stringa "h:m:s"
Klasa treba imati operatore : +=, -=, +, -, /=, / , << , operator double
2. Zbog kršenja pravila svi su vozaèi kažnjeni sa dodatnih m sekundi.
Napisati funkcijski objekt kojim æe se postignuto vrijeme vozaèa poveæati za m sekundi.
Pomoæ : Za najbržu vožnju koristite funkciju min_element iz <algorithm>.
Da bi funkcija ispravno raèunala potrebno je definirati operator <.
*/
 
#include "formula1.hpp"
#include <vector>

int main()
{
    vector<Timer> v{ {2, 6, 9.118}, {2, 6, 15.251}, {2, 6, 9.925}, {2, 7, 15.222}, {2, 7, 10.775} };

    // prosjecno vrijeme
    Timer avg;
    for (auto t : v)
        avg += t;
    avg /= (int)v.size();
    cout << "avg " << avg << endl;

    // vrijeme najbrzeg (operator<)
    Timer tmax = *min_element(v.begin(), v.end());
    cout << "min " << tmax << endl;

    // zaostajanje za vodecim u sekundama
    for (auto& tm : v)
        cout << double(tm - tmax) << endl;

    // penaliziranje vozaca s m sekundi (funkcijski objekt)
    Penalty p(5);
    for (auto& tm : v)
        p(tm);

    return 0;
}

 /*
 * Rezultat
 * avg 2:6:36.0582
 * min 2:6:9.118
 * 0
 * 6.133
 * 0.807
 * 66.104
 * 61.657
 */
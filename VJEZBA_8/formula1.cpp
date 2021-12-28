/*formula.cpp : 
1. Napi�ite klasu timer koja sadr�i privatne �lanove h, m tipa int i s tipa double,
koja predstavlja rezultat u trci Formule 1. Napi�ite potrebne konstruktore
i operatore kako bi za grupu voza�a izra�unali :
� prosje�nu brzinu svih voza�a,
� postignuto vrijeme najbr�eg voza�a,
� razliku vremena do vremena najbr�eg voza�a(u sekundama),
� ispisati postignuta vremena u obliku stringa "h:m:s"
Klasa treba imati operatore : +=, -=, +, -, /=, / , << , operator double
2. Zbog kr�enja pravila svi su voza�i ka�njeni sa dodatnih m sekundi.
Napisati funkcijski objekt kojim �e se postignuto vrijeme voza�a pove�ati za m sekundi.
Pomo� : Za najbr�u vo�nju koristite funkciju min_element iz <algorithm>.
Da bi funkcija ispravno ra�unala potrebno je definirati operator <.
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
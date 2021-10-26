// zad3.cpp : 
// Definirati strukturu kruznica i strukturu pravokutnik koja predstavlja pravokutnik čije su stranice 
// paralelne sa osima apscisa i ordinata. Napisati funkciju koja prima niz pravokutnika i jednu kruznicu i 
// vraća broj pravokutnika koji sijeku kružnicu. Niz pravokutnika i kružnica šalju se u funkciju pomoću const referenci. 
// Napomena: – Jednadžba kružnice sa središtem u S(xs,ys) radijusa r (x−xs)2 +(y−ys)2 = r2 
//           – Pravokutnik u koordinatnom sustavu je određen sa svojom donjom lijevom i gornjom desnom točkom.

#include <iostream>
#include <cmath>
using namespace std;

struct point {
    float x, y;
};

struct circle {
    point S;
    float r;
};

struct rectangle {
    point left_down;  // x, y
    point right_up;   // w=abs(right_up.x-left_down.x), h=right_up.x-left_down.x ??
};

bool overlap (circle C, rectangle R) {
    float delta_x, delta_y;
    if (R.left_down.x * R.right_up.x < 0) {
        delta_x = fabs (R.right_up.x - R.left_down.x);
    }
    else {
        delta_x = fabs (-1 * R.right_up.x - R.left_down.x);
    }
    if (R.left_down.y * R.right_up.y < 0) {
        delta_y = fabs (R.right_up.y - R.left_down.y);
    }
    else {
        delta_y = fabs (-1 * R.right_up.y - R.left_down.y);
    }
    for (float x = R.left_down.x; x < R.left_down.x + delta_x; x++) {
        for (float y = R.left_down.y; y < R.left_down.y + delta_y; y++) {
            if (((x - C.S.x) * (x - C.S.x) + (y - C.S.y) * (y - C.S.y)) == C.r * C.r) {
                return true;
            }
        }
    }
    return false;
}

int finding_overlaps (const rectangle R[], int n, const circle& C ) {
    int overlaps = 0;
    for (int i = 0; i < n; i++) {
        if (overlap(C, R[i])) {
            overlaps ++;
        }
    }
    return overlaps;
}

int main ()
{
    point T, L;
    circle K;
    rectangle P1, P2, P3, P[3];
    T.x = 0.0; T.y = 0.0;
    L.x = 200.0; L.y = 200.0;
    K.S = T;
    K.r = 10.0;
    P1.left_down = T;
    P2.left_down = L;
    P3.left_down = T;
    P1.right_up.y = 22.0;
    P1.right_up.x = 12.0;
    P2.right_up.y = 18.0;
    P2.right_up.x = 24.0;
    P3.right_up.y = 14.0;
    P3.right_up.x = 124.0;
    P[0] = P1;
    P[1] = P2;
    P[2] = P3;
    cout << "number of overlaps: " << finding_overlaps(P, 3, K);
}

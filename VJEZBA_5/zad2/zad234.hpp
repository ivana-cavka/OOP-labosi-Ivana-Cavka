#pragma once
#include <iostream>
using namespace std;
class point {
    double x = 0, y = 0, z = 0;

public:
    void setPoint(double x, double y);
    void randomPoint(const int a, const int b);
    double getX() const;
    double getY() const;
};

void point::setPoint(double x, double y)
{
    this->x = x;
    this->y = y;
}

void point::randomPoint(const int a, const int b)
{
    this->x = (double)(a + rand() % (int)(b - a + 1));
    this->y = (double)(a + rand() % (int)(b - a + 1));
}

double point::getX() const
{
    return this->x;
}

double point::getY() const
{
    return this->y;
}

//zad3
class target {
    point leftDown;
    point rightUp;
    bool stanje_target;

public:
    void setTarget(point x, point y);
    bool shotOrMissed(point shoot);

};

void target::setTarget(point x, point y)
{
    leftDown = x;
    rightUp = y;

}

bool target::shotOrMissed(point shoot)
{
    return (shoot.getY() >= this->leftDown.getY() && shoot.getY() <= this->rightUp.getY());
}

//zad2
class weapon {
    point p;
    unsigned int maxBullets = 15;
    unsigned int statusBullets;

public:
	point p;
    void reload();
    void shoot();
    int shootTargets(target* array, int n);
};

void weapon::shoot()
{
    if (statusBullets != 0) {
        statusBullets--;
    }
    cout << "no bullets" << endl;
}

void weapon::reload()
{
    statusBullets = maxBullets;
    cout << "reloading bullets..." << endl;
}

int weapon::shootTargets(target* array, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i].shotOrMissed(this->p)) {
            count++;
        }
    }
    return count;
}


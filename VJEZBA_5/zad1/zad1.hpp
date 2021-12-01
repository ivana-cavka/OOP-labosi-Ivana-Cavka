#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class point {

    double x = 0, y = 0, z = 0;

public:
    void setPoint(double x, double y, double z);
    double getX() const;
    double getY() const;
    double getZ() const;
    void randomPoint(const int a, const int b);
    double pointDistance2D(const point p);
    double pointDistance3D(const point p);

};

void point::setPoint(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double point::getX() const
{
    return this->x;
}

double point::getY() const
{
    return this->y;
}

double point::getZ() const
{
    return this->z;
}

void point::randomPoint(const int a, const int b)
{
    this->x = (double)(a + rand() % (int)(b - a + 1));
    this->y = (double)(a + rand() % (int)(b - a + 1));
    this->z = (double)(a + rand() % (int)(b - a + 1));
}

double point::pointDistance2D(const point p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); //x je tocka nad kojom pozivamo classu, a t je druga tocka s kojom pristupamo classi
}

double point::pointDistance3D(const point p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
}


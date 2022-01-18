#pragma once
#include "animal.hpp"

class Counter {
private:
    int allLegs = 0;
public:
    Counter() { };
    void addAnimal(Animal x);
    void print();
    int getAllLegs();
};

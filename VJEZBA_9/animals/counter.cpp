#include "counter.hpp"
#include "animals.hpp"

void Counter::addAnimal(Animal x) {
    this->allLegs += a.getNumOfLegs();
    cout << a.getName() << " added." << endl;
}

int Counter::getAllLegs() {
    return this->allLegs;
}

void Counter::print() {
    cout << "Sum of legs: " << this->getAllLegs();
}
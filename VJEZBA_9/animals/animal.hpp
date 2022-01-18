#pragma once
#include <iostream>
using namespace std;

class Animal { 
private:
    int numOfLegs = 0;
    string name;
public:
    virtual int getNumOfLegs() = 0;
    virtual string getName() { return this->name; };
};

class Insect : public Animal {
private:
    int numOfLegs = 0;
    string name = "Insect";
public:
    int getNumOfLegs() = 0;
    string getName() { return this->name; };
};

class Bird : public Animal {
private:
    int numOfLegs = 0;
    string name = "Bird";
public:
    int getNumOfLegs() = 0;
    string getName() { return this->name; };
};

class Spider : public Animal {
private:
    int numOfLegs = 0;
    string name = "Spider";
public:
    int getNumOfLegs() = 0;
    string getName() { return this->name; };
};

class Owl : public Bird {
private:
    int numOfLegs = 2;
    string name = "Owl";
public:
    int getNumOfLegs() { return this->numOfLegs; }
    string getName() { return this->name; }
};

class Sparrow : public Bird {
private:
    int numOfLegs = 2;
    string name = "Sparrow";
public:
    int getNumOfLegs() { return this->numOfLegs; }
    string getName() { return this->name; }
};

class Pigeon : public Bird {
private:
    int numOfLegs = 2;
    string name = "Pigeon";
public:
    int getNumOfLegs() { return this->numOfLegs; }
    string getName() { return this->name; }
};

class Ladybug : public Insect {
private:
    int numOfLegs = 6;
    string name = "Ladybug";
public:
    int getNumOfLegs() { return this->numOfLegs; }
    string getName() { return this->name; }
};

class Mantis : public Insect {
private:
    int numOfLegs = 6;
    string name = "Mantis";
public:
    int getNumOfLegs() { return this->numOfLegs; }
    string getName() { return this->name; }
};

class Tarantula : public Spider {
private:
    int numOfLegs = 8;
    string name = "Tarantula";
public:
    int getNumOfLegs() { return this->numOfLegs; }
    string getName() { return this->name; }
};

class BlackWidow : public Spider {
private:
    int numOfLegs = 8;
    string name = "BlackWidow";
public:
    int getNumOfLegs() { return this->numOfLegs; }
    string getName() { return this->name; }
};


/* Definirajte klasu Board koja æe služiti kao okvir za iscrtavanje znakova. 
Board je matrica èije se dimenzije zadaju u konstruktoru, a za koju se memorija alocira na heapu. 
Board ima rub koji se sastoji od nekog znaka koji je odreðen u konstruktoru. 
· Napišite defaultni konstruktor, copy konstruktor, move konstruktor, konstruktor s argumentima i destruktor. 
· Definirajte strukturu Point koja ima dva èlana x i y tipa double, gdje su x i y vrijednosti manje od dimenzije matrice. 
· Napišite member funkciju draw_char koja za toèku p i znak ch postavlja znak ch na odgovarajuæem mjestu u matrici 
(x-koordinata odgovara retku matrice, a y-koordinata stupcu). Ako koordinate toèke p nisu cjelobrojne, 
zaokružite ih na najbližu cjelobrojnu vrijednost. 
· Napišite member funkciju draw_up_line koja poèevši od toèke p postavlja znak ch na svim poljima 
koja predstavljaju okomitu liniju prema gore. 
· Napišite member funkciju draw_line koja za dvije toèke p1 i p2 postavlja znak ch na svim poljima 
koje predstavljaju liniju izmeðu te dvije toèke. 
· Napišite member funkciju koja iscrtava trenutno stanje Boarda. */

#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

class Board {
private:
    int height;
    int width;
    char** matrix;

public:
    Board();
    Board(int a, int b);
    Board(const Board& other);
    ~Board();
    void display();
    void setHeight(int newHeight) { this->height = newHeight; }
    int getHeight() { return this->height; }
    void setWidth(int newWidth) { this->width = newWidth; }
    int getWidth() { return this->width; }
    void setMatrix(int height, int width);
    char** getMatrix() { return this->matrix; }
    void draw_char(Point& p, char ch);
    void draw_up_line(Point& p, char ch);
    void draw_line(Point& p1, Point& p2, char ch);
}; 

void Board::setMatrix(int height, int width) {
    matrix = new char* [height];
    for (int i = 0; i < height; i++) {
        matrix[i] = new char [width];
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == width - 1) {
                matrix[i][j] = '$';
            }
            else {
                matrix[i][j] = ' ';
            }
        }
    }
}

Board::Board() {
    setHeight(7);
    setWidth(7);
    setMatrix(this->getHeight(), this->getWidth());
}

Board::Board(int a, int b) {
    setHeight(a);
    setWidth(b);
    setMatrix(this->getHeight(), this->getWidth());
}

Board::Board(const Board& other) {
    this->width = other.width;
    this->height = other.height;
    this->matrix = new char* [this->getHeight()];
    for (int i = 0; i < this->getHeight(); i++) {
        this->matrix[i] = new char[this->getWidth()];
        for (int j = 0; j < this->getWidth(); j++) {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
}

Board::~Board() {
    for (int i = 0; i < this->getHeight(); i++) {
        cout << i << endl;
        char* tmp = matrix[i];
        delete tmp;
    }
    delete this->matrix;
}

void Board::display() {
    for (int i = 0; i < this->getHeight(); i++) {
        for (int j = 0; j < this->getWidth(); j++) {
            cout << this->matrix[i][j];
        }
        cout << endl;
    }
}

void Board::draw_char(Point& p, char ch) {
    if (p.x < this->getWidth() && p.y < this->getHeight()) {
        this->matrix[(int)p.y][(int)p.x] = ch;
    }
}

void Board::draw_up_line(Point& p, char ch) {
    for (int j = p.y; j >= 1; j--) {
        this->matrix[j][(int)p.x] = ch;
    }
}

void Board::draw_line(Point& p1, Point& p2, char ch) {
    int x1 = min(round(p1.x), round(p2.x));
    int y1 = min(round(p1.y), round(p2.y));
    int x2 = max(round(p1.x), round(p2.x));
    int y2 = max(round(p1.y), round(p2.y));
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            if (y1 == y2) {
                this->matrix[y1][j] = ch;
            }
            else if (x1 == x2) {
                this->matrix[i][x1] = ch;
            }
            else if (i == j) {
                this->matrix[i][j] = ch;
            }
        }
    }
}
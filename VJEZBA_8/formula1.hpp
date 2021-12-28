#pragma once
#ifndef formula1_hpp
#define formula1_hpp
#include <iostream>
#include <algorithm>
using namespace std;

class Timer {
private:
	int h, m;
	double s;
public:
	Timer() : h(0), m(0), s(0) {};
	Timer(int h, int m, double s) { this->h = h; this->m = m; this->s = s; };
	Timer(Timer const& other) { this->h = other.h; this->m = other.m; this->s = other.s; };
	Timer operator+(Timer const& other);
	Timer operator+=(Timer const& other);
	Timer operator-(Timer const& other);
	Timer operator-=(Timer const& other);
	Timer operator/(Timer const& other);
	Timer operator/=(Timer const& other);
	Timer operator/=(int n);
	bool operator<(Timer const& other);
	friend ostream& operator << (ostream& os, Timer const& other);
	void setS(double newS);
	double getS();
	operator double() { return ((double)(this->h * 60 * 60) + (double)(this->m * 60) + this->s); };
};

Timer Timer::operator+(Timer const& other){
	Timer temp;
	temp.h = this->h += other.h;
	temp.m = this->m += other.m;
	temp.s = this->s += other.s;
	return *this;
}

Timer Timer::operator+=(Timer const& other) {
	this->s += other.s;
	if (this->s >= 60.0) {
		this->m += 1;
		this->s = this->s - 60.0;
	}
	this->m += other.m;
	if (this->m >= 60) {
		this->h += 1;
		this->m = this->m - 60;
	}
	this->h -= other.h;
	if (this->h >= 24) {
		this->h = this->h - 24;
	}
	return *this;
}

Timer Timer::operator-(Timer const& other) {
	Timer temp;
	temp.h = this->h - other.h;
	temp.m = this->m - other.m;
	temp.s = this->s - other.s;
	return *this;
}

Timer Timer::operator-=(Timer const& other) {
	this->s -= other.s;
	if (this->s < 0) {
		this->m -= 1;
		this->s = 60.0 - this->s;
	}
	this->m -= other.m;
	if (this->m < 0) {
		this->h -= 1;
		this->m = 60 - this->m;
	}
	this->h -= other.h;
	if (this->h < 0) {
		this->h = 24 - this->h;
	}
	return *this;
}

Timer Timer::operator/(Timer const& other) {
	Timer temp;
	temp.h = this->h / other.h;
	temp.m = this->m / other.m;
	temp.s = this->s / other.s;
	return *this;
}

Timer Timer::operator/=(int n) {
	Timer temp;
	temp.h = this->h / n;
	temp.m = this->m / n;
	temp.s = this->s / n;
	return *this;
}

Timer Timer::operator/=(Timer const& other) {
	this->h /= other.h;
	this->m /= other.m;
	this->s /= other.s;
	return *this;
}

bool Timer::operator<(Timer const& other) {
	return (this->h < other.h) && (this->m < other.m) && (this->s < other.s);
}

ostream& operator<<(ostream& os, Timer const& time) {
	os << time.h << ":" << time.m << ":" << time.s << endl;
	return os;
}

void Timer::setS(double newS) {
	this->s = newS;
}

double Timer::getS() {
	return this->s;
}


class Penalty {
	friend class Timer;
	double m;
public:
	Penalty(double m) { this->m = m; }
	void operator() (Timer& time) {
		time.setS( time.getS() + m );
	}
};

#endif
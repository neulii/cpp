#include "Point.h"
#include <iostream>
#include <time.h>
#include "functions.h"
#include <ostream>

using namespace std;
Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::setCoord(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX() const {
	return  this->x;
}

int Point::getY() const {
	return this->y;
}

/*
		Vorher immer:
		srand(time(NULL));

*/
Point* Point::getRandomPoint(int rangeX,int rangeY){
	
	
	int x = getRandomInt(0, rangeX);
	int y = getRandomInt(0, rangeY);

	return new Point(x,y);
}

Point* Point::getRandomPoint(int startX, int rangeX, int startY, int rangeY) {

	int x = getRandomInt(startX, rangeX);
	int y = getRandomInt(startY, rangeY);
	
	return new Point(x, y);
}


void Point::showPoint() {
	//std::cout << "Speicheradresse: " << this << std::endl;
	std::cout << "X: " << x << " / Y: " << y << std::endl;

}

void Point::showAdress() {
	std::cout << "Adresse: " << this << std::endl;
}

Point Point::operator+(Point& p) {

	Point temp = Point(p.getX()+ this->getX(), p.getY() + this->getY());
	return temp;

}

Point& Point::operator++() {
	this->x++;
	this->y++;

	return *this;
}


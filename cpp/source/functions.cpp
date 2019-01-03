
#include "functions.h"
#include "SFML/Graphics.hpp"


using namespace std;
//=======================================================================================



bool isPointInside(sf::CircleShape circle, Point p) {
	bool isInside = false;

	double a = p.getX() - (circle.getPosition().x+circle.getRadius());
	double b = circle.getPosition().y+circle.getRadius() - p.getY();

	double c = sqrt((a * a) + (b * b));

	if (c <= circle.getRadius()) {
		isInside = true;
	}

	return isInside;
}

bool isPointInside(sf::CircleShape circle, sf::Vector2i p) {
	return isPointInside(circle, Point(p.x, p.y));
}

bool isPointInside(sf::CircleShape circle, int x, int y) {
	return isPointInside(circle, Point(x, y));
}

//======================================================================================

sf::Color getRandomColor() {

	return sf::Color(getRandomInt(255), getRandomInt(255), getRandomInt(255));
}

//=====================================================================================

/*
Zufallszahl zurückgeben
rand gehört noch mit srand initialisiert

		srand(time(NULL));
*/

int getRandomInt(int range) {

	return (rand() % (range+1));

}

int getRandomInt(int start, int range) {

	return (rand() % (range+1)) + start;

}

float getRandomFloat(float min, float max) {
	return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

float getRandomFloat(float range) {
	return getRandomFloat(0, range);
}

//=====================================================================================
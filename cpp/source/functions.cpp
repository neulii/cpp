
#include "functions.h"
#include "SFML/Graphics.hpp"


using namespace std;
//=======================================================================================

//bool isPointInside(sf::CircleShape circle, Point p);

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
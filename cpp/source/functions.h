#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdlib>
#include <ostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Point.h"

//====================================================================================
//bool isPointInside(sf::CircleShape circle, Point p) {
//	bool isInside = false;
//	
//	double a = p.getX() - circle.getPosition().x;
//	double b = circle.getPosition().y - p.getY();
//
//	double c = sqrt((a * a ) + (b * b));
//
//	if (c <= circle.getRadius()) {
//		isInside = true;
//	}
//
//	return isInside;
//}

//====================================================================================

sf::Color getRandomColor();

//=====================================================================================

/*
Zufallszahl zur�ckgeben
rand geh�rt noch mit srand initialisiert 

		srand(time(NULL));
*/

int getRandomInt(int range);
int getRandomInt(int start, int range);

float getRandomFloat(float min, float max);
float getRandomFloat(float range);


//=====================================================================================


#endif // !FUNCTIONS_H


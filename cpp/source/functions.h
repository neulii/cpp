#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdlib>
#include <ostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Point.h"


//====================================================================================


bool isPointInside(sf::CircleShape circle, Point p);
bool isPointInside(sf::CircleShape circle, sf::Vector2i p);
bool isPointInside(sf::CircleShape circle, int x, int y);


//====================================================================================

sf::Color getRandomColor();

//=====================================================================================

/*
Zufallszahl zurückgeben
rand gehört noch mit srand initialisiert 

		srand(time(NULL));
*/

int getRandomInt(int range);
int getRandomInt(int start, int range);

float getRandomFloat(float min, float max);
float getRandomFloat(float range);


//=====================================================================================


#endif // !FUNCTIONS_H


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdlib>
#include <ostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Point.h"


sf::Color getRandomColor();




//=====================================================================================

/*
Zufallszahl zur�ckgeben
rand geh�rt noch mit srand initialisiert 

		srand(time(NULL));
*/

int getRandomInt(int range);
int getRandomInt(int start, int range);

//=====================================================================================


#endif // !FUNCTIONS_H


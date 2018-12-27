

#include "functions.h"


using namespace std;

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

//=====================================================================================
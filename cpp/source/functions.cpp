#include <cstdlib>
#include <ostream>
#include "Point.h"

using namespace std;
//=====================================================================================

/*
Zufallszahl zur�ckgeben
rand geh�rt noch mit srand initialisiert

		srand(time(NULL));
*/

int getRandomInt(int range) {

	return (rand() % (range+1));

}

int getRandomInt(int start, int range) {

	return (rand() % (range+1)) + start;

}

//=====================================================================================
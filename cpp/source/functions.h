#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>


//=====================================================================================

/*
Zufallszahl zurückgeben
rand gehört noch mit srand initialisiert 

		srand(time(NULL));
*/

int getRandomInt(int range);
int getRandomInt(int start, int range);

//=====================================================================================


#endif // !FUNCTIONS_H


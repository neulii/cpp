#include "functions.h"
#include <iostream>
#include <conio.h>
#include "Point.h"
#include <vector>
#include "map.h"

using namespace std;

int main() {
	


	srand(time(NULL));

	Map *map = new Map(100, 20);

	for (int i = 0; i < 100; i++) {

		Point *temp = Point::getRandomPoint(0,100,0,20);
		//temp->showPoint();
		map->setPoint(*temp);


	}

	map->showMap();

	Point a = Point(3, 3);
	Point b = Point(2, 4);

	Point c = a + b;
	c.showPoint();
	++c;
	c.showPoint();





	_getch();


	return 0;
}
#include "map.h"
#include <iostream>
#include "Point.h"

Map::Map(int width, int height) {
	
	this->width = width;
	this->height = height;

	mapSize = width * height;
	
	map.assign(mapSize,0);

}

void Map::showValueMap() {

	for (int i = 0; i < map.size(); i++) {
		if ((i%width) == 0)
			cout << endl;
		
		cout << map.at(i);
	}
}

void Map::showMap() {
	for (int i = 0; i < map.size(); i++) {
		if ((i%width) == 0)
			cout << endl;

		if (map.at(i) == 0)
			cout << ".";
		else
			cout << "*";
	}
}

int Map::getValue(int x, int y) {
	
	int returnValue = -1;

	if (x < width && y < height) {
		int indexForValue = width * y + x;
		
		returnValue = map.at(indexForValue);
	}
	return returnValue;
}

bool Map::setValue(int value, int x, int y) {

	bool returnValue = false;

	if (x < width && y < height) {
		int indexForValue = y * width + x;
		map.at(indexForValue) = value;
		returnValue = true;
	}

	return returnValue;
}

bool Map::setPointAt(int x, int y) {
	return setValue(1, x, y);
}

bool Map::setPoint(const Point &p) {
	return setValue(1, p.getX(), p.getY());
}

int Map::getWidth() const {
	return width;
}

int Map::getHeight() const{
	return height;
}
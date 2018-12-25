#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include <vector>


using namespace std;

class Map {

private:
	int width;
	int height;
	int mapSize;

	vector<int> map;

public:
	Map(int width, int height);
	void showValueMap();
	void showMap();
	
	int getValue(int x, int y);
	bool setValue(int value, int x, int y);
	bool setPointAt(int x, int y);
	bool setPoint(const Point &p);

	int getWidth() const;
	int getHeight() const;

};

#endif // !


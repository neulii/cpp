#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point {

private:
	int x;
	int y;

public:
	Point();
	Point(int x, int y);
	void setCoord(int x, int y);
	void showPoint();
	void showAdress();

	int getX() const;
	int getY() const;

	static Point* getRandomPoint(int rangeX, int rangeY);
	static Point* getRandomPoint(int startX, int rangeX, int startY, int rangeY);

	Point operator+(Point& p);
	
	Point &operator++();

};

#endif // !POINT_H


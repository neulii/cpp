#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball {

private:
	int x;
	int y;
	int size;

	float speed;

	sf::Color color;
	sf::CircleShape circle;
	

	bool right;
	bool left;

	float gravity;

public:

	Ball(int x, int y, int size);
		
	void setRandomSpeed(float range);
	void setRandomSpeed(float min, float max);
	void setSpeed(float speed);
	float getSpeed();
	bool isInside(sf::Vector2i p);

	void render(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void setRandomColor();
};

#endif // !BALL_H


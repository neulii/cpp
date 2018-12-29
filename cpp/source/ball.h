#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball {

private:
	int x;
	int y;
	int size;

	sf::Color color;
	sf::CircleShape circle;

	float speedX;
	float speedY;

	float gravity;

public:

	Ball(int x, int y, int size);

	void render(sf::RenderWindow &window);
	void update();

};




#endif // !BALL_H


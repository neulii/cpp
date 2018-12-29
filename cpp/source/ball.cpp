#include "ball.h"

Ball::Ball(int x, int y, int size) {
	this->x = x;
	this->y = y;
	this->size = size;

	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(this->x, this->y));
	circle.setRadius(this->size);



}


void Ball::render(sf::RenderWindow &window)
{
	window.draw(circle);


}

void Ball::update()
{
}



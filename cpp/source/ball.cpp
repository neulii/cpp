#include "ball.h"
#include <iostream>
#include "functions.h"

Ball::Ball(int x, int y, int size) {
	this->x = x;
	this->y = y;
	this->size = size;

	speed = 0.1;
	right = true;
	left = false;

	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(this->x, this->y));
	circle.setRadius(this->size);
}


void Ball::render(sf::RenderWindow &window)
{
	window.draw(circle);
}

void Ball::update(sf::RenderWindow &window)
{
	
	//std::cout << circle.getPosition().x <<  "   " << right << "   " << left <<  std::endl;

	if (right) {
		if (circle.getPosition().x < (window.getSize().x)-2*circle.getRadius()) {
			circle.move(speed, 0);
		}
		else {
			setRandomColor();
			right = false;
			left = true;
		}
	}

	if (left) {

		if (circle.getPosition().x > 0) {
			circle.move(-1*speed, 0);
		}
		else {
			setRandomColor();
			left = false;
			right = true;
		}
	}
	
}

void Ball::setSpeed(float speed) {
	this->speed = speed;
}

float Ball::getSpeed() {
	return this->speed;
}

void Ball::setRandomColor() {
	circle.setFillColor(getRandomColor());
}

void Ball::setRandomSpeed(float range) {
	setSpeed(getRandomFloat(0, range));
}

void Ball::setRandomSpeed(float min, float max) {
	setSpeed(getRandomFloat(min, max));
}

bool Ball::isInside(sf::Vector2i p) {
	return isPointInside(circle, p);
}


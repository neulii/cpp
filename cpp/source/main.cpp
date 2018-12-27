#include <SFML/Graphics.hpp>
#include <iostream>
#include "functions.h"
#include <math.h>

using namespace std;

int main()
{
	
	double speedBall = 0;
	float  acc = 0;
	double speed = 0.1;
	srand(time(NULL));
	sf::Clock clock;
	bool start = false;
	
	

	sf::RenderWindow window(sf::VideoMode(800, 800), "my visual game");

	sf::CircleShape shape(50.f);
	sf::RectangleShape rs(sf::Vector2f(100, 100));
	
	sf::CircleShape ball(20);

	ball.setFillColor(sf::Color::Red);
	ball.setPosition(50, 0);


	
	rs.setFillColor(getRandomColor());
	rs.setOutlineColor(sf::Color::White);
	rs.setOutlineThickness(2);
	rs.setPosition(50, 50);

	shape.setPosition(100, 100);
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Blue);

	shape.setFillColor(sf::Color::Green);

	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Space) {
				
					
					
					clock.restart();
					start = true;
				
				}

				if (event.key.code == sf::Keyboard::Enter) {



					ball.setPosition(50, 0);


				}
			}
	
		
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			rs.move(-speed, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			rs.move(speed, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			rs.move(0, -speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			rs.move(0,speed);
		}

		long time = clock.getElapsedTime().asMilliseconds();

		speedBall = 9.81*time/1000;
		
		if (start) {

			
			if(ball.getPosition().y<window.getSize().y-50){
				cout << speedBall << endl;
				ball.move(0, speedBall);


			}
			else
			{
				start = false;
				
			}
		}
		
		window.clear();
		window.draw(shape);
		window.draw(rs);
		window.draw(ball);

		window.display();
	}

	return 0;
}
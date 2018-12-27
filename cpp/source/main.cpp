#include <SFML/Graphics.hpp>
#include <iostream>
#include "functions.h"



int main()
{
	float speed = 0.1;
	srand(time(NULL));



	sf::RenderWindow window(sf::VideoMode(800, 800), "my visual game");

	sf::CircleShape shape(50.f);
	sf::RectangleShape rs(sf::Vector2f(100, 100));
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

				std::cout << event.key.code  ;

				if (event.key.code == sf::Keyboard::Left) {
					left = true;
				}

				if (event.key.code == sf::Keyboard::Right) {
					right = true;
				}

				if (event.key.code == sf::Keyboard::Up) {
					up = true;
				}

				if (event.key.code == sf::Keyboard::Down) {
					down = true;
				}

				if (event.key.code == sf::Keyboard::Space) {
					rs.setFillColor(getRandomColor());
					rs.setOutlineColor(getRandomColor());
				}

				if (event.key.code == sf::Keyboard::A) {
					speed += 0.05;
				}

				if (event.key.code == sf::Keyboard::Y) {
					if(speed-0.05>0)
					speed -= 0.05;
				}

				if (event.key.code == sf::Keyboard::Enter) {

					rs.setPosition(sf::Vector2f(0, 0));
				}


			}

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Left) {
					left = false;
				}

			}

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Right) {
					right = false;
				}

			}

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					up = false;
				}

			}

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Down) {
					down = false;
				}

			}
		}

		if (left) {
			sf::Vector2f v(rs.getPosition());
			v.x = v.x - speed;

			rs.setPosition(v);

		}

		if (right) {
			sf::Vector2f v(rs.getPosition());
			v.x = v.x + speed;

			rs.setPosition(v);

		}

		if (up) {
			sf::Vector2f v(rs.getPosition());
			v.y = v.y - speed;

			rs.setPosition(v);

		}

		if (down) {
			sf::Vector2f v(rs.getPosition());
			v.y = v.y + speed;

			rs.setPosition(v);

		}

		window.clear();
		window.draw(shape);
		window.draw(rs);

		window.display();
	}

	return 0;
}
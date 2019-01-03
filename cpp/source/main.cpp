#include <SFML/Graphics.hpp>
#include "ball.h"
#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	const int WIDTH = 500;
	const int HEIGHT = 500;

	const int speedMin = 50;
	const int speedMax = 500;

	

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Balls");
	sf::Clock clock;
	sf::Font gameFont;
	sf::Text showFPS;
	sf::Text deltaTime;

	window.setFramerateLimit(60);

	sf::CircleShape test;
	test.setPosition(100, 100);
	test.setRadius(60);
	test.setOutlineColor(sf::Color::Blue);
	test.setFillColor(sf::Color::Black);
	test.setOutlineThickness(1);

	sf::Vertex line[2];
	
	int fps = 0;
	long elapsedTime = 0;

	srand(time(NULL));

	vector<Ball> balls;
	int numberOfBalls =50;
	int randomX = 0;

	/*for (int i = 0; i < 10; i++) {

		cout << getRandomInt(100) << endl;
	}*/

	for (int i = 0; i < numberOfBalls; i++) {
		
		int range = window.getSize().y-20;

		randomX = getRandomInt(range);
		//cout << randomX << endl;

		Ball *temp = new Ball(20, randomX, 20);
		temp->setRandomColor();
		temp->setRandomSpeed(speedMin,speedMax);

		balls.push_back(*temp);
	}
	
	gameFont.loadFromFile("arial.ttf");
	showFPS.setFont(gameFont);
	showFPS.setCharacterSize(20);
	showFPS.setString("0");
	showFPS.setStyle(sf::Text::Regular);
	
	deltaTime.setFont(gameFont);
	deltaTime.setString("0");
	deltaTime.setCharacterSize(20);
	deltaTime.setPosition(0, 20);



	clock.restart();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			

			if (event.type == sf::Event::MouseMoved)
			{
				/*std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
*/
				if (isPointInside(test, Point(event.mouseMove.x, event.mouseMove.y))) {
					test.setFillColor(sf::Color::Red);
					test.setOutlineColor(sf::Color::White);
				
				}
				else {
					test.setFillColor(sf::Color::Black);
					test.setOutlineColor(sf::Color::Blue);
				}
				
				line[0].position = sf::Vector2f(test.getPosition().x+test.getRadius(),test.getPosition().y+test.getRadius());
				line[1].position = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				//cout << "clicked" << endl;
				/*if (isPointInside(test, sf::Mouse::getPosition(window))) {
					cout << "inside" << endl;
					
				}*/
				for (int i = 0; i < balls.size(); i++) {
					if (balls.at(i).isInside(sf::Mouse::getPosition(window))) {
						balls.erase(balls.begin() + i);
						if (balls.size() <= 0) {
							exit(0);
						}

					}
					
				}
			}
			
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;


			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::A) {
					for (int i = 0; i < balls.size(); i++) {
						balls.at(i).setRandomSpeed(speedMin,speedMax);

					}
				}
				break;
			}
		}

		elapsedTime = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		
		fps = 1000000 / elapsedTime;

		showFPS.setString("FPS: " + std::to_string(fps));
		deltaTime.setString("dt: " + std::to_string(elapsedTime));

		//std::cout << fps << endl;
		/*ball.update(window);
		b->update(window);
		*/
	/*	ball.render(window);
		b->render(window);*/

		for (int i = 0; i < balls.size(); i++) {

			balls.at(i).update(window, elapsedTime);
			
			balls.at(i).render(window);

		}

		//window.draw(test);
		//window.draw(line,2,sf::Lines);

		window.draw(showFPS);
		window.draw(deltaTime);

		window.display();
		window.clear();
	}

	return 0;
}
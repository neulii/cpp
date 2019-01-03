#include <SFML/Graphics.hpp>
#include "ball.h"
#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 500;

	const int paddleSpeed = 3;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Balls");
	sf::Clock clock;
	sf::Font gameFont;

	sf::Text showFPS;
	sf::Text deltaTime;

	sf::Vector2f paddleSize(30, 100);

	sf::RectangleShape playerPaddle;
	sf::RectangleShape machinePaddle;

	playerPaddle.setFillColor(sf::Color::Blue);
	playerPaddle.setPosition(0, (HEIGHT / 2 - paddleSize.y / 2));

	machinePaddle.setFillColor(sf::Color::Blue);
	machinePaddle.setPosition(window.getSize().x - paddleSize.x, (HEIGHT / 2 - paddleSize.y / 2));

	playerPaddle.setSize(paddleSize);
	machinePaddle.setSize(paddleSize);


	

	window.setFramerateLimit(60);

	int fps = 0;
	long elapsedTime = 0;

	srand(time(NULL));

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
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;


			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Up) {
					
				}
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if(playerPaddle.getPosition().y>0)
				playerPaddle.move(0, -paddleSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if(playerPaddle.getPosition().y+paddleSize.y<HEIGHT)
				
				playerPaddle.move(0, paddleSpeed);
		}

		elapsedTime = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		fps = 1000000 / elapsedTime;

		showFPS.setString("FPS: " + std::to_string(fps));
		deltaTime.setString("dt: " + std::to_string(elapsedTime));

		window.draw(playerPaddle);
		window.draw(machinePaddle);



		window.draw(showFPS);
		window.draw(deltaTime);

		window.display();
		window.clear();
	}
	return 0;
}
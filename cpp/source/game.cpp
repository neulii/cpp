#include <SFML/Graphics.hpp>
#include <iostream>

//#define DEBUG


int main()
{

	const int ballSize = 20;
	const sf::Vector2f paddleSize(30,150 );
	const sf::Color ballColor = sf::Color::Red;
	const sf::Color paddleColor = sf::Color::Blue;

	bool gameIsRunning = false;

	bool ballToRight = true;
	bool ballToLeft = false;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

	sf::CircleShape ball;

	sf::RectangleShape playerPaddle;
	sf::RectangleShape machinePaddle;

	ball.setRadius(ballSize);
	ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y / 2 - ball.getRadius());
	ball.setFillColor(ballColor);

	playerPaddle.setSize(paddleSize);
	playerPaddle.setPosition(0, window.getSize().y / 2 - paddleSize.y / 2);
	playerPaddle.setFillColor(paddleColor);

	machinePaddle.setSize(paddleSize);
	machinePaddle.setPosition(window.getSize().x - paddleSize.x, window.getSize().y / 2 - paddleSize.y / 2);
	machinePaddle.setFillColor(paddleColor);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if(playerPaddle.getPosition().y>0)
				playerPaddle.move(0, -1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (playerPaddle.getPosition().y + playerPaddle.getSize().y < window.getSize().y)
				playerPaddle.move(0, 1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (!gameIsRunning) {
				gameIsRunning = true;
				ballToRight = true;
				ballToLeft = false;
			}
		}

		if (!gameIsRunning) {

			ball.setPosition(paddleSize.x, playerPaddle.getPosition().y + paddleSize.y / 2 - ball.getRadius());
		}
		else {

			
			if (gameIsRunning) {

				//std::cout << "isrunning  " << gameIsRunning << " balltoright:  " << ballToRight << std::endl;
			
				//Ball richtung Rechts
				if (ballToRight) {
				
					#ifdef DEBUG
						std::cout << "=========================================================" << std::endl;
						std::cout << (ball.getPosition().x > window.getSize().x - paddleSize.x - ball.getRadius() * 2) << std::endl;
						std::cout << (ball.getPosition().y > machinePaddle.getPosition().y) << std::endl;
						std::cout << (ball.getPosition().y < machinePaddle.getPosition().y + paddleSize.y) << std::endl;
					#endif // DEBUG
					
					//ball bewegen
					ball.move(0.5, 0);

					//bedingungen für maschine paddle
					bool ballIsRight = (ball.getPosition().x > window.getSize().x - paddleSize.x - ball.getRadius() * 2);
					bool ballIsUnderLimit = (ball.getPosition().y > machinePaddle.getPosition().y-ball.getRadius()*2);
					bool ballIsOverLimit = (ball.getPosition().y < machinePaddle.getPosition().y + paddleSize.y);
					
					//wenn ball paddle erwischt
					if(ballIsRight && ballIsOverLimit && ballIsUnderLimit){
						std::cout << "oh schreck" << std::endl;

						ballToRight = false;
						ballToLeft = true;
					}

					//Ball nicht gefangen
					if (ball.getPosition().x > window.getSize().x - ball.getRadius() * 2) {
						gameIsRunning = false;
					}
					
				}
				
				//Ball Richtung links
				if (ballToLeft) {
					ball.move(-0.5, 0);

					//ball nicht gefangen
					if (ball.getPosition().x < 0) {
						gameIsRunning = false;
					}

					//
				}
			}
		}

		window.draw(ball);
		window.draw(playerPaddle);
		window.draw(machinePaddle);

		window.display();
		window.clear();
	}



	return 0;
}
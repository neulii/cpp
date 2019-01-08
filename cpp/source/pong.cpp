#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

//#define DEBUG

int pong_main()
{
	
	float angle = 90;
	const int FPS = 60;
	float PI = 3.14;

	float ballSpeed = 10;
	
	float speedX = ballSpeed;
	float speedY = 0;

	const int paddleSpeed = 10;

	const int machineSpeed = 5;
	
	const int ballSize = 20;
	const sf::Vector2f paddleSize(30,150 );
	const sf::Color ballColor = sf::Color::Red;
	const sf::Color paddleColor = sf::Color::Blue;

	bool gameIsRunning = false;

	bool ballToRight = true;
	bool ballToLeft = false;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setFramerateLimit(FPS);

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
				playerPaddle.move(0, paddleSpeed*-1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (playerPaddle.getPosition().y + playerPaddle.getSize().y < window.getSize().y)
				playerPaddle.move(0, paddleSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (!gameIsRunning) {
				
				speedX = ballSpeed;
				speedY = 0;
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
			
				//Wenn ball oben oder unten 
				if (ball.getPosition().y <= 0 || ball.getPosition().y>window.getSize().y-ball.getRadius()*2) {
					speedY = -speedY;
				}

				//Computer paddle bewegen

				/*if (machinePaddle.getPosition().y > ball.getPosition().y + ball.getRadius()) {
					machinePaddle.move(0, -1*machineSpeed);
				
				}*/
				if (machinePaddle.getPosition().y+paddleSize.y/2 > ball.getPosition().y + ball.getRadius()) {
					if(machinePaddle.getPosition().y>0)
						machinePaddle.move(0, -1 * machineSpeed);

				}

				/*if (machinePaddle.getPosition().y + paddleSize.y < ball.getPosition().y + 2 * ball.getRadius()) {
					machinePaddle.move(0, machineSpeed);
				}*/

				if (machinePaddle.getPosition().y + paddleSize.y/2 < ball.getPosition().y + 2 * ball.getRadius()) {
					if (machinePaddle.getPosition().y + paddleSize.y < window.getSize().y)
					machinePaddle.move(0, machineSpeed);
				}

				//Ball richtung Rechts
				if (ballToRight) {
				
					#ifdef DEBUG
						std::cout << "=========================================================" << std::endl;
						std::cout << (ball.getPosition().x > window.getSize().x - paddleSize.x - ball.getRadius() * 2) << std::endl;
						std::cout << (ball.getPosition().y > machinePaddle.getPosition().y) << std::endl;
						std::cout << (ball.getPosition().y < machinePaddle.getPosition().y + paddleSize.y) << std::endl;
					#endif // DEBUG
					
					//ball bewegen
					ball.move(speedX, speedY);

					//bedingungen für maschine paddle
					bool ballIsRight = (ball.getPosition().x > window.getSize().x - paddleSize.x - ball.getRadius() * 2);
					bool ballIsUnderLimit = (ball.getPosition().y > machinePaddle.getPosition().y-ball.getRadius()*2);
					bool ballIsOverLimit = (ball.getPosition().y < machinePaddle.getPosition().y + paddleSize.y);
					
					//wenn ball paddle erwischt
					if(ballIsRight && ballIsOverLimit && ballIsUnderLimit){

						ballToRight = false;
						ballToLeft = true;
					
						float gk = machinePaddle.getPosition().y+paddleSize.y/2-ball.getPosition().y-ball.getRadius();
						float ak = paddleSize.x + ball.getRadius();

						std::cout << "ak: " << ak << "       gk: " << gk << std::endl;

						angle = std::atan(gk / ak)*180/PI;

						speedY = -1*std::sin(angle *PI/180)*ballSpeed;
						speedX = std::cos(angle *PI/180)*ballSpeed;
					
						std::cout << "angle: " << angle << "speedY : " << speedY << std::endl;
					}

					//Ball nicht gefangen
					if (ball.getPosition().x > window.getSize().x - ball.getRadius() * 2) {
						gameIsRunning = false;
						playerPaddle.setPosition(0, window.getSize().y / 2 - paddleSize.y / 2);
						machinePaddle.setPosition(window.getSize().x - paddleSize.x, window.getSize().y / 2 - paddleSize.y / 2);
					}
				}
				
				//Ball Richtung links
				if (ballToLeft) {

					//ball bewegen
					ball.move(-1*speedX, speedY);

					//bedingungen für menschen paddle
					bool ballIsLeft = (ball.getPosition().x < paddleSize.x);
					bool ballIsUnderLimit = (ball.getPosition().y > playerPaddle.getPosition().y - ball.getRadius() * 2);
					bool ballIsOverLimit = (ball.getPosition().y < playerPaddle.getPosition().y + paddleSize.y);

					//wenn ball paddle erwischt
					if (ballIsLeft && ballIsOverLimit && ballIsUnderLimit) {
						std::cout << "oh schreck" << std::endl;

						ballToRight = true;
						ballToLeft = false;

						float gk = playerPaddle.getPosition().y + paddleSize.y / 2 - ball.getPosition().y - ball.getRadius();
						float ak = paddleSize.x + ball.getRadius();

						std::cout << "ak: " << ak << "       gk: " << gk << std::endl;

						angle = std::atan(gk / ak) * 180 / PI;

						speedY = -1 * std::sin(angle *PI / 180)*ballSpeed;
						speedX = std::cos(angle *PI / 180)*ballSpeed;

						std::cout << "angle: " << angle << "speedY : " << speedY << std::endl;
					}

					//ball nicht gefangen
					if (ball.getPosition().x < 0) {
						gameIsRunning = false;
						playerPaddle.setPosition(0, window.getSize().y / 2 - paddleSize.y / 2);
						machinePaddle.setPosition(window.getSize().x - paddleSize.x, window.getSize().y / 2 - paddleSize.y / 2);
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
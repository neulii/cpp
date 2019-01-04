#include <SFML/Graphics.hpp>
#include <iostream>



int main()
{

	const int ballSize = 20;
	const sf::Vector2f paddleSize(20, 60);
	const sf::Color ballColor = sf::Color::Red;
	const sf::Color paddleColor = sf::Color::Blue;


	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

	sf::CircleShape ball;

	sf::RectangleShape playerPaddle;
	sf::RectangleShape machinePaddle;

	ball.setRadius(ballSize);
	ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y / 2 - ball.getRadius());
	ball.setFillColor(ballColor);







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



		window.draw(ball);

	


		window.display();
		window.clear();
	}



	return 0;
}
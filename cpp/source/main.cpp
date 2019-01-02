#include <SFML/Graphics.hpp>
#include "ball.h"
#include <iostream>
#include "functions.h"




using namespace std;

int main()
{
	const int WIDTH = 500;
	const int HEIGHT = 500;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Balls");
	sf::Clock clock;
	sf::Font gameFont;
	sf::Text showFPS;

	float fps = 0;
	long elapsedTime = 0;

	srand(time(NULL));

	vector<Ball> balls;
	int numberOfBalls =4000;
	int randomX = 0;

	/*for (int i = 0; i < 10; i++) {

		cout << getRandomInt(100) << endl;
	}*/



	for (int i = 0; i < numberOfBalls; i++) {
		
		int range = window.getSize().y;

		randomX = getRandomInt(range);
		//cout << randomX << endl;

		


		Ball *temp = new Ball(20, randomX, 20);
		temp->setRandomColor();
		temp->setRandomSpeed(0.2,1.5);


		balls.push_back(*temp);
		

	}
	
	

	gameFont.loadFromFile("arial.ttf");
	showFPS.setFont(gameFont);
	showFPS.setCharacterSize(20);
	showFPS.setString("0");
	showFPS.setStyle(sf::Text::Regular);
	

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
				if (event.key.code == sf::Keyboard::A) {
					for (int i = 0; i < balls.size(); i++) {
						balls.at(i).setRandomSpeed(0.2,2);

					}

				}
				break;
			}
		}

		
		
		elapsedTime = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		
		fps = 1000000 / elapsedTime;

		showFPS.setString(std::to_string(fps));
		//std::cout << fps << endl;
		/*ball.update(window);
		b->update(window);
		*/
	/*	ball.render(window);
		b->render(window);*/

		for (int i = 0; i < balls.size(); i++) {

			balls.at(i).render(window);
			balls.at(i).update(window);


		}



		window.draw(showFPS);


		window.display();
		window.clear();
	}

	
	return 0;
}



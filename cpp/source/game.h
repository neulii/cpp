#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ball.h"


class Game {

private:
	
	const int HEIGHT = 400;
	const int WIDTH = 600;
	
	sf::RenderWindow window;

	void processEvents();
	void update();
	void render();

	Ball* ball;
	
	

public:

	Game();
	void run();

};

#endif

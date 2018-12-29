#include "game.h"
#include "ball.h"

Game::Game(){

	window.create(sf::VideoMode(WIDTH, HEIGHT), "Balls");
	window.setFramerateLimit(60);

	
	ball = new Ball(20, 20, 20);

	




}

void Game::update() {

}

void Game::processEvents() {

	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		}

	}

}

void Game::render() {
	window.clear();
	
	//draw()
	ball->render(window);

	
	window.display();
}

void Game::run() {

	while (window.isOpen()) {

		processEvents();
		update();
		render();
	}
}




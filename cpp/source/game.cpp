#include "game.h"

Game::Game(){

	window.create(sf::VideoMode(600, 600), "Balls");
	window.setFramerateLimit(60);

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

	window.display();
}

void Game::run() {

	while (window.isOpen()) {

		processEvents();
		update();
		render();
	}
}




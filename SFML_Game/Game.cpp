#include "Game.h"

// Metoda inicjalizuj�ca okno gry
void Game::initWindow() {
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Platformer Game");
}

// Definicja konstruktora/destruktora
Game::Game() {
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}

// Definicje funkcji

// Aktualizacja logiki gry - metoda aktualizacji (np. ruchy postaci, fizyka)
void Game::update() {
    this->processEvents();
}

// Metoda do renderowania grafiki 
void Game::render() {
    // Czyszczenie obrazu
    this->window->clear(sf::Color::Black);

    // Renderowanie grafiki
    this->window->display();
}

// Obs�uga wej�cia od u�ytkownika
void Game::processEvents() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }
    }
}

// Funkcja obs�uguj�ca p�tl� gry
void Game::run() {
    // Dop�ki okno gry jest otwarte
    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}
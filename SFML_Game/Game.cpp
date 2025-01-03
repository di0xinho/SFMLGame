#include "Game.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

// Metoda inicjalizuj¹ca okno gry
void Game::initWindow() {
	
    // Tworzymy strumien wejsciowy do wczytania pliku json z ustawieniami graficznymi
    std::ifstream file("Config/graphics.json");

    // Sprawdzamy czy plik zostal otwarty poprawnie
    if (!file.is_open()) {
        std::cerr << "Nie mozna wczytac pliku konfiguracyjnego" << std::endl;
        exit(1);
    }

    // Tworzymy obiekt, ktory bedzie przechowywac dane z configu
    nlohmann::json configuration;

    // Odczytywanie pliku konfiguracyjnego i deserializacja do obiektu "configuration"
    file >> configuration;

    // Dane wczytujemy do poszczegolnych zmiennych
    std::string title = configuration.at("name").get<std::string>();
    int height = configuration.at("window_height").get<int>();
    int width = configuration.at("window_width").get<int>();
    unsigned int frame_limit = configuration.at("framelimit").get<int>();
    bool verticalSync = configuration.at("verticalSync").get<bool>();

    this->window = new sf::RenderWindow(sf::VideoMode(height, width), title);
    this->window->setFramerateLimit(frame_limit);
    this->window->setVerticalSyncEnabled(verticalSync);
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

void Game::updateDeltaTime() {
    this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

// Metoda do renderowania grafiki 
void Game::render() {
    // Czyszczenie obrazu
    this->window->clear(sf::Color::Black);

    // Renderowanie grafiki
    this->window->display();
}

// Obs³uga wejœcia od u¿ytkownika
void Game::processEvents() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }
    }
}

// Funkcja obs³uguj¹ca pêtlê gry
void Game::run() {
    // Dopóki okno gry jest otwarte
    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}
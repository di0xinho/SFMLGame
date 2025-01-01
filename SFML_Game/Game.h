#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game {
public:
    // Konstuktory / destruktory
    Game();
    ~Game();

    // Metoda do uruchomienia p�tli gry
    void run();

    void processEvents();    // Obs�uga wej�cia
    void update();           // Metoda aktualizacji
    void render();           // Renderowanie grafiki

private:

    // Zmienne 
    sf::RenderWindow* window;
    sf::Event event;

    // Funkcje
    void initWindow();


};

#endif 

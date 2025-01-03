#ifndef GAME_HPP
#define GAME_HPP

#include "State.h"

class Game {
public:
    // Konstuktory / destruktory
    Game();
    ~Game();

    // Metoda do uruchomienia p�tli gry
    void run();

    void processEvents();    // Obs�uga wej�cia
    void update();           // Metoda aktualizacji
    void updateDeltaTime();
    void render();           // Renderowanie grafiki

private:

    // Zmienne 
    sf::RenderWindow* window;
    sf::Event event;

    float deltaTime;
    sf::Clock deltaTimeClock;

    // Funkcje
    void initWindow();


};

#endif 

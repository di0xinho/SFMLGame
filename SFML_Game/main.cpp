#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
     
    }

    return 0;
}

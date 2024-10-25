#include <SFML/Graphics.hpp>

int main() {
    // Tworzymy okno
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Projekt");

    // Prostok�t
    sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f)); // Wymiary prostok�ta: 200x100 pikseli
    rectangle.setPosition(300.f, 250.f); // Ustawiamy pozycj� prostok�ta
    rectangle.setFillColor(sf::Color::Green); // Ustawiamy kolor wype�nienia na zielony

    // G��wna p�tla gry
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Czy�cimy okno
        window.clear();

        // Rysujemy prostok�t
        window.draw(rectangle);

        // Wy�wietlamy wszystko na ekranie
        window.display();
    }

    return 0;
}

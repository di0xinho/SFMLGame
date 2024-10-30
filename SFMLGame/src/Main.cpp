#include <SFML/Graphics.hpp>

int main() {
    // Tworzymy okno
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Projekt");

    // Prostok¹t
    sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f)); // Wymiary prostok¹ta: 200x100 pikseli
    rectangle.setPosition(300.f, 250.f); // Ustawiamy pozycjê prostok¹ta
    rectangle.setFillColor(sf::Color::Green); // Ustawiamy kolor wype³nienia na zielony

    // G³ówna pêtla gry
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Czyœcimy okno
        window.clear();

        // Rysujemy prostok¹t
        window.draw(rectangle);

        // Wyœwietlamy wszystko na ekranie
        window.display();
    }

    return 0;
}

#ifndef STATE_H
#define STATE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class State
{
public:
	State();
	virtual ~State();

	virtual void update() = 0;
	virtual void render() = 0;

private:
	std::vector<sf::Texture> textures;
};

#endif 

#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

#include "ResourceManager.h"
#include "State.h"

struct Game
{
	// Engine Related
	sf::RenderWindow* window;
	ResourceManager<sf::Texture>* textureManager;
	ResourceManager<sf::Font>* fontManager;
	std::stack<State*>* states;

	// Game Related
};
#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <map>

#include "ResourceManager.h"
#include "State.h"

// Game struct being passed through
// all game classes
struct Game
{
	// Engine Related
	sf::RenderWindow* window;
	ResourceManager<sf::Texture>* textureManager;
	ResourceManager<sf::Font>* fontManager;
	std::stack<State*>* states;

	// Game Related
};
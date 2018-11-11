#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include <memory>

#include "Game.h"
#include "ResourceManager.h"
#include "State.h"
#include "MenuState.h"

class Application
{
public:

	Application(unsigned int width, unsigned int height, const std::string& title);
	~Application();

	void run();

private:

	sf::RenderWindow m_Window;
	sf::Clock m_Timer;

	std::unique_ptr<ResourceManager<sf::Texture>> m_TextureManager;
	std::unique_ptr<ResourceManager<sf::Font>> m_FontManager;

	std::stack<State*> m_States;
	std::unique_ptr<MenuState> m_InitialState;

	Game m_Data;

};
#include "Application.h"

Application::Application(unsigned int width, unsigned int height, const std::string& title)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	m_Window.create(sf::VideoMode(width, height), title, sf::Style::Close, settings);

	m_TextureManager = std::make_unique<ResourceManager<sf::Texture>>("res/textures");
	m_FontManager = std::make_unique<ResourceManager<sf::Font>>("res/fonts");

	m_Data.window = &m_Window;
	m_Data.textureManager = m_TextureManager.get();
	m_Data.fontManager = m_FontManager.get();
	m_Data.states = &m_States;

	m_InitialState = std::make_unique<MenuState>(m_Data);
	m_States.push(m_InitialState.get());
}

Application::~Application()
{
}

void Application::run()
{
	float currFrame, prevFrame = 0.f;
	float deltaTime;

	while (m_Window.isOpen())
	{
		currFrame = m_Timer.getElapsedTime().asSeconds();
		deltaTime = currFrame - prevFrame;
		prevFrame = currFrame;

		m_States.top()->handleInput(deltaTime);
		m_States.top()->update(deltaTime);
		m_States.top()->render();
	}
}
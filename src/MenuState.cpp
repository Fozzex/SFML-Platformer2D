#include "MenuState.h"

MenuState::MenuState(const Game& data) :
	m_GameData(data)
{
	m_Menu = Menu(m_GameData);
	m_Menu.setTheme({ 80, 80, 80, 100 }, { 200, 200, 200, 100 });
	m_PlayingState = std::make_unique<PlayingState>(m_GameData);

	int playButton		= m_Menu.addButton("Play");
	int settingsButton  = m_Menu.addButton("Settings");
	int exitButton		= m_Menu.addButton("Exit");

	// Button Callbacks
	m_Menu.setCallbackState(playButton, m_PlayingState.get());

	m_Menu.setCallback(settingsButton, []() 
	{ 
		std::cout << "Who needs settings anyway, amirite?" << std::endl; 
	});

	m_Menu.setCallback(exitButton, [&]()
	{
		m_GameData.window->close();
	});

	m_Menu.setButtonSize({ 250, 50 });
	m_Menu.setCentre();

	m_BGSurface.setSize({ 1280, 720 });
	m_BGSurface.setTexture(&m_GameData.textureManager->getResource("background.jpg"));
}

MenuState::~MenuState()
{
}

void MenuState::handleInput(float dt)
{
	sf::Event evnt;
	while (m_GameData.window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			m_GameData.window->close();
			break;
		}

		m_Menu.updateEvents(evnt);
	}
}

void MenuState::update(float dt)
{
	m_Menu.update();
}

void MenuState::render()
{
	m_GameData.window->clear(); // Begin Frame

	m_GameData.window->draw(m_BGSurface);
	m_GameData.window->draw(m_Menu);

	m_GameData.window->display(); // End Frame
}
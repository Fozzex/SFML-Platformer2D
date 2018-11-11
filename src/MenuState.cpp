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

	m_Menu.setCallbackState(playButton, m_PlayingState.get());
	m_Menu.setCallback(settingsButton, []()
	{
		std::cout << "The Settings menu hasn't been created yet.. Sorry :(" << std::endl;
	});
	m_Menu.setCallbackExit(exitButton);

	m_Menu.setButtonSize({ 200, 50 });
	m_Menu.setCentre();
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

	m_GameData.window->draw(m_Menu);

	m_GameData.window->display(); // End Frame
}
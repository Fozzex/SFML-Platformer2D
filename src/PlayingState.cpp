#include "PlayingState.h"

PlayingState::PlayingState(const Game& game) :
	m_GameData(game)
{
	m_Player = std::make_unique<Player>(m_GameData);
}

PlayingState::~PlayingState()
{
}

void PlayingState::handleInput(float dt)
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

		m_Player->handleInput(evnt, dt);
	}
}

void PlayingState::update(float dt)
{
	m_Player->update(dt);
}

void PlayingState::render()
{
	m_GameData.window->clear(); // Begin Frame
	m_Player->render();
	m_GameData.window->display(); // End Frame
}
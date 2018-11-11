#include "PlayingState.h"

PlayingState::PlayingState(const Game& game) :
	m_GameData(game)
{
	mario.setTexture(m_GameData.textureManager->getResource("mario.png"));
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
	}
}

void PlayingState::update(float dt)
{

}

void PlayingState::render()
{
	m_GameData.window->clear(); // Begin Frame

	m_GameData.window->draw(mario);

	m_GameData.window->display(); // End Frame
}
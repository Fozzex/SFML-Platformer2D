#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Config.h"

class Player
{
public:

	Player(const Game& game);
	~Player();

	void handleInput(const sf::Event& evnt, float dt);
	void update(float dt);
	void render();

private:

	Game m_GameData;

	sf::RectangleShape m_Body;
	sf::Vector2f m_Velocity;
	bool onGround = false;

};
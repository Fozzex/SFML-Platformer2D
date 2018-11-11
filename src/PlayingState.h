#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class PlayingState : public State
{
public:

	PlayingState(const Game& game);
	~PlayingState();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

private:

	Game m_GameData;
	sf::Sprite mario;

};
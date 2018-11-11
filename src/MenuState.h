#pragma once
#include "Game.h"
#include "State.h"
#include "PlayingState.h"
#include "Menu.h"

class MenuState : public State
{
public:

	MenuState(const Game& data);
	~MenuState();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

private:

	Game m_GameData;
	Menu m_Menu;

	std::unique_ptr<PlayingState> m_PlayingState;

};
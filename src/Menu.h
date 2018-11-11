#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <iostream>

#include "State.h"
#include "Game.h"

using Callback = void(*)();

class Menu : public sf::Drawable
{
public:

	Menu();
	Menu(const Game& data);
	~Menu();

	void updateEvents(const sf::Event& evnt);
	void update();

	void setTheme(const sf::Color& idle, const sf::Color& hover);
	void setPosition(const sf::Vector2f& position);
	void setButtonSize(const sf::Vector2f& size);
	void setCentre();
	int addButton(const std::string& text);
	void setCallback(int index, Callback function);
	void setCallbackState(int index, State* state);
	void setCallbackExit(int index);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	void updateButtons();
	void alignTextCentre(const sf::FloatRect& rect, sf::Text& text);

private:

	struct Button
	{
		sf::RectangleShape button;
		sf::Text text;
		State* callbackState = nullptr;
		Callback callback = nullptr;
		bool isHover = false;
		bool isExit = false;
	};

	sf::Font m_Font;
	Game m_GameData;
	std::vector<Button> m_Buttons;
	sf::Vector2f m_Position = sf::Vector2f(0, 0); // Top left
	sf::Vector2f m_Size = sf::Vector2f(100, 40);
	sf::Color m_IdleColour, m_HoverColour;

};
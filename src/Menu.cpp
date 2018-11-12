#include "Menu.h"
#include "Game.h"

Menu::Menu()
{
}

Menu::Menu(const Game& data) :
	m_GameData(data)
{
}

Menu::~Menu()
{
}

void Menu::updateEvents(const sf::Event& evnt)
{
	switch (evnt.type)
	{
	case sf::Event::MouseButtonReleased:
		if (evnt.mouseButton.button == sf::Mouse::Left)
		{
			for (auto& button : m_Buttons)
			{
				if (button.isHover)
				{
					if (button.callback != nullptr)
					{
						button.callback();
					}

					if (button.callbackState != nullptr)
					{
						m_GameData.states->pop();
						m_GameData.states->push(button.callbackState);
					}
				}
			}
		}
	}
}

void Menu::update()
{
	sf::Vector2f mousePosition = (sf::Vector2f)sf::Mouse::getPosition(*m_GameData.window);
	for (auto& button : m_Buttons)
	{
		if (button.button.getGlobalBounds().contains(mousePosition))
		{
			button.isHover = true;
			button.button.setFillColor(m_HoverColour);
		}
		else
		{
			button.isHover = false;
			button.button.setFillColor(m_IdleColour);
		}
	}
}

void Menu::setTheme(const sf::Color& idle, const sf::Color& hover)
{
	m_IdleColour = idle;
	m_HoverColour = hover;
}

void Menu::setCentre()
{
	m_Position.x = (m_GameData.window->getSize().x / 2) - (m_Size.x / 2);
	m_Position.y = (m_GameData.window->getSize().y / 2) - (m_Size.y * m_Buttons.size() / 2);
	this->updateButtons();
}

void Menu::setPosition(const sf::Vector2f& position)
{
	m_Position = position;
	this->updateButtons();
}

void Menu::setButtonSize(const sf::Vector2f& size)
{
	m_Size = size;
	this->updateButtons();
}

int Menu::addButton(const std::string& text)
{
	int index = m_Buttons.size();

	Button button;
	button.button.setPosition(m_Position.x, m_Position.y + (m_Size.y * index));
	button.button.setSize(m_Size);
	button.button.setFillColor(m_IdleColour);
	
	m_Font = m_GameData.fontManager->getResource("arial.ttf");
	button.text.setFont(m_Font);

	button.text.setFillColor({ 255, 255, 255 });

	button.text.setString(text);
	this->alignTextCentre({ button.button.getPosition(), m_Size }, button.text);

	m_Buttons.push_back(button);
	return index;
}

void Menu::setCallback(int index, Callback function)
{
	m_Buttons[index].callback = function;
}

void Menu::setCallbackState(int index, State* state)
{
	m_Buttons[index].callbackState = state;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& button : m_Buttons)
	{
		target.draw(button.button);
		target.draw(button.text);
	}
}

void Menu::updateButtons()
{
	for (unsigned int i = 0; i < m_Buttons.size(); i++)
	{
		m_Buttons[i].button.setSize(m_Size);
		m_Buttons[i].button.setPosition(m_Position.x, m_Position.y + (m_Size.y * i));
		this->alignTextCentre({ m_Buttons[i].button.getPosition(), m_Size }, m_Buttons[i].text);
	}
}

void Menu::alignTextCentre(const sf::FloatRect& rect, sf::Text& text)
{
	sf::Vector2f position;

	position.x = rect.left - (text.getLocalBounds().width / 2) + (rect.width / 2) - text.getLocalBounds().left;
	position.y = rect.top - (text.getLocalBounds().height / 2) + (rect.height / 2) - text.getLocalBounds().top;

	text.setPosition(position);
}
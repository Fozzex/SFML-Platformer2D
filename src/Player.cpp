#include "Player.h"

Player::Player(const Game& game) :
	m_GameData(game)
{
	m_Body.setSize({ 50, 50 });
	m_Body.setFillColor({ 255, 255, 255 });
	m_Body.setPosition({ 0, 0 });
}

Player::~Player()
{
}

void Player::handleInput(const sf::Event& evnt, float dt)
{

}

void Player::update(float dt)
{
	m_Velocity.y += cfg::GRAVITY * dt * cfg::PLAYER_MASS;
	m_Body.move(m_Velocity * dt * cfg::PLAYER_MASS);

	onGround = false;
	if (m_Body.getPosition().y >= m_GameData.window->getSize().y - m_Body.getSize().y)
	{
		m_Velocity.y = 0;
		onGround = true;

		m_Body.setPosition(m_Body.getPosition().x, m_GameData.window->getSize().y - m_Body.getSize().y);
	}

	if (onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_Velocity.y -= cfg::JUMP_FORCE;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Velocity.x -= cfg::ACCELERATION * dt * cfg::PLAYER_MASS;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Velocity.x += cfg::ACCELERATION * dt * cfg::PLAYER_MASS;
	}

	if (onGround)
	{
		float appliedFriction = cfg::FRICTION * dt * cfg::PLAYER_MASS;
		if (m_Velocity.x > appliedFriction)
		{
			m_Velocity.x -= appliedFriction;
		}
		else if (m_Velocity.x < -appliedFriction)
		{
			m_Velocity.x += appliedFriction;
		}
		else
		{
			m_Velocity.x = 0;
		}
	}

	if (m_Velocity.x > cfg::MAX_SPEED)
		m_Velocity.x = cfg::MAX_SPEED;

	if (m_Velocity.x < -cfg::MAX_SPEED)
		m_Velocity.x = -cfg::MAX_SPEED;
}

void Player::render()
{
	m_GameData.window->draw(m_Body);
}
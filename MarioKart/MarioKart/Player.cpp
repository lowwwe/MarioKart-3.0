#include "Player.h"
#include <iostream>
#include "Game.h"


/// <summary>
/// setup the player assets
/// </summary>
void Player::initialise()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\mario.png"))
	{
		std::cout << "problem with player" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture,true);
	resetPosition();
}

/// <summary>
/// draw the player
/// </summary>
/// <param name="t_window">game window</param>
void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerSprite);
}


/// <summary>
/// update the player
/// </summary>
/// <param name="t_deltaTime">time not used</param>
void Player::update(sf::Time t_deltaTime)
{
	fall();
	m_playerSprite.setPosition(m_playerLocation);
}

/// <summary>
/// jump
/// </summary>
void Player::jump()
{
	m_playerLocation.y -= 100.0f;
	m_playerSprite.setPosition(m_playerLocation);
}

/// <summary>
/// apply gravity
/// </summary>
void Player::fall()
{
	if (m_playerLocation.y < m_roadLevel)
	{
		m_playerLocation.y += 1.4f;
	}
}

/// <summary>
/// move the player left
/// and flip if not already pointing left
/// </summary>
void Player::left()
{
	m_playerLocation.x -= m_speed;
	if (m_playerSprite.getScale().x == 1.0f)
	{
		m_playerSprite.setScale(sf::Vector2f{ -1.0f, 1.0f });
		m_playerLocation.x += 118.0f;
	}
}

/// <summary>
/// move player right
/// flip right if needed
/// </summary>
void Player::right()
{
	m_playerLocation.x += m_speed;
	if (m_playerSprite.getScale().x == -1.0f)
	{
		m_playerSprite.setScale(sf::Vector2f{ 1.0f, 1.0f });
		m_playerLocation.x -= 118.0f;
	}

}

/// <summary>
/// chek if player is off screen
/// </summary>
/// <returns></returns>
bool Player::departed()
{
	if (m_playerLocation.x < 0 || m_playerLocation.x > WIDTH)
	{
		return true;
	}
	return false;
}

/// <summary>
/// return player to starting position
/// </summary>
void Player::resetPosition()
{
	float posX = WIDTH / 2.0f;
	m_playerLocation = sf::Vector2f(posX, m_roadLevel);
	m_playerSprite.setPosition(m_playerLocation);
}

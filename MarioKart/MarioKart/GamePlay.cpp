#include "GamePlay.h"
#include "Game.h"
#include <iostream>

/// <summary>
/// set up the game play assets
/// </summary>
void GamePlay::initialise()
{
	if (!m_backbroundTexture.loadFromFile("ASSETS\\IMAGES\\background.jpg"))
	{
		std::cout << "problem with background" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backbroundTexture,true);
	float scaleX = WIDTH / static_cast<float>(m_backbroundTexture.getSize().x);
	float scaleY = static_cast<float>(HEIGHT) / m_backbroundTexture.getSize().y;
	m_backgroundSprite.setScale(sf::Vector2f{ scaleX, scaleY });
	m_backgroundSprite.setPosition(sf::Vector2f{ 0.0f, 0.0f });
	m_player.initialise();
}


/// <summary>
/// draw the game screen
/// </summary>
/// <param name="t_window">game window to draw to</param>
void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	m_player.render(t_window);
}


/// <summary>
/// handle user input for game play
/// </summary>
/// <param name="t_event"></param>
void GamePlay::processEvents(const std::optional<sf::Event> t_event)
{
	if (t_event->is<sf::Event::KeyPressed>()) //user pressed a key
	{
		const sf::Event::KeyPressed* newKeypress = t_event->getIf<sf::Event::KeyPressed>();
		if(sf::Keyboard::Key::Up == newKeypress->code && m_jumpWait == 0)
		{
			m_jumpKeyPressed = true;
		} 
		if (sf::Keyboard::Key::Escape == newKeypress->code)
		{
			Game::s_currentMode = GameMode::Pause;
		}
	}
}

/// <summary>
/// update the game world
/// </summary>
/// <param name="t_deltaTime">delta time not used</param>
void GamePlay::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		m_player.right();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		m_player.left();
	}
	m_player.update(t_deltaTime);
	if (m_player.departed())
	{
		Game::s_currentMode = GameMode::Menu;
		m_player.resetPosition();
	}
	if (m_jumpKeyPressed)
	{
		m_player.jump();
		m_jumpKeyPressed = false;
		m_jumpWait = 35; // half a second
	}
	if (m_jumpWait > 0)
	{
		m_jumpWait--;
	}
}

#include "Licence.h"
#include "Game.h"

/// <summary>
/// setup the license screen assets
/// </summary>
/// <param name="t_font">single font from game class</param>
void Licence::intialise(sf::Font& t_font)
{
	float xPos; // left co ordinate for text
	sf::FloatRect boundingBox; // bounding box for text
	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setString("Handmade by Pete");
	m_message.setFillColor(sf::Color::White);
	m_message.setCharacterSize(24U);
	

	boundingBox = m_message.getLocalBounds();
	xPos = WIDTH / 2 - boundingBox.size.x / 2.0f;
	m_message.setPosition(sf::Vector2f{ xPos, 200.f });
	m_cumulativeTime = sf::seconds(0.0f);


}

/// <summary>
/// draw the licence screen
/// </summary>
/// <param name="t_window">game window</param>
void Licence::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_message);
}


/// <summary>
/// update the screen switch modes when time is up
/// </summary>
/// <param name="t_deltaTime">time interval 1/60 sec</param>
void Licence::update(sf::Time t_deltaTime)
{
	m_cumulativeTime += t_deltaTime;
	if (m_cumulativeTime.asSeconds() > 1.0f)
	{
		Game::s_currentMode = GameMode::Splash;
	}
}

#include "Splash.h"
#include "Game.h"
#include <iostream>


/// <summary>
/// setup the splash screen
/// </summary>
/// <param name="t_font"></param>
void Splash::initialise(sf::Font& t_font)
{
	float xPos; // left co ord of centered text
	sf::FloatRect boundingBox; // bounding box of text
	if (!m_wallPaperTexture.loadFromFile("ASSETS\\IMAGES\\splash.jpg"))
	{
		std::cout << "problem with wall paper" << std::endl;
	}
	m_wallPaperTexture.setRepeated(true);
	m_wallPaperSprite.setTexture(m_wallPaperTexture);
	m_wallPaperSprite.setTextureRect(sf::IntRect{ sf::Vector2i{0, 0},sf::Vector2i{ WIDTH, HEIGHT} });

	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setString("Press any key to continue");
	m_message.setFillColor(sf::Color::Yellow);
	m_message.setOutlineColor(sf::Color::Black);
	m_message.setOutlineThickness(1.0f);
	m_message.setCharacterSize(24U);

	boundingBox = m_message.getLocalBounds();
	xPos = WIDTH / 2 - boundingBox.size.x / 2.0f;
	m_message.setPosition(sf::Vector2f{ xPos, 400.0f });


}

/// <summary>
/// draw the splash screen
/// </summary>
/// <param name="t_window">game window</param>
void Splash::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_wallPaperSprite);
	t_window.draw(m_message);
}


/// <summary>
/// handle input for the splash screen
/// </summary>
/// <param name="t_event"></param>
void Splash::processEvents(const std::optional<sf::Event> t_event)
{
	if (t_event->is<sf::Event::KeyPressed>() || t_event->is<sf::Event::MouseButtonReleased>()) //user pressed a key or mouse
	{	
		Game::s_currentMode = GameMode::Menu;
	}	
}

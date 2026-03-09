#include "Menu.h"
#include <iostream>
#include "game.h"

/// <summary>
/// setupo the menu assets
/// </summary>
/// <param name="t_font"></param>
void Menu::initialise(sf::Font& t_font)
{
	m_font = t_font;
	float textDropOffset = 23.0f;
	std::string menuTexts[] = { "Play" , "Help", "Quit" };
	sf::Vector2u textureSize;
	if (!m_buttonTexture.loadFromFile("ASSETS\\IMAGES\\button.png"))
	{
		std::cout << "problem with button" << std::endl;
	}
	m_buttonSprite.setTexture(m_buttonTexture,true);
	textureSize = m_buttonTexture.getSize();
	float scaleX = BUTTON_WIDTH / textureSize.x;
	float scaleY = BUTTON_HEIGHT / textureSize.y;
	m_buttonSprite.setScale(sf::Vector2f{ scaleX, scaleY });
	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		m_buttonLocations[i] = sf::Vector2f{ BUTTON_LEFT, TOP_OFFSET + (GAP + BUTTON_HEIGHT) * i };
		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setFillColor(sf::Color::Black);
		m_buttonTexts[i].setCharacterSize(24U);
		m_buttonTexts[i].setString(menuTexts[i]);
		sf::FloatRect box = m_buttonTexts[i].getLocalBounds();
		float offset = (BUTTON_WIDTH - box.size.x) / 2.0f;
		m_buttonTexts[i].setPosition(sf::Vector2f{ BUTTON_LEFT + offset, TOP_OFFSET + textDropOffset + (GAP + BUTTON_HEIGHT) * i });

	}

}

/// <summary>
/// menu doesn't change just reacts to events
/// here for future code
/// </summary>
/// <param name="t_deltaTime">unused</param>
void Menu::update(sf::Time t_deltaTime)
{
}

/// <summary>
/// draw the menu
/// </summary>
/// <param name="t_window">game window</param>
void Menu::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		m_buttonSprite.setPosition(m_buttonLocations[i]);
		t_window.draw(m_buttonSprite);
		t_window.draw(m_buttonTexts[i]);
	}
}


/// <summary>
/// react to mouse releases
/// </summary>
/// <param name="t_event">game event</param>
void Menu::processEvents(const std::optional<sf::Event> t_event)
{
	sf::Vector2i mouse;
	if (t_event->is<sf::Event::MouseButtonReleased>())
	{
		const sf::Event::MouseButtonReleased* newMouseReelease = t_event->getIf<sf::Event::MouseButtonReleased>();

		mouse = newMouseReelease->position;
		
		if (mouse.x > BUTTON_LEFT && mouse.x < BUTTON_LEFT + BUTTON_WIDTH)
		{
			if (mouse.y > TOP_OFFSET && mouse.y < TOP_OFFSET + BUTTON_HEIGHT)
			{
				Game::s_currentMode = GameMode::GamePlay;
			}
			if (mouse.y > (TOP_OFFSET + GAP + BUTTON_HEIGHT) &&
				mouse.y < TOP_OFFSET + GAP + BUTTON_HEIGHT * 2)
			{
				Game::s_currentMode = GameMode::Help;
			}
			if (mouse.y > TOP_OFFSET + GAP * 2 + BUTTON_HEIGHT * 2 &&
				mouse.y < TOP_OFFSET + GAP * 2 + BUTTON_HEIGHT * 3)
			{
				Game::m_exitGame = true;
			}
		}


	}
}

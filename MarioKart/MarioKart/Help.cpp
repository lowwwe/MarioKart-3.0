#include "Help.h"
#include "Game.h"

void Help::initalise(sf::Font& t_font)
{
	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setFillColor(sf::Color::White);
	m_message.setCharacterSize(24U);
	m_message.setString("Use arrow keys to move\nMario Left or right\n<UpArrow> to jump\nMove off stage to finish.\n Escape to pause.\n\n<esc> to return.");

	sf::FloatRect box = m_message.getLocalBounds();
	float posX = (WIDTH - box.size.x) / 2.0f;
	m_message.setPosition(sf::Vector2f{ posX, 150.0f });

}

void Help::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_message);
}

void Help::update(sf::Time t_deltaTime)
{
	if (m_exit)
	{
		Game::s_currentMode = GameMode::Menu;
		m_exit = false;
	}
}

void Help::processEvents(const std::optional<sf::Event> t_event)
{
	if (t_event->is<sf::Event::KeyPressed>()) //user pressed a key
	{
		const sf::Event::KeyPressed* newKeypress = t_event->getIf<sf::Event::KeyPressed>();
		if (sf::Keyboard::Key::Escape == newKeypress->code)
		{
			m_exit = true;
		}
	}
}

#pragma once

#include <SFML/Graphics.hpp>

class Help
{
public:
	void initalise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void processEvents(const std::optional<sf::Event> t_event);

private:
	sf::Font m_font; // game font
	sf::Text m_message{ m_font }; // help text
	bool m_exit{ false };
};


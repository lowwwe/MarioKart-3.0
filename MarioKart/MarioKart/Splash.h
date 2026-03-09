#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>

class Splash
{
	public:
		void initialise(sf::Font& t_font);
		void render(sf::RenderWindow& t_window);
		
		void processEvents(const std::optional<sf::Event> t_event);

private:
	sf::Font m_font; // local refrence to game font
	sf::Text m_message{ m_font }; // user prompt
	sf::Texture m_wallPaperTexture; // wallpaper image
	sf::Sprite m_wallPaperSprite{ m_wallPaperTexture }; // wallpaperSprite


};

#endif // !SPLASHSCREEN_H
#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class GamePlay
{
public:
	void initialise();
	void render(sf::RenderWindow& t_window);
	void processEvents(const std::optional<sf::Event> t_event);
	void update(sf::Time t_deltaTime);

private:
	sf::Texture m_backbroundTexture;// background texture
	sf::Sprite m_backgroundSprite{ m_backbroundTexture }; // background sprite
	Player m_player;// player
	bool m_jumpKeyPressed{ false }; // has the player decided to jump
	int m_jumpWait{ 0 };// wait for next jump
};


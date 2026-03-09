#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	void initialise();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void jump();
	void fall();
	void left();
	void right();
	bool departed();
	void resetPosition();

private:
	sf::Texture m_playerTexture; // texture for player
	sf::Sprite m_playerSprite{ m_playerTexture };// sprite for player
	sf::Vector2f m_playerLocation;// location of p[layer
	float m_roadLevel{ 420.0f };// road height
	float m_speed{1.0f}; // speed of movement
};


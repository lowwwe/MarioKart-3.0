/// <summary>
/// @author Peter Lowe
/// @date Feb 2023
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>


GameMode Game::s_currentMode = GameMode::Licence;
bool Game::m_exitGame{ false }; //when true game will exit
/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup the image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ sf::Vector2u{800U, 600U},32U }, "Mario Kart Game" }
	
{
	setupFontAndText(); // load font 
	m_licence.intialise(m_gameFont);
	m_splash.initialise(m_gameFont);
	m_menu.initialise(m_gameFont);
	m_help.initalise(m_gameFont);
	m_gamePlay.initialise();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but method needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	while (const std::optional newEvent = m_window.pollEvent())
	{
		if (newEvent->is<sf::Event::Closed>()) // close window message 
		{
			m_exitGame = true;
		}
		switch (s_currentMode)
		{
		case GameMode::None:
			break;
		case GameMode::Licence:
			break;
		case GameMode::Splash:
			m_splash.processEvents(newEvent);
			break;
		case GameMode::Menu:
			m_menu.processEvents(newEvent);
			break;
		case GameMode::Help:
			m_help.processEvents(newEvent);
			break;
		case GameMode::GamePlay:
			m_gamePlay.processEvents(newEvent);
			break;
		case GameMode::Pause:
			pauseProcessEvents(newEvent);
			break;
		default:
			break;
		}
		
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(const std::optional<sf::Event> t_event)
{
	if (t_event->is<sf::Event::KeyPressed>()) //user pressed a key
	{
		const sf::Event::KeyPressed* newKeypress = t_event->getIf<sf::Event::KeyPressed>();
		if (sf::Keyboard::Key::Escape == newKeypress->code)
		{
			m_exitGame = true;
		}
	}
}

/// <summary>
/// deal with key press when game is paused
/// enter to return to game
/// </summary>
/// <param name="t_event">input event</param>
void Game::pauseProcessEvents(const std::optional<sf::Event> t_event)
{
	if (t_event->is<sf::Event::KeyPressed>()) //user pressed a key
	{
		const sf::Event::KeyPressed* newKeypress = t_event->getIf<sf::Event::KeyPressed>();
		if (sf::Keyboard::Key::Enter == newKeypress->code)
		{
			Game::s_currentMode = GameMode::GamePlay;
		}

	}
	
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	switch (s_currentMode)
	{
	case GameMode::None:
		break;
	case GameMode::Licence:
		m_licence.update(t_deltaTime);
		break;
	case GameMode::Splash:
		break;
	case GameMode::Menu:
		break;
	case GameMode::Help:
		m_help.update(t_deltaTime);
		break;
	case GameMode::GamePlay:
		m_gamePlay.update(t_deltaTime);
		break;
	case GameMode::Pause:
		break;
	default:
		break;
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	switch (s_currentMode)
	{
	case GameMode::None:
		break;
	case GameMode::Licence:
		m_licence.render(m_window);
		break;
	case GameMode::Splash:
		m_splash.render(m_window);
		break;
	case GameMode::Menu:
		m_menu.render(m_window);
		break;
	case GameMode::Help:
		m_help.render(m_window);
		break;
	case GameMode::GamePlay:
		m_gamePlay.render(m_window);
		break;
	case GameMode::Pause:
		m_gamePlay.render(m_window);
		break;
	default:
		break;
	}


	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_gameFont.openFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
}



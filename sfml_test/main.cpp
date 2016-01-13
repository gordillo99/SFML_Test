#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	enum SpriteName {Stand, Walk, Fire};

	int const CHARACTER_SPRITE_WIDTH = 32 * 5;

	sf::Vector2i playersSpriteSource(0, 1);
	sf::Vector2i playersPositionSource(0, 0);

	float frameCounter = 0, switchFrame = 100, frameSpeed = 900;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Close);

	// Load a sprite to display
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("Sprites/dinoPlayer.png"))
	{
		return EXIT_FAILURE;
	}

	sf::Sprite dinoPlayer(playerTexture);

	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("Music/kraid_theme.mp3"))
	{
		//return EXIT_FAILURE;
	}

	// Play the music
	music.play();

	// Limit the framerate to 30 frames per second 
	window.setFramerateLimit(30);

	sf::Clock clock;

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{		
			switch (event.type)
			{
				case sf::Event::Closed:
					// Close window: exit
					window.close();
					break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (playersSpriteSource.x == 0)
			{
				playersSpriteSource.x = 2;
			}
			else
			{
				playersSpriteSource.x = 0;
			}
			dinoPlayer.move(10, 0);
			/*if ((dinoPlayer.getPosition().x + 10) < 600)
			{
				playersPositionSource.x += 10;
			}*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (playersSpriteSource.x == 1)
			{
				playersSpriteSource.x = 3;
			}
			else
			{
				playersSpriteSource.x = 1;
			}
			/*if ((dinoPlayer.getPosition().x - 10) > 0)
			{
				playersPositionSource.x -= 10;
			}*/
			dinoPlayer.move(-10, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (playersSpriteSource.x == 0 || playersSpriteSource.x == 4)
			{
				playersSpriteSource.x = 2;
			}
			else if (playersSpriteSource.x == 2 || playersSpriteSource.x == 4)
			{
				playersSpriteSource.x = 0;
			}
			if (playersSpriteSource.x == 1 || playersSpriteSource.x == 5)
			{
				playersSpriteSource.x = 3;
			}
			else if (playersSpriteSource.x == 3 || playersSpriteSource.x == 5)
			{
				playersSpriteSource.x = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				/*if ((dinoPlayer.getPosition().y - 10) > 0)
				{
					playersPositionSource.y -= 10;
				}*/
				dinoPlayer.move(0, -10);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				/*if ((dinoPlayer.getPosition().y + 10) < 420)
				{
					playersPositionSource.y += 10;
				}*/
				dinoPlayer.move(0, 10);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			if (playersSpriteSource.x == 3 || playersSpriteSource.x == 1)
			{
				playersSpriteSource.x = 5;
			}
			else if (playersSpriteSource.x == 0 || playersSpriteSource.x == 2)
			{
				playersSpriteSource.x = 4;
			}
			else if (playersSpriteSource.x == 5)
			{
				playersSpriteSource.x = 1;
			}
			else if (playersSpriteSource.x == 4)
			{
				playersSpriteSource.x = 0;
			}
		}

		// Clear screen
		window.clear();
		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			//updating the right texture for the sprite
			dinoPlayer.setTextureRect(sf::IntRect(playersSpriteSource.x * CHARACTER_SPRITE_WIDTH, playersSpriteSource.y, CHARACTER_SPRITE_WIDTH, CHARACTER_SPRITE_WIDTH));
		}
		//dinoPlayer.setPosition(playersPositionSource.x, playersPositionSource.y);
		// Draw the player sprite
		window.draw(dinoPlayer);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}

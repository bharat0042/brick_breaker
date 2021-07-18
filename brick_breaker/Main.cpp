#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#pragma warning( disable : 4244)

// Entry point for the application
int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	// a window that is 1024 by 768 pixels
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Brick Breaker");

	int score = 0;
	int lives = 3;

	// create a bat
	Bat bat(windowWidth / 2, windowHeight - 20);

	// create a ball
	Ball ball(windowWidth / 2, 1);

	// text representing score and lives
	sf::Text hud;

	// font for text
	sf::Font font;
	font.loadFromFile("DS-DIGIT.ttf");

	// set the font to our text
	hud.setFont(font);

	// size set to large
	hud.setCharacterSize(75);

	// setting color to white
	hud.setFillColor(sf::Color::White);

	// while loop for gameplay
	while(window.isOpen())
	{
		// will handle the player actions here
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// move left
			bat.moveLeft();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// move right
			bat.moveRight();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// quit, someone closed the window- bye
			window.close();
		}
		
		// updating the frames
		
		// handle ball hitting the bottom
		if(ball.getPosition().top > windowHeight)
		{
			// reverse the ball direction
			ball.hitBottom();

			// reduce a life
			lives--;

			// check for zero lives
			if (lives < 1) {
				// reset the score
				score = 0;
				// reset the lives
				lives = 3;
			}
		}

		// Handle ball hitting top
		if(ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();

			// Add a point to the players score
			score++;

		}

		// handle ball hitting sides
		if(ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}

		// has the ball hit the bat?
		if(ball.getPosition().intersects(bat.getPosition()))
		{
			// hit detected so reverse the ball and score a point
			ball.reboundBatOrTop();
		}

		ball.update();
		bat.update();

		// update the text
		std::stringstream ss;
		ss << "Score:" << score << "Lives:" << lives;
		hud.setString(ss.str());

		// draw the frame

        // clear everything from the last frame
		window.clear(sf::Color(26, 128, 182, 255));

		window.draw(bat.getShape());

		window.draw(ball.getShape());

		// draw score
		window.draw(hud);

		// show everything
		window.display();
	}

	return 0;
}
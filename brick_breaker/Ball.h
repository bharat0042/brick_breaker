#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
private:
	// Position vector, a pair of floats
	sf::Vector2f mPosition;

	// A RectangleShape object representing ball
	sf::RectangleShape mBallShape;

	// Velocity of ball in x and y direction
	float xVelocity = .2f;
	float yVelocity = .2f;

public:
	Ball(float nStartX, float nStartY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();

	void hitBottom();

	void update();

};

#endif

#include "Ball.h"

// setting the initial size and postion of ball
Ball::Ball(float nStartX, float nStartY)
{
	mPosition.x = nStartX;
	mPosition.y = nStartY;

	mBallShape.setSize(sf::Vector2f(10, 10));
	mBallShape.setPosition(mPosition);
}

// returns the postion of ball 
sf::FloatRect Ball::getPosition()
{
	return mBallShape.getGlobalBounds();
}

// return the RectangleShape object representing ball
sf::RectangleShape Ball::getShape()
{
	return mBallShape;
}

// return velocity of ball in x direction
float Ball::getXVelocity()
{
	return xVelocity;
}

// this function will be called every time the ball hits the sides of the screen, 
// makes xVelocity the negative of whatever it currently is
void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

// alters the position.y value by the equivalent of 30 frames of movement
// prevents the ball from getting stuck on the bat
// second line of code reverses the direction of the ball
void Ball::reboundBatOrTop()
{
	mPosition.y -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

//sets the position.y value to 1, effectively placing the ball back at the top of the screen 
// and the position.x to 500, placing it around about the middle horizontally
void Ball::hitBottom()
{
	mPosition.y = 1;
	mPosition.x = 500;
}

// Update the ball position variables
// Move the ball and the bat
void Ball::update()
{
	mPosition.y += yVelocity;
	mPosition.x += xVelocity;

	mBallShape.setPosition(mPosition);
}
#include "Bat.h"

// constructor for initializing the postion and size of bat
Bat::Bat(float nStartX, float nStartY)
{
	mPosition.x = nStartX;
	mPosition.y = nStartY;

	// set the size of vectors and its initial position
	mBatShape.setSize(sf::Vector2f(50, 5));
	mBatShape.setPosition(mPosition);
}

// returns the coordinates to four corners of the bat shape
sf::FloatRect Bat::getPosition()
{
	return mBatShape.getGlobalBounds();
}

// set position to left by one bat speed unit
void Bat::moveLeft()
{
	mPosition.x -= batSpeed;
}

// set position to right by one bat speed unit
void Bat::moveRight()
{
	mPosition.y += batSpeed;
}

// set the updated position of bat
void Bat::update()
{
	mBatShape.setPosition(mPosition);
}
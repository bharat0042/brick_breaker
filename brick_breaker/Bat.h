#ifndef BAT_H
#define BAT_H

#include "SFML/Graphics.hpp"

class Bat
{
private:
	/* 
	 *sf::Vector2 is a simple class that defines a mathematical vector with two coordinates (x and y)
	 * syntax wise its same as pair of float
	 */
	sf::Vector2f mPosition;

	/* 
     * Specialized shape representing a rectangle
     */
	sf::RectangleShape mBatShape;

	float batSpeed = 0.3f;

public:
	Bat(float nStartX, float nStartY);
	sf::FloatRect getPosition();
	void moveLeft();
	void moveRight();
	void update();
};

#endif // BAT_H
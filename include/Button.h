#pragma once
#include "Tile.h"

// Class representing a button in the painter application
class Button : public Tile
{
public:
	Button();

	void setButton(sf::Vector2f position, float width, float height, char symbol);
    char getCharacter() const;
	void setPress(bool pressed);
	void drawButton(sf::RenderWindow& window, const sf::Texture &aTexture);

private:

	bool m_press;
};
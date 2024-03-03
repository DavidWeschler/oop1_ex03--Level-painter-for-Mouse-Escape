 #pragma once

#include <SFML/Graphics.hpp>


// Class representing a tile in the game grid
 class Tile
 {
 public:

    Tile();
 	Tile(sf::Vector2f position, float width, float hight, char character, sf::Color color);
    
	// Get functions
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::Color getColor() const;
    char getCharacter() const;
    float getWidth() const;
    float getHeight() const;

	// Set functions
    void setChar(char c);
    void setWidth(float width);
    void setHeight(float height);
    void setColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    void setToDefult();

    void drawTile(sf::RenderWindow& window, const sf::Texture& aTexture) const;
 
 protected:

    sf::Color m_color;
    sf::Vector2f m_position;

 	char m_character;
    float m_width;
    float m_height;
 };
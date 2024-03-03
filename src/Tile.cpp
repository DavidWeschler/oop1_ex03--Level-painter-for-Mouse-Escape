#pragma once

#include "Tile.h"
#include <iostream>

 Tile::Tile()
 {
	m_character = ' ';
	m_width = m_height = 80.f;
	sf::Color gridColor = sf::Color::White;
	gridColor.a = 230;
	setColor(gridColor);
	sf::Vector2f m_position = sf::Vector2f(0, 0);
 }

Tile::Tile(sf::Vector2f position, float width, float height, char character, sf::Color color)
	: m_width(width), m_height(height), m_character(character), m_color(color)
{
	m_position = position;
}

sf::Vector2f Tile::getPosition() const
{
	return m_position;
}


sf::Vector2f Tile::getSize() const
{
	return sf::Vector2f(m_width, m_height);
}

sf::Color Tile::getColor() const
{
	return m_color;
}

char Tile::getCharacter() const
{
	return m_character;
}

float Tile::getWidth() const
{
	return m_width;
}

float Tile::getHeight() const
{
	return m_height;
}

void Tile::setChar(char c)
{
	m_character = c;
}

void Tile::setWidth(float width)
{
	m_width = width;
}

void Tile::setHeight(float height)
{
	m_height = height;
}

void Tile::setColor(sf::Color color)
{
	m_color = color;
}

void Tile::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void Tile::setToDefult()
{
	m_character = ' ';	
}

void Tile::drawTile(sf::RenderWindow& window, const sf::Texture &aTexture) const
{
	 sf::RectangleShape shape; 

	 if (!(aTexture.getSize().x > 0 && aTexture.getSize().y) > 0)
	 {
		 shape.setFillColor(m_color);
	 }
	 shape.setPosition(m_position);
	 shape.setSize(sf::Vector2f(m_width, m_height));

	 shape.setTexture(&aTexture);
	 window.draw(shape);
}

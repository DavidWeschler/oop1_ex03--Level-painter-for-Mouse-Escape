#include "Button.h"
#include <iostream>

Button::Button()
{
	m_press = false;
}

void Button::setButton(sf::Vector2f position, float width, float height, char symbol)
{	
	setChar(symbol);
	setWidth(width);
	setHeight(height);
	setPosition(position);
	//settButtonTexture();
}

//void Button::setButtonTexture()	// needs to go
//{
//	switch (m_character)
//	{
//	case 'S':
//		if (!(m_texture.loadFromFile("Save.png"))) { std::cerr << "cannot load Save\n"; exit(EXIT_FAILURE); }
//		//handle save
//		break;
//	case ' ':
//		if (!(m_texture.loadFromFile("Eraser.png"))) { std::cerr << "cannot load Eraser\n"; exit(EXIT_FAILURE); }
//		break;
//	case 'N':
//		if (!(m_texture.loadFromFile("NewPage.png"))) { std::cerr << "cannot load NewPage\n"; exit(EXIT_FAILURE); }
//		//handle new page
//		break;
//	default:
//		setTexture();
//		break;
//	}
//}

void Button::setPress(bool pressed)
{
	m_press = pressed;
}

void Button::drawButton(sf::RenderWindow& window, const sf::Texture &aTexture)
{
	sf::Sprite sprite;
	sprite.setPosition(m_position);
	sprite.setScale(sf::Vector2f(m_width / aTexture.getSize().x, m_height / aTexture.getSize().y));
	sprite.setTexture((aTexture));

	if (!m_press)
	{
		sprite.setColor(sf::Color(205,205,205, 100));	//can change here to any color
	}
	window.draw(sprite);
}

char Button::getCharacter() const
{
	return m_character;
} 
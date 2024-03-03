#include "Board.h"
#include <iostream>

Board::Board(){}

Board::Board(const std::vector<Row>* a_mat, Button* tools)
{
	m_mat = a_mat;
	m_tools = tools;
	m_pressed = -1;
}

void Board::setMat(const std::vector<Row>* a_mat)
{
	m_mat = a_mat;
}

void Board::setTools(/*const*/ Button tools[])
{
	m_tools = tools;
}

void Board::setPressed(int buttonNum)
{
	m_pressed = buttonNum;
}

void Board::draw(sf::RenderWindow& window, const std::vector<sf::Texture> &textures)
{

	//draw the tools menu
	for (int i = 0; i < 10; i++)
	{
		if (m_pressed == i)
		{
			m_tools[i].setPress(true);
		}
		else
		{
			m_tools[i].setPress(false);
		}
		m_tools[i].drawButton(window, textures[i]);
	}

	//draw the tiles
	for(int i=0; i< (*m_mat).size(); i++)
	{
		for(int j=0; j<(*m_mat)[i].size(); j++)
		{
			char c = (*m_mat)[i].at(j).getCharacter();
			drawTheTile(window, c, textures, i, j);
		}	
	}

	drawBar(window);
	
}

void Board::drawTheTile(sf::RenderWindow& window, char c, const std::vector<sf::Texture>& textures, int i, int j) const
{
	int num;

	switch (c)
	{
		case 'S': num = 0; break;
		case ' ': num = 1; break;
		case '#': num = 2; break;
		case '*': num = 3; break;
		case '%': num = 4; break;
		case '^': num = 5; break;
		case 'D': num = 6; break;
		case 'F': num = 7; break;
		case '$': num = 8; break;
		case 'N': num = 9; break;
	}

	if(c == ' ')
	{
		(*m_mat)[i].at(j).drawTile(window, sf::Texture());
	}
	else
	{
		(*m_mat)[i].at(j).drawTile(window, textures[num]);
	}
}

void Board::drawBar(sf::RenderWindow& window)
{
	//draw bar
	sf::RectangleShape m_bar;
	m_bar.setSize(sf::Vector2f(2, 880));
	m_bar.setPosition(100, 10);
	sf::Color gridColor = sf::Color::White;
	gridColor.a = 100;
	m_bar.setFillColor(gridColor);
	window.draw(m_bar);
}

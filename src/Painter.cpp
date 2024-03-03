#include "Painter.h"
#include "Tile.h"
#include <iostream>
#include <fstream>

Painter::Painter()
{
	m_file.open("Board.txt", std::ios_base::out | std::ios_base::in);
	m_exists = m_file.is_open();

	m_height = m_width = 10;

	if (!m_exists)
	{
		readSizes();
		allocRows();
	}
	else
	{
		findSizes();
		allocRows();
		loadBoard();
	}
}

void Painter::Run()
{
	auto isNewPage = true;
	auto isSave = false;

	while (isNewPage)
	{
		isNewPage = isSave= false;
		Window m_window(m_board, m_width, m_height, m_exists, isNewPage, isSave);
		m_window.handleInput();

		if (isSave)
		{
			std::cout << "Saving...\n";
			saveToFile();	
		}

		if (isNewPage)
		{
			isSave = false;
			m_exists = false;
			m_board.clear();
			readSizes();
			allocRows();
		}
	}	
}

void Painter::saveToFile()
{
	if (m_file.is_open())
	{
		m_file.clear();
		m_file.close();
	}
	
	m_file.open("Board.txt", std::ios_base::out | std::ios_base::in | std::ios::trunc);

	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			m_file << m_board[row].at(col).getCharacter();
		}
		if (row != m_height - 1)
		{
			m_file << "\n";
		}
	}

	std::cout << "Saved!!\n";
	m_file.close();
	m_file.open("Board.txt", std::ios_base::out | std::ios_base::in);
}

void Painter::loadBoard()
{
	int row, col;
	for (row = 0; row < m_height; row++)
	{
		for (col = 0; col < m_width; col++)
		{
			char c;
			m_file.get(c);
			m_board[row].at(col).setChar(c);
		}

		if (row != m_height - 1)
		{
			m_file << "\n";
		}
	}
}

void Painter::findSizes()
{
	int row, col;
	char c;
	for (row = 0; m_file.get(c); row++)
	{
		for (col = 0; m_file.get(c) && c != '\n'; col++)
		{
			m_width = col+2;
		}

		m_height = row+1;
	}

	m_file.clear();
	m_file.seekg(0, std::ios::beg);
}

void Painter::readSizes()
{
	bool keepGoing = true;
	int width, height;

	while (keepGoing)
	{
		std::cout << "Enter height: \n";
		std::cin >> height;
		std::cout << "Enter width: \n";
		std::cin >> width;

		if (height <=0 || width <=0)
		{
			std::cout << "Invalid size. Please try again:\n";
			keepGoing = true;
		}
		else
		{
			m_width = width;
			m_height = height;
			keepGoing = false;
		}
	}	
}


void Painter::allocRows()
{
	for (int row = 0; row < m_height; row++)
	{
		Tile a_tile;
		Row a_row(m_width, a_tile);
		m_board.push_back(a_row);
	}
}
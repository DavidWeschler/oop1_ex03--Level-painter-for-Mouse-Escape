#pragma once

#include <SFML/Graphics.hpp>
#include "Row.h"
#include <vector>
#include "Tile.h"
#include "Board.h"
#include "Button.h"

// Enum representing symbols used in the game grid
enum Symbol {
	Save = 'S',
	Eraser = ' ',
	Wall = '#',
	Cheese = '*',
	Mouse = '%',
	Cat = '^',
	Door = 'D',
	Key = 'F',
	Present = '$',
	NewPage = 'N'
};


// Class representing the game window
class Window
{
public:
	Window(std::vector<Row>& m_board, int width, int height, bool exists, bool &isNewPage, bool &isSave);
	void handleInput();


private:
	void handleClickPress(const sf::Event::MouseButtonEvent& event);
	void allocGridMat();
	void setSymbolArr();	
	void copyToMat();
	void findMouse();

	// Function to set textures for game elements once
	void setTextures();

	sf::RenderWindow m_window;

	int m_rows;
	int m_cols;

	char m_currInput;
	char m_symbols[10];

	bool m_exists;
	bool *m_p2NewPage;
	bool *m_p2isSave;

	Tile* m_theMouse;

	std::vector<Row> m_tiles;
	std::vector<Row> *m_pToMat;

	Button m_tools[10];
	Board m_board;

	std::vector<sf::Texture> m_textures;
};
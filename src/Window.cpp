#include "Window.h"
#include <iostream>

Window::Window(std::vector<Row>& m_board, int width, int height, bool exists, bool &isNewPage, bool &isSave)
	: m_exists(exists), m_cols(width), m_rows(height), m_window(sf::VideoMode(1200, 900), 
		"Ron's and David's Painter program- the most wonderful tool in the world")
{
	setTextures();
	m_p2isSave = &isSave;
	m_p2NewPage = &isNewPage;
	m_pToMat = &m_board;		
	setSymbolArr();
	m_currInput = Cat;
	allocGridMat();
	findMouse();
}

void Window::setTextures()
{
	char pics[10][25] = {"Save.png", 
						 "Eraser.png", 
						 "Wall.png", 
						 "Cheese.jpg", 
						 "Mouse.jpg", 
						 "Cat.jpg", 
						 "Door.png", 
						 "Key.png", 
						 "Present.png", 
						 "NewPage.png"};

	for (int i = 0; i < 10; i++)
	{
		m_textures.push_back(sf::Texture());
		if (!(m_textures[i].loadFromFile(pics[i]))) 
		{ 
			std::cerr << "cannot load graphic\n"; 
			exit(EXIT_FAILURE); 
		}
	}
}

void Window::findMouse()
{
	m_theMouse = NULL;
	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			if (m_tiles[row].at(col).getCharacter() == '%')
			{
				m_theMouse = &((m_tiles[row].at(col)));
				return;
			}
		}
	}
}

void Window::allocGridMat()
{
	for (int row = 0; row < m_rows; row++)
	{
		m_tiles.push_back(Row(m_cols));

		for (int col = 0; col < m_cols; col++)
		{
			sf::Color gridColor = sf::Color::White;
			gridColor.a = 20;

			m_tiles[row].at(col).setColor(gridColor);
			m_tiles[row].at(col).setWidth(1020/m_cols);
			m_tiles[row].at(col).setHeight(765/m_rows);
			m_tiles[row].at(col).setPosition(sf::Vector2f(110 + ((1090*col)/m_cols), 10 + ((890*row)/m_rows)));

			if (m_exists)
			{					
				m_tiles[row].at(col).setChar((*m_pToMat)[row].at(col).getCharacter());
			}
		}
	}

	//for the menu bar
	for (int i = 0; i < 10; i++)
	{
		m_tools[i].setButton(sf::Vector2f(10.5, 10 * (i + 1) + (79 * i)), 79, 79, m_symbols[i]);
	}

	m_board.setMat(&m_tiles);
	m_board.setTools(m_tools);
}

void Window::setSymbolArr()
{
	m_symbols[0] = Save; m_symbols[1] = Eraser; m_symbols[2] = Wall; m_symbols[3] = Cheese; m_symbols[4] = Mouse;
	m_symbols[5] = Cat; m_symbols[6] = Door; m_symbols[7] = Key; m_symbols[8] = Present; m_symbols[9] = NewPage;
}

void Window::copyToMat()
{
	for (int row = 0; row < m_rows; row++)
	{
		(*m_pToMat)[row] = m_tiles[row];
	}
}

void Window::handleInput()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_board.draw(m_window, m_textures);
		m_window.display();

		sf::Event event;

		//handle input
		if (m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					handleClickPress(event.mouseButton);
				}
				break;
			}
		}
	}
}

//Left mouse was Pressed
void Window::handleClickPress(const sf::Event::MouseButtonEvent& event)
{	
	auto mouseX = event.x;
	auto mouseY = event.y;
	int numOfButton;

	//tool buttons
	if (mouseX > 10.5 && mouseX < 89.5)
	{
		numOfButton = mouseY / 89;
		
		if (m_tools[numOfButton].getCharacter() == Save)
		{
			std::cout << "copying to mat..\n";
			(*m_p2isSave) = true;
			copyToMat();
		}
		else if (m_tools[numOfButton].getCharacter() == NewPage)
		{
			(*m_p2NewPage) = true;
			m_window.close();
		}
		else
		{
			m_board.setPressed(numOfButton);
			m_currInput = m_tools[numOfButton].getCharacter();
		}
	}
	//insert to mat tiles
	else                           
	{
		int numOfCol = (((mouseX - 110) * m_cols) / 1090);
		int numOfRow = (mouseY* m_rows) / 890;

		if(m_currInput== Mouse)
		{
			if (m_theMouse != NULL)
			{
				(*m_theMouse).setToDefult();
			}
			
			m_theMouse = &(m_tiles[numOfRow].at(numOfCol));
		}
		
		else if (m_tiles[numOfRow].at(numOfCol).getCharacter() == Mouse)
		{
			m_theMouse = NULL;
		}

		m_tiles[numOfRow].at(numOfCol).setChar(m_currInput);
	}
}

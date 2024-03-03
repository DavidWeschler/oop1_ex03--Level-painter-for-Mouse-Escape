#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Row.h"
#include "Button.h"

// Class representing a button in the painter application
class Board
{
public:
    Board();
    Board(const std::vector<Row>* a_mat,  Button* tools);

    void setMat(const std::vector<Row>* a_mat);
    void setTools(Button tools[]);
    void setPressed(int buttonNum);
    void draw(sf::RenderWindow& window, const std::vector<sf::Texture> &textures);

private:
    void drawTheTile(sf::RenderWindow& window, char c, const std::vector<sf::Texture>& textures, int i, int j) const;
    void drawBar(sf::RenderWindow& window);

    const std::vector<Row> *m_mat;
    Button* m_tools;
    int m_pressed;
};
#pragma once

#include <vector>
#include "Row.h"
#include <Window.h>
#include <fstream>

// Class responsible for managing the painting application
class Painter
{
public:
	Painter();
	void Run();

private:
	void allocRows();
	std::vector<Row> m_board;
	void saveToFile();
	void loadBoard();
	void findSizes();
	void readSizes();

	bool m_exists;
	int m_height;
	int m_width;
	std::fstream m_file;
};
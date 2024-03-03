#pragma once

#include "Tile.h"

// Class representing a row in the game grid (dynameclly)
class Row
{
public:
	explicit Row(int size = 0, const Tile& value = Tile());
	Row(const Row& other);
	Row& operator=(const Row& other);
	void pushBack(const Tile& vall);
	int size() const;	
	bool empty() const;
	Tile& at(int index) const;

	~Row();

private:
	void allocRow(int size);
	Tile* m_row;

	int m_size;
};
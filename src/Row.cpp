#include "Row.h"
#include <iostream>

Row::Row(int size, const Tile& value)
	: m_size(size)
{
	allocRow(size);

	for(int place=0; place < size; place++)
	{
		m_row[place] = value;
	}
}

Row::Row(const Row& other)
	: m_size(other.m_size)
{
	allocRow(m_size);

	for (int place = 0; place < m_size; place++)
	{
		m_row[place] = other.m_row[place];
	}
}

Row& Row::operator=(const Row& other)
{
	if (this != &other) 
	{
		delete[] m_row;

		m_size = other.m_size;

		allocRow(m_size);

		for (int place = 0; place < m_size; place++)
		{
			m_row[place] = other.m_row[place];
		}
	}
	return *this;
}

void Row::pushBack(const Tile& val)
{
	if (m_size == 0)
	{
		allocRow(1);
		m_row[0] = val;
		return;
	}

	Tile *newRow = new Tile[m_size + 1];
	
	for (int index= 0; index < m_size; index++)
	{
		newRow[index] = (*this).at(index);
	}	
	(*this).at(m_size) = val;
	m_size++;
	delete[] m_row;	
	m_row = newRow;
}

int Row::size() const
{
	return m_size;
}

bool Row::empty() const
{
	return (m_size == 0);
}


Tile& Row::at(int index) const
{
	return m_row[index];
}

Row::~Row()
{
	delete[] m_row;
}

void Row::allocRow(int size)
{
	if (size > 0)
	{
		m_row = new Tile[size];
	}
}

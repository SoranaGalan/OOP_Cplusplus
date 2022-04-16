#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(int id)
{
	m_id = id;
	m_position = Point{};
	// allocate the bag 
	m_bag = new int[m_bagCapacity](); 
}

Character::~Character()
{
	// release the memory only for the variables allcated on the heap (with new)
	delete[] m_bag;
	// good practice after free set the variable to nullptr
	m_bag = nullptr;
}

Character::Character(const Character & other)
{
	m_bag = new int[m_bagCapacity](); // use () to initialize the memory with 0
	m_id = other.m_id;
	m_bagSize = other.m_bagSize;
	m_position = other.m_position;
	
	// deep copy of the chocholate bag
	for (int i = 0; i < m_bagSize; i++)
		m_bag[i] = other.m_bag[i];
}

Character & Character::operator=(const Character & other)
{
	if (&other != this) { // self assignment check

		// free the previous data
		delete[] m_bag;
		m_bag = nullptr;

		m_bag = new int[m_bagCapacity](); // use () to initialize the memory with 0
		m_id = other.m_id;
		m_bagSize = other.m_bagSize;
		m_position = other.m_position;
		
		// deep copy of the chocholate bag
		for (int i = 0; i < m_bagSize; i++)
			m_bag[i] = other.m_bag[i];
	}
	return *this;
}

void Character::setPosition(Point pos)
{
	m_position = pos;
}

int Character::getChocolateAmount()
{
	int amount{ 0 };
	for (int i = 0; i < m_bagSize; i++)
		amount += m_bag[i];
	return amount;
}

void Character::display()
{
	std::cout << ": id: " << m_id <<"; position: "<< m_position<< "; chocolate gathered: " << getChocolateAmount() << endl;
}

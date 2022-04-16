#include "Tortoise.h"
#include <iostream>
using namespace std;

Tortoise::Tortoise(int id) : Character{ id } // call parent constructor!!
{}

void Tortoise::move(int direction)
{
	Point newPosition = m_position;

	// conditions implemented with if
	 // left
	if(direction == 0)
		newPosition.setX(m_position.x() - 3);
	if(direction == 1)
		newPosition.setX(m_position.x() + 3);
	if(direction == 2)
		newPosition.setY(m_position.y() + 3);
	if(direction == 3)
		newPosition.setY(m_position.y() - 3);
	
	
	cout << "\tTortoise " << getId() << " moves from "<<m_position << " to " << newPosition <<endl;
	m_position = newPosition;
}

bool Tortoise::pickChocolate()
{
	if ((m_position.x() + m_position.y()) % 2 == 1) { // if one of its coordinates is even and the other one is odd
		// pick up a chocholate bar of weight equal to |m_position.x()| + |m_position.y()|
		if (m_bagSize < m_bagCapacity) {// if we still have space in the bag
			m_bag[m_bagSize++] = abs(m_position.x()) + abs(m_position.y());
			cout << "\tTortoise " << getId() << " picks choco of size " << abs(m_position.x()) + abs(m_position.y()) << endl;
			return true;
		}
	}

	return false;
}

inline void Tortoise::display() 
{
	cout << "Tortoise";
	Character::display(); // call methods from parent class; delegation

}


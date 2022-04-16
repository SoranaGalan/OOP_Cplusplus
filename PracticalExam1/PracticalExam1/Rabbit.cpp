#include "Rabbit.h"
#include <iostream>
using namespace std;

Rabbit::Rabbit(int id): Character{id} // call parent constructor!!
{}

void Rabbit::move(int direction)
{
	// conditions implemented with switch
	Point newPosition = m_position;
	switch (direction)
	{
	case 0: // left
		newPosition.setX(m_position.x() - 4);
		break;
	case 1: // right
		newPosition.setX(m_position.x() + 4);
		break;
	case 2: // up
		newPosition.setY(m_position.y() + 4);
		break;
	case 3: // down
		newPosition.setY(m_position.y() - 4);
		break;
	default:
		break;
	}
	
	cout << "\tRabbit " << getId() << " moves from " << m_position << " to " << newPosition << endl;
	m_position = newPosition;
}

bool Rabbit::pickChocolate()
{
	if (m_position.x() % 3 == 0 || m_position.y() % 3 == 0) { // if one of the coords are divisible by 3
		// pick up a chocholate bar of weight equal to |position.x()|
		if (m_bagSize < m_bagCapacity) { // if we still have space in the bag
			m_bag[m_bagSize++] = abs(m_position.x());
			cout << "\tRabbit " << getId() << " picks choco of weight " << abs(m_position.x()) << endl;
			return true;
		}
	}
		
	return false;
}

void Rabbit::display()
{
	cout << "Rabbit";
	Character::display(); // call methods from parent class; delegation

}

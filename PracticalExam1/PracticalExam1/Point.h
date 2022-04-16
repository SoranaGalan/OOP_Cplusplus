#pragma once
#include <ostream>
#include <istream>
class Point
{
public:
	// default constructor
	 Point();
	// parametrized constructor
	 Point(int x, int y);
	
	
	// !! no need for rule of three (copy constructor, assignment operator and destructor; we don't have any data allocated on the heap)

	// getters! Good practice: mark the getters as const methods
	int x() const; 
	int y() const;

	// setters
	void setX(int x);
	void setY(int y);

	// stream operators
	friend std::ostream& operator<<(std::ostream& os, const Point &p);
	friend std::istream& operator>>(std::istream& is, Point &p); // for the operator>> we don't have a const reference !!! we need to change the state of the point

private:
	int m_x;
	int m_y;
};


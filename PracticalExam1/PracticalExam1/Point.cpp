#include "Point.h"

Point::Point()
{
	// set the x and y coordinates to 0
	this->m_x = 0;
	this->m_x = 0;
}

Point::Point(int x, int y) : m_x{ x }, m_y{y} // set the x and y coordinates by using initializer lists
{
}

int Point::x() const
{
	return m_x;
}

int Point::y() const
{
	return m_y;
}

void Point::setX(int x)
{
	this->m_x = x;
}

void Point::setY(int y)
{
	this->m_y = y;
}

std::ostream & operator<<(std::ostream & os, const Point & p)
{
	os << "(" << p.m_x << ", " << p.m_y << ")";
	return os;
}

std::istream & operator>>(std::istream & is, Point & p)
{
	// extract the data from teh stream into the Point's p coordinates
	is >> p.m_x >> p.m_y;
	// !!!!! NO cout<<"Please insert the x coordinate"
	return is;
}

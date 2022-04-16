#pragma once
#include <ostream>
#include <istream>
#include <iomanip>
#include <string>

class Age
{
public:
	int days, years;

	Age();
	Age(int, int);
	void addDays(int);
	friend std::ostream& operator<<(std::ostream& os, const Age);
	friend std::istream& operator>>(std::istream& is, Age& age);
};


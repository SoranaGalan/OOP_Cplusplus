#include "Age.h"

Age::Age() {
	this->days = 0;
	this->years = 0;
}

Age::Age(int years, int days) {
	if(days < 365)
		this->days = days;
	else {
		years += days / 365;
		days = days % 365;
	}
	this->years = years;
}

void Age::addDays(int n) {
	this->days+=n;
	if (this->days >= 365) {
		this->years += this->days/365;
		this->days = this->days%365;
	}
}

std::ostream& operator<<(std::ostream& os, const Age age)
{
	// TODO: insert return statement here
	//age.years;
	std::string s_years = std::to_string(age.years);
	std::string message = std::to_string(age.years) + " years and " + std::to_string(age.days) + " days";
	os << std::setw(21) << message;
	return os;
}

std::istream& operator>>(std::istream& is, Age& age)
{
	// TODO: insert return statement here
	is >> age.years >> age.days;
	return is;
}

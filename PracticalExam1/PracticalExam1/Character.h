#pragma once
#include "Point.h"
class Character
{
public:
	Character(int id);  // !!!!!!!!!! DON'T PASS THE BAG OF CHOCHOLATE AS A PARAMETER TO THE CONSTRUCTOR; all characters start with an empty bag
						// NOT ALL THE ATTRIBUTES OF A CLASS NEED TO BE PASSED AS PARAMETERS TO THE CONSTRUCTOR

	// Rule of three
	virtual ~Character(); // virtual destructor!!! always
	Character(const Character& other);
	Character& operator=(const Character &other);

	virtual void move(int direction) = 0; // make the move method as pure virtual
	virtual bool pickChocolate() = 0; // make the pickChocholate method as pure virtual

	// setter for the position of the character
	void setPosition(Point pos);

	int getChocolateAmount(); // returns how many chocholate (the weight) did the character gather

	virtual void display(); // prints all the info about this character

	int getId() const { return m_id;  }
protected:
	// make the attributes that we need to access from the subclasses as protected
	Point m_position;
	int* m_bag; // the bag of chocholate; we store the weights of the chocholate bars in it
	int m_bagSize;  // the bag size: how many chocholate bars do we have in the bag
	const int m_bagCapacity{ 100 }; // the capacity of the bag (100) ; good practice make a const variable for it

private:
	int m_id;
};


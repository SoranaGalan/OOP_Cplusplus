#pragma once
#include "Character.h"
class Rabbit : public Character // inherit publicly from Character
{
public:
	Rabbit(int id);

	void move(int direction) override; // good practice : mark the methods we override with override specifier
	bool pickChocolate() override; // good practice : mark the methods we override with override specifier

	void display() override; // good practice : mark the methods we override with override specifier
protected:
private:
};


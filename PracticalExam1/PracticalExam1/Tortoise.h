#pragma once
#include "Character.h"
class Tortoise: public Character
{
public:
	Tortoise(int id);
	void move(int direction) override; // good practice : mark the methods we override with override specifier
	bool pickChocolate() override; // good practice : mark the methods we override with override specifier

	void display() override; // good practice : mark the methods we override with override specifier
protected:
private:
};


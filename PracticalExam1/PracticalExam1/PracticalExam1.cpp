#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

// include required headers
#include "Rabbit.h"
#include "Tortoise.h"
#include "Character.h"

int main() {

	srand(time(0)); // initialize random generator
	// create a polymorphic array of characters
	Character* characters[10];  // polymorphic array (notice the type of an element is Character*) allocated on the stack [10]
	// add 3 characters in this array: one rabbit and two tortoises
	characters[0] = new Rabbit{ 1 };
	characters[1] = new Tortoise{ 2 };
	characters[2] = new Tortoise{ 3 };
	int numCharacters = 3;

	// set the initial positions of the characters
	for (int ci = 0; ci < numCharacters; ci++) {
		// generate a random position for this character in the range (0, 0) - (100, 100)
		int x = rand() % 101;
		int y = rand() % 101;

		// set (x, y) as the starting position for the ci-th character
		characters[ci]->setPosition(Point{ x, y });
	}

	// run simulation
	const int simulationSteps = 10;
	std::string directionNames[4] = {"left", "right", "up", "down"};
	for (int i = 0; i < simulationSteps; i++) {
		int dir = rand() % 4;
		cout << "-----------------------------------------------------" << endl;
		cout << "Step " << i << "/" << simulationSteps << " MOVE " << directionNames[dir]<<endl;
		cout << "-----------------------------------------------------" << endl;
		
		//  move all the characters in the direction dir and check if the characters can pick up any chocolate bars in the new position
		for (int ci = 0; ci < numCharacters; ci++) {
			characters[ci]->move(dir);
			characters[ci]->pickChocolate();
			cout << "-----------------------------------------------------" << endl;
		}
		cout << "-----------------------------------------------------" << endl;
	}

	//  for each character display its id, type, position and the total weight of chocolate bars it gathered (you can add a method in the Character class for this)
	int maxChoco = 0;
	int maxChocIdx = -1;
	for (int i = 0; i < numCharacters; i++) {
		characters[i]->display();
		int chocoGathered = characters[i]->getChocolateAmount();
		if (maxChoco < chocoGathered) {
			maxChoco = chocoGathered;
			maxChocIdx = i;
		}

	}
	cout << "AAAAND the winner is: " << endl;
	characters[maxChocIdx]->display();
	//  display the winner: the character that gathered the largest amount of chocolate

	// no mem leaks, release the dynamically allocated memory
	for (int i = 0; i < numCharacters; i++)
		delete characters[i]; // notice we use delete and not delete[]!!, delete[] is used only when you allocate with new[]
	
	return 0;
}
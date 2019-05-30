#include <iostream>	// For cout 
#include <ctime>	// For time()
#include <cstdlib>	// For srand() and rand()

// Using srand and rand with time is not ideal,
// since you have to wait a second for the number 
// to change, but for the purpose of this challenge
// it will suffice

int main() {
	// Generate a number from 0 to 1. If it's 0 say "Heads",
	// if 1 say "Tails"
	
	srand(time(0));

	int number = rand() % 2;

	if (number == 0) {
		std::cout << "Heads";
	} else {
		std::cout << "Tails";
	}
	
	return 0;
}

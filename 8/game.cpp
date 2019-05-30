#include "game.h"
#include "word_engine.h"

void clear_scree() {
	#ifdef WINDOWS
		std::system("cls");
	#else
		std::system("clear");
	#endif
}

void draw_hangman(int lives) {
	switch(lives) {
		case 5:
			std::cout << " -------  " << std::endl;
			std::cout << "  |    |  " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << " ______   " << std::endl;
			break;
		case 4:
			std::cout << " -------  " << std::endl;
			std::cout << "  |/   |  " << std::endl;
			std::cout << "  |    O  " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << " ______   " << std::endl;
			break;
		case 3: 
			std::cout << " -------  " << std::endl;
			std::cout << "  |/   |  " << std::endl;
			std::cout << "  |    O  " << std::endl;
			std::cout << "  |    |  " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << " ______   " << std::endl;
			break;
		case 2: 
			std::cout << " -------  " << std::endl;
			std::cout << "  |/   |  " << std::endl;
			std::cout << "  |    O  " << std::endl;
			std::cout << "  |   /|  " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << " ______   " << std::endl;
			break;
		case 1: 
			std::cout << " -------  " << std::endl;
			std::cout << "  |/   |  " << std::endl;
			std::cout << "  |    O  " << std::endl;
			std::cout << "  |   /|\\ " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << " ______   " << std::endl;
			break;
		case 0: 
			std::cout << " -------  " << std::endl;
			std::cout << "  |/   |  " << std::endl;
			std::cout << "  |    O  " << std::endl;
			std::cout << "  |   /|\\ " << std::endl;
			std::cout << "  |   /   " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << " ______   " << std::endl;
			break;
		case -1: 
			std::cout << " -------  " << std::endl;
			std::cout << "  |/   |  " << std::endl;
			std::cout << "  |    O  " << std::endl;
			std::cout << "  |   /|\\ " << std::endl;
			std::cout << "  |   / \\ " << std::endl;
			std::cout << "  |       " << std::endl;
			std::cout << " ______   " << std::endl;
			break;
	}
}

void game_start(std::string word) {
	std::string input;
	int lives = 5;	
	
	WordEngine we(word);
	while(lives > -1) {
		draw_hangman(lives);
		we.printWord();
		if(we.word_guessed) {
			std::cout << "Game won!" << std::endl;
			return;
		}
		std::cout << std::endl << std::endl;

		std::cout << "Please enter a letter: ";
		std::cin  >> input;
		
		if(!we.takeInput(input)) {
			lives--;
		}
		
	}
	draw_hangman(lives);
	std::cout << "You lost." << std::endl;
}

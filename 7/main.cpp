#include <iostream>
#include "randutils.h"

char num_to_char(int num) {
	switch(num) {
		case 1:
			return 'r';
			break;
		case 2:
			return 'p';
			break;
		case 3:
			return 's';
			break;
	}
}

char to_lower(char c) {
	if (c == 'R') {
		return 'r';
	}
	if (c == 'P') {
		return 'p';
	}
	if (c == 's') {
		return 's';
	}
}

void say_ai_choice(char ai_answer) {
	switch(ai_answer) {
		case 'r':
			std::cout << "AI chose ROCK" << std::endl;
			break;
		case 'p':
			std::cout << "AI chose PAPER" << std::endl;
			break;
		case 's':
			std::cout << "AI chose SCISSORS" << std::endl;
			break;
	}

	return;
}

bool findWinner(char p_answer, char ai_answer) {
	p_answer = to_lower(p_answer);
	say_ai_choice(ai_answer);

	if (p_answer == ai_answer) {
		std::cout << "It's a draw" << std::endl;
		return false;
	}

	if (p_answer == 'r') {
		switch(ai_answer) {
			case 'p':
				return 0;
				break;
			case 's':
				return 1;
				break;
		}
	}

	if (p_answer == 'p') {
		switch(ai_answer) {
			case 'r':
				return 1;
				break;
			case 's':
				return 0;
				break;
		}
	}

	if (p_answer == 's') {
	       switch(ai_answer) {
			case 'r':
				return 0;
				break;
			case 'p':
				return 1;
				break;
	       }
	}
}

bool runGame(char p_answer) {
	char ai_answer = num_to_char(g_rand_int(1, 3));

	return findWinner(p_answer, ai_answer);
}

int main() {
	char answer;

	std::cout << "[R]ock, [P]aper, [S]cissors: ";
	std::cin  >> answer;

	if(runGame(answer)) {
		std::cout << "You win!" << std::endl;
	} else {
		std::cout << "Sorry, maybe next time.." << std::endl;
	}

	return 0;
}

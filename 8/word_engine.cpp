#include "word_engine.h"

WordEngine::WordEngine(std::string word) {
	this->word 	      = word;	
	this->guessed_letters = {};
	this->word_guessed    = true;
}

bool WordEngine::takeInput(std::string input) {
	char inp_letter = input.at(0);
	inp_letter = toupper(inp_letter);

	for (int i = 0; i < this->guessed_letters.size(); i++) {
		if (this->guessed_letters.at(i) == inp_letter) {
			return false;
		}
	}

	this->guessed_letters.push_back(inp_letter);

	for (int i = 0; i < this->word.length(); i++) {
		if (inp_letter == this->word.at(i)) {
			return true;
		}
	}

	return false;
}

void WordEngine::printWord() {
	bool letter_guessed;
	this->word_guessed = true;

	for (int i = 0; i < this->word.length(); i++) {
		letter_guessed = false;
		for (int j = 0; j < this->guessed_letters.size(); j++) {
			if (this->word.at(i) == this->guessed_letters[j]) {
				letter_guessed = true;
				break;
			}
		}
		if (letter_guessed) {
			std::cout << this->word.at(i) << " ";
		} else {
			std::cout << "_ ";
			this->word_guessed = false;
		}
	}
}

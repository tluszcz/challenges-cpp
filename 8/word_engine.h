#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <cctype>

class WordEngine {
	public:
		WordEngine    (std::string word );
		bool takeInput(std::string input);
		void printWord();
		bool word_guessed;
	private:
		std::string       word;
		std::vector<char> guessed_letters;
};

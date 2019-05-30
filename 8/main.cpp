/* 
 * Challenge #8 - Hangman game
 *
 * This one will be easy, but the image rendering will
 * be pain to write. The whole mechanic of the game looks 
 * like this:
 * 	1 Choose a word at random (optional: show word category)
 * 	2 Show player lives via the image 
 * 	3 Show guessed/unguessed letters
 * 	4 Ask user for next letter
 * 	5 Check if it's correct, update game status and repeat from 2.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "randutils.h"
#include "game.h"

std::string get_word() {
	std::ifstream		 dict_file;
	std::string		 line;
	std::vector<std::string> word_list;
	std::string		 chosen_word;
	int 			 dict_len;
	int 			 word_num;

	dict_file.open("words.txt");

	while (!dict_file.eof()) {
		getline(dict_file, line);
		word_list.push_back(line);
	}	

	dict_file.close();

	dict_len = word_list.size();
	word_num = g_rand_int(0, --dict_len);
	
	chosen_word = word_list.at(word_num);

	return chosen_word;
}

int main() {
	game_start(get_word());
	return 0;
}

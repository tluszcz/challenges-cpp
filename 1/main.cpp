#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

int main() {
	// We'll keep the prefixes and suffixes in a text file so
	// editing them will be simpler
	
	std::vector<std::string> prefixes;
	std::vector<std::string> suffixes;

	std::ifstream prefix_file;
	std::ifstream suffix_file;

	// Let's read the text files and append each line
	// to a new item in the vector lists

	std::string line;
	
	prefix_file.open("prefixes.txt");

	if(prefix_file.is_open()) {
		while(getline(prefix_file,line)) {
			prefixes.push_back(line);
		}
	}

	prefix_file.close();

	suffix_file.open("suffixes.txt");

	if(suffix_file.is_open()) {
		while(getline(suffix_file,line)) {
			suffixes.push_back(line);
		}
	}

	suffix_file.close();

	// Now let's pick random prefix and random suffix
	// and concatenate them to create a random name
	
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist_pre(1,prefixes.size() - 1);
	std::uniform_int_distribution<std::mt19937::result_type> dist_suf(1,suffixes.size() - 1);

	std::string pref, suf;

	pref = prefixes[dist_pre(rng)];
	suf  = suffixes[dist_suf(rng)];

	std::cout << pref << suf;

	return 0;
}

#include "lovecalc.h"

LoveCalc::LoveCalc(std::string name_a, std::string name_b) {
	this->name_a = name_a;
	this->name_b = name_b;

	this->sentence = name_a + " loves " + name_b;
}

LoveCalc::LoveCalc() {
	std::cout << "Enter name A: ";
	std::cin  >> this->name_a;

	std::cout << "Enter name B: ";
	std::cin  >> this->name_b;

	this->sentence = name_a + " loves " + name_b;
}

int LoveCalc::calculateLove() {
	std::string numstring;
	std::string numstring_new;



}

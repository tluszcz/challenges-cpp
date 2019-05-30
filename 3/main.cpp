/* 
 * For this version of the application I'll try to write the code
 * without using any modern libraries. If I'll make the first version 
 * without them, the second one will use them, mainly for the 
 * argument parsing
 */

#include <iostream>	// For user cin and cout

void convert_temp(float temp_src, char conv_from, char conv_to) {
	switch(conv_to) {
		case 'c':
			switch(conv_from) {
				case 'c':
					std::cout << "What are you doing?";
					break;
				case 'k':
					temp_src = temp_src - 273.15;
					std::cout << temp_src;
					break;
				case 'f':
					temp_src = (temp_src - 32) * 0.555;
					std::cout << temp_src;
					break;
				default:
					std::cout << "Wrong parameter given";
					return;
			}
			break;
		case 'k':
			switch(conv_from) {
				case 'c':
					temp_src = temp_src + 273.15;
					std::cout << temp_src;
					break;
				case 'k':
					std::cout << "What are you doing?";
					break;
				case 'f':
					temp_src = (temp_src + 459.67) * 0.555;
					std::cout << temp_src;
					break;
				default:
					std::cout << "Wrong parameter given";
					return;
			}
			break;
		case 'f':
			switch(conv_from) {
				case 'c':
					temp_src = (temp_src * 1.8) + 32;
					std::cout << temp_src;
					break;
				case 'k':
					temp_src = (temp_src * 1.8) - 459.67;
					std::cout << temp_src;
					break;
				case 'f':
					std::cout << "What are you doing?";
					break;
				default:
					std::cout << "Wrong parameter given";
					return;
			}
			break;
		default:
			std::cout << "Wrong parameter given";
			return;
	}
}

int main(int argc, char* argv[]) {

	/* I'll approach the challenge from two different angles
	 * First, let's check if user has given us the input 
	 * via the command line arguments. If not, then ask the user
	 * for the parameters. 
	 */	

	/* The main function will contain all the frontend part
	 * of the application, all calculations or error handling 
	 * will be in seperate functions
	 */

	float temp_src;
	char conv_from;
	char conv_to;

	if (argc == 4) {
		temp_src  = atof(argv[1]);
		conv_from = argv[2][0];
		conv_to   = argv[3][0];

		convert_temp(temp_src, conv_from, conv_to);

		return 0;
	}

	if (argc != 3) {
		std::cout << "No or not enough parameters given" << std::endl;

		std::cout << "Input the source temperature: ";
		std::cin >> temp_src;

		std::cout << "Input the source unit (c/k/f): ";
		std::cin >> conv_from;

		std::cout << "Input the unit to convert to (c/k/f): ";
		std::cin >> conv_to;

		convert_temp(temp_src, conv_from, conv_to);
	
	}

	return 0;
}

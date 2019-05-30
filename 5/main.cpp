#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

bool is_file_exist(std::string file) {
	std::ifstream infile(file);
	return infile.good();
}

bool encrypt_msg(std::string file) {
	std::string passkey;
	std::string message;

	std::cout  << "Enter passphrase: ";
	std::cin   >> passkey;

	std::cout  << "Enter your message: ";
	std::getline(std::cin >> std::ws, message);

	while (passkey.length() < message.length()) {
		passkey += passkey;
	}

	if (passkey.length() > message.length()) {
		passkey = passkey.substr(0, message.length());
	}

	std::ofstream message_file;
	message_file.open(file);

	for (int i = 0; i < message.length(); i++) {
		std::bitset<8> msg_char = std::bitset<8>(message.at(i));
		std::bitset<8> key_char = std::bitset<8>(passkey.at(i));
		std::bitset<8> crypt    = msg_char^key_char;

		message_file << (char)(crypt.to_ulong()+33);
	}

	message_file.close();

	return 0;
}

bool decrypt_msg(std::string file) {
	std::string passkey;
	std::string message;
	std::string decoded;

	std::cout  << "Enter passphrase: ";
	std::cin   >> passkey;

	std::ifstream message_file(file);
	message = std::string((std::istreambuf_iterator<char>(message_file)),
			      (std::istreambuf_iterator<char>()));

	while (passkey.length() < message.length()) {
		passkey += passkey;
	}

	if (passkey.length() > message.length()) {
		passkey = passkey.substr(0, message.length());
	}

	for (int i = 0; i < message.length(); i++) {
		std::bitset<8> msg_char = std::bitset<8>(message.at(i));
		char mc = (char)msg_char.to_ulong() - 33; 
		msg_char = std::bitset<8>(mc);
		std::bitset<8> key_char = std::bitset<8>(passkey.at(i));
		std::bitset<8> crypt    = msg_char^key_char;

		decoded += (char)(crypt.to_ulong());
	}

	std::cout << std::endl << decoded;
}

void parse_arguments(int argv, char* argc[]) {
	if (argv != 2) {
		std::cout << "Wrong parameters given" << std::endl;
		return;
	}

	// Check if file exist and depending on that,
	// encrypt or decrypt the message

	std::string filename = argc[1];

	if(is_file_exist(filename)) {
		decrypt_msg(filename);
	} else {
		encrypt_msg(filename);
	}

	return;
}

int main(int argv, char* argc[]) {
	parse_arguments(argv, argc);

	return 0;
}


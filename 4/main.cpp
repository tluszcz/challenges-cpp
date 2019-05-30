#include <iostream>	// For user interface
#include <ctime>
#include <iomanip>

/* Since date and time was always my weak spot it's time for some 
 * hard practice. I'll use the ctime library to calculate time difference
 * between the user input and current time.
 */


/*
int main() {

	tm user_bday;

	user_bday.tm_sec   = 0;
	user_bday.tm_min   = 0;
	user_bday.tm_hour  = 0;
	user_bday.tm_mday  = 10;
	user_bday.tm_mon   = 10;
	user_bday.tm_year  = 92;

	// Let's check if the funcion mktime will run correctly 
	// without those parameters
	
	//user_bday.tm_wday  = 0;
	//user_bday.tm_yday  = 0;
	//user_bday.tm_isdst = 0;

	time_t now = time(nullptr);

	//std::cout << difftime(now, mktime(&user_bday));

	long user_seconds = mktime(&user_bday);
	
	std::cout << user_seconds;
	std::cout << std::endl << now << std::endl;
	std::cout << now - user_seconds << std::endl;

	long diff = now - user_seconds;

	diff = diff / (60 * 60 * 24);

	std::cout << diff;

	return 0;
}
 
 * This is the main function I've written while learning to use date
 * and time in C++. It calculates the difference in seconds since
 * my birthday and current system time, and gives several outputs:
 * my seconds since 1.1.1900, system seconds since 1.1.1900, difference
 * between these two, and the same difference given in days. It works, so 
 * now I can use the code to write the answer for the challenge.
 */

int main() {
	
	time_t	now;
	tm 	user_bday;
	
	now = time(nullptr);

	std::cout << "Please enter the day of the month you were born: ";
	std::cin >> user_bday.tm_mday;

	std::cout << "Please enter the month of the year you were born: ";
	std::cin >> user_bday.tm_mon;
	user_bday.tm_mon--;

	std::cout << "Please enter the year you were born: ";
	std::cin >> user_bday.tm_year;
	user_bday.tm_year -= 1900;

	user_bday.tm_sec   = 0;
	user_bday.tm_min   = 0;
	user_bday.tm_hour  = 0;

	long user_seconds  = mktime(&user_bday);

	std::cout << std::endl << "You are alive for " << now - user_seconds
	          << " seconds!" << std::endl;

	return 0;
}

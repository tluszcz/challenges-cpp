#include <iostream>
#include <string>
#include "convutils.h"

class LoveCalc {
    public:
        LoveCalc(std::string, std::string);
        LoveCalc();
        int calculateLove();
    private:
        std::string name_a;
        std::string name_b;
	std::string sentence;
};

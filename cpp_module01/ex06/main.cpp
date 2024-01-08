#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "input error!" << std::endl;
		return 1;
	}

	Harl harl;
	std::string level(argv[1]);
	harl.complain(level);
	return 0;
}
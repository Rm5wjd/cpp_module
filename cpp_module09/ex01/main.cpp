#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Input Error" << std::endl;
		return 1;
	}
	
	RPN rpn;
	std::string notation(argv[1]);

	if (notation.size() == 1) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	rpn.convert(notation);

	return 0;
}
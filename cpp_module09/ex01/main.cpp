#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Input Error" << std::endl;
		return 1;
	}

	RPN rpn;
	std::string notation(argv[1]);

	rpn.convert(notation);

	return 0;
}
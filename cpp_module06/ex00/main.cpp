#include <iostream>
#include <sstream>
#include <ScalarConvertor.hpp>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	
	std::string input(argv[1]);
	ScalarConvertor::convert(input);
}
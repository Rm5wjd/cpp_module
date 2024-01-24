#include <iostream>
#include <sstream>
#include <limits>

int main()
{
	std::stringstream ss;
	
	std::string str;
	str = "42.4f";
	
	ss << str;
	float f;
	int i;
	char c;
	double b;
	ss >> f;

	if (ss.fail())
		std::cout << "fail" << std::endl;
	if (ss.good())
		std::cout << "good" << std::endl;
	if (ss.bad())
		std::cout << "bad" << std::endl;
	if (ss.eof())
		std::cout << "eof" << std::endl;

	std::cout << f << std::endl;
	std::cout << i << std::endl;
	std::cout << c << std::endl;
	std::cout << b << std::endl;
}

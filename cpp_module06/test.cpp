#include <iostream>
#include <sstream>
#include <limits>

int main()
{
	std::stringstream ss;
	
	std::string str;
	str = "25122";
	
	ss << str;
	float f;
	int i;
	char c;
	double b;
	ss >> i;

	c = static_cast<char>(i);
	if (static_cast<double>(c) > 127)
		std::cout << "ww" << std::endl;
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
	std::cout << static_cast<int>(c) << std::endl;
	std::cout << b << std::endl;
}

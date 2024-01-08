#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR;
	stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address held by PTR: " << stringPTR << std::endl;
	std::cout << "Address held by REF: " << &stringREF << std::endl;

	std::cout << "Value of the string: " << str << std::endl;
	std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by REF: " << stringREF << std::endl;
	return 0;
}
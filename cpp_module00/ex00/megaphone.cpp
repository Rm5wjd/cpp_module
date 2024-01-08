#include <iostream>

int main(int argc, char *argv[])
{
	for (int i = 1; argv[i]; ++i)
	{
		std::string str(argv[i]);
		for (size_t i = 0; i < str.length(); i++) {
			str.replace(i, 1, 1, std::toupper(str[i]));
		}
		std::cout << str;
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
}
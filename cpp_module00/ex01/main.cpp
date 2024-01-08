#include "PhoneBook.hpp"

#define ADD 1
#define SEARCH 2
#define EXIT 3

int main()
{
	PhoneBook phoneBook;
	std::string input_menu;

	while (1)
	{
		phoneBook.input_field(input_menu, "Select Command\n 1) ADD, 2) SEARCH, 3) EXIT");
		if (input_menu == "ADD") {
			phoneBook.add();
		}
		else if (input_menu == "SEARCH") {
			phoneBook.search();
		}
		else if (input_menu == "EXIT") {
			exit(0);
		}
		else {
			std::cout << "invalid command!\n";
		}
		std::cout << std::endl;
	}
}
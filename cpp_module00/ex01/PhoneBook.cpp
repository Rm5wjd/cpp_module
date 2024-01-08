#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0), isFull(false) {}

void PhoneBook::input_field(std::string &field, const std::string &prompt)
{
	
	std::cout << prompt << " : ";
	std::getline(std::cin, field);
	while (std::cin.fail()) {
		if (std::cin.eof())
			std::exit(1);
		std::cin.clear();
		std::cout << prompt << " : ";
		std::getline(std::cin, field);
	}
}

int PhoneBook::input_index()
{
	int index;
	
	std::cout << "index: ";
	std::cin >> index;
	while((std::cin.fail()))
	{
		if (std::cin.eof())
			std::exit(1);
		else {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		// std::clearerr(stdin);
		std::cout << "index: ";
		std::cin >> index;
		std::cout << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	return index;
}

void PhoneBook::add()
{
	std::string fields[5];
	std::string prompt[5] = {"firstName", "lastName", "nickName", "phoneNumber", "darkestSecret"};
	
	for (int i = 0; i < 5; i++)
		input_field(fields[i], prompt[i]);
	contacts[size % 8] = Contact(fields[0], fields[1], fields[2], fields[3], fields[4]);
	++size;
	if (size == 8)
		isFull = true;
}

void PhoneBook::search()
{
	int haveSize = size;
	if (isFull)
		haveSize = 8;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	for (int i = 0; i < haveSize; i++) {
		contacts[i].shortPrint(i + 1);
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------------------------------------" << std::endl;
	int index = input_index();
	if (index >= 1 && index <= size)
		contacts[index - 1].longPrint();
	else {
		std::cout << "not exist contact" << std::endl;
	}
}
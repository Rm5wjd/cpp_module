#include "Contact.hpp"

void Contact::printAttribute(const std::string &str)
{
	if (str.length() <= 10) {
		std::cout.width(10);
		std::cout << str;
	}
	else {
		for (int i = 0; i < 9; i++) {
			std::cout << str.at(i);
		}
		std::cout << ".";
	}
}

void Contact::shortPrint(int index)
{
	std::cout << index << '|';
	printAttribute(firstName);
	std::cout << "|";
	printAttribute(lastName);
	std::cout << "|";
	printAttribute(nickName);
	std::cout << "|";
}

void Contact::longPrint(void)
{
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "| [firstName] -> " << firstName << std::endl;
	std::cout << "| [lastName] -> " << lastName << std::endl;
	std::cout << "| [nickName] -> " << nickName << std::endl;
	std::cout << "| [phoneNumber] -> " << phoneNumber << std::endl;
	std::cout << "| [darkestSecret] -> " << darkestSecret << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
}

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
	: firstName(firstName), lastName(lastName), nickName(nickName), phoneNumber(phoneNumber), darkestSecret(darkestSecret)
{

}
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		void printAttribute(const std::string &str);
	public:
		Contact();
		Contact(std::string firstName, \
		std::string lastName, \
		std::string nickName, \
		std::string phoneNumber, \
		std::string darkestSecret);
		void shortPrint(int index);
		void longPrint(void);
};

#endif
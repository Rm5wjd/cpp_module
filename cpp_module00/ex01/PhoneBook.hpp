#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int size;
		bool isFull;
		int input_index();
	public:
		PhoneBook();
		void input_field(std::string &field, const std::string &prompt);
		void add();
		void search();
};

#endif
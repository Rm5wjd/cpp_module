#include "Animal.hpp"

Animal::Animal()
	: type("")
{
	std::cout << "\033[1;31m" << "Animal Default Constructor" << "\033[0m" << std::endl;
}

Animal::Animal(const Animal& origin)
{
	std::cout << "\033[1;31m" << "Animal Copy Constructor" << "\033[0m" << std::endl;
	*this = origin;
}

Animal& Animal::operator=(const Animal& origin)
{
	std::cout << "\033[1;31m" << "Animal assignment oprator" << "\033[0m" << std::endl;
	type = origin.type;

	return *this;
}

Animal::~Animal()
{
	std::cout << "\033[1;31m" << "Animal Default Destructor" << "\033[0m" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "............................" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::setType(std::string& type)
{
	this->type = type;
}
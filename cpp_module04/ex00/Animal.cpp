#include "Animal.hpp"

Animal::Animal()
	: type("")
{
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(const Animal& origin)
{
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = origin;
}

Animal& Animal::operator=(const Animal& origin)
{
	std::cout << "Animal assignment oprator" << std::endl;
	type = origin.type;

	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Default Destructor" << std::endl;
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
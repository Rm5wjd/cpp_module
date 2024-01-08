#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("")
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& origin)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	*this = origin;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& origin)
{
	std::cout << "WrongAnimal assignment oprator" << std::endl;
	type = origin.type;

	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Default Destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong............................" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::setType(std::string& type)
{
	this->type = type;
}
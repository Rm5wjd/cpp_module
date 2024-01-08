#include "AAnimal.hpp"

AAnimal::AAnimal()
	: type("")
{
	std::cout << "\033[1;31m" << "AAnimal Default Constructor" << "\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal& origin)
{
	std::cout << "\033[1;31m" << "AAnimal Copy Constructor" << "\033[0m" << std::endl;
	*this = origin;
}

AAnimal& AAnimal::operator=(const AAnimal& origin)
{
	std::cout << "\033[1;31m" << "AAnimal assignment oprator" << "\033[0m" << std::endl;
	type = origin.type;

	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "\033[1;31m" << "AAnimal Default Destructor" << "\033[0m" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}

void AAnimal::setType(std::string& type)
{
	this->type = type;
}
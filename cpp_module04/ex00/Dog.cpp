#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	std::cout << "Dog Default Constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& origin)
{
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = origin;
}

Dog& Dog::operator=(const Dog& origin)
{
	std::cout << "Dog assignment operator" << std::endl;
	type = origin.type;

	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Default Destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "bark..........................." << std::endl;
}
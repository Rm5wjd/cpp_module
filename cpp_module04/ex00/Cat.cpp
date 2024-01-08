#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	std::cout << "Cat Default Constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& origin)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = origin;
}

Cat& Cat::operator=(const Cat& origin)
{
	std::cout << "Cat assignment operator" << std::endl;
	type = origin.type;

	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Default Destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "mia..........................." << std::endl;
}
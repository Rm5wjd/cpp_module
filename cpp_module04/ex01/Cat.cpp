#include "Cat.hpp"

Cat::Cat()
	: Animal(), brain(new Brain())
{
	std::cout << "\033[1;32m" << "Cat Default Constructor" << "\033[0m" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& origin)
{
	std::cout << "\033[1;32m" << "Cat Copy Constructor" << "\033[0m" << std::endl;
	type = origin.type;
	brain = new Brain(*(origin.brain));
}

Cat& Cat::operator=(const Cat& origin)
{
	std::cout << "\033[1;32m" << "Cat assignment operator" << "\033[0m" << std::endl;
	type = origin.type;

	delete brain;
	brain = new Brain(*(origin.brain));

	return *this;
}

Cat::~Cat()
{
	std::cout << "\033[1;32m" << "Cat Default Destructor" << "\033[0m" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "mia..........................." << std::endl;
}
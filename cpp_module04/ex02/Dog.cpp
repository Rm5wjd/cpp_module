#include "Dog.hpp"

Dog::Dog()
	: AAnimal(), brain(new Brain())
{
	std::cout << "\033[1;33m" << "Dog Default Constructor" << "\033[0m" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& origin)
{
	std::cout << "\033[1;33m" << "Dog Copy Constructor" << "\033[0m" << std::endl;
	type = origin.type;
	brain = new Brain(*(origin.brain));
}

Dog& Dog::operator=(const Dog& origin)
{
	std::cout << "\033[1;33m" << "Dog assignment operator" << "\033[0m" << std::endl;
	type = origin.type;

	delete brain;
	brain = new Brain(*(origin.brain));

	return *this;
}

Dog::~Dog()
{
	std::cout << "\033[1;33m" << "Dog Default Destructor" << "\033[0m" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "bark..........................." << std::endl;
}
#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal()
{
	std::cout << "WrongCat Default Constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& origin)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
	*this = origin;
}

WrongCat& WrongCat::operator=(const WrongCat& origin)
{
	std::cout << "WrongCat assignment operator" << std::endl;
	type = origin.type;

	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Default Destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong mia..........................." << std::endl;
}
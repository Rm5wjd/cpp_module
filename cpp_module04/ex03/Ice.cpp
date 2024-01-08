#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "\033[1;33m" << "Ice Default Constructor" << "\033[0m" << std::endl;
}

Ice::Ice(const Ice& origin)
{
	std::cout << "\033[1;33m" << "Ice Copy Constructor" << "\033[0m" << std::endl;
	*this = origin;
}

Ice& Ice::operator=(const Ice& origin)
{
	std::cout << "\033[1;33m" << "Ice Copy Assignment Operator" << "\033[0m" << std::endl;
	type = origin.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "\033[1;33m" << "Ice Default Destructor" << "\033[0m" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria* tmp = new Ice();
	return tmp;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
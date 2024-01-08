#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "\033[1;34m" << "Cure Default Constructor" << "\033[0m" << std::endl;
}

Cure::Cure(const Cure& origin)
{
	std::cout << "\033[1;34m" << "Cure Copy Constructor" << "\033[0m" << std::endl;
	*this = origin;
}

Cure& Cure::operator=(const Cure& origin)
{
	std::cout << "\033[1;34m" << "Cure Copy Assignment Operator" << "\033[0m" << std::endl;
	type = origin.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "\033[1;34m" << "Cure Default Destructor" << "\033[0m" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria* tmp = new Cure();
	return tmp;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
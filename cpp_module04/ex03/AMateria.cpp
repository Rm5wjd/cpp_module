#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
	: type("")
{
	std::cout << "\033[1;32m" << "AMateria Default Constructor" << "\033[0m" << std::endl;
}

AMateria::AMateria(std::string const& type)
	: type(type)
{
	std::cout << "\033[1;32m" << "AMateria String Constructor" << "\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria& origin)
{
	std::cout << "\033[1;32m" << "AMateria Copy Constructor" << "\033[0m" << std::endl;
	*this = origin;
}

AMateria& AMateria::operator=(const AMateria& origin)
{
	std::cout << "\033[1;32m" << "AMateria Copy Assignment Operator" << "\033[0m" << std::endl;
	type = origin.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "\033[1;32m" << "AMateria Default Destructor" << "\033[0m" << std::endl;
}

std::string const& AMateria::getType() const
{
	return type;	
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Abstract " << target.getName() << " *" << std::endl;
}

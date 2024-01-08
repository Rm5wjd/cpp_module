#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	hp = 100;
	ep = 100;
	dmg = 30;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	std::cout << "FragTrap Name Constructor called" << std::endl;
	hp = 100;
	ep = 100;
	dmg = 30;
}

FragTrap::FragTrap(const FragTrap& origin)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = origin;
}

FragTrap& FragTrap::operator=(const FragTrap& origin)
{
	std::cout << "FragTrap Default copy assignment called" << std::endl;
	if (this != &origin) {
		name = origin.name;
		hp = origin.hp;
		ep = origin.ep;
		dmg = origin.dmg;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap requests highFive" << std::endl;
}
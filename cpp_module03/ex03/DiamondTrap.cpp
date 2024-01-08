#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Name Constructor called" << std::endl;
	DiamondTrap::name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap& origin)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = origin;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origin)
{
	std::cout << "DiamondTrap Default copy assignment called" << std::endl;
	if (this != &origin) {
		name = origin.name;
		ClapTrap::name = origin.ClapTrap::name;
		hp = origin.hp;
		ep = origin.ep;
		dmg = origin.dmg;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
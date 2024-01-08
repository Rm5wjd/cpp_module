#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	hp = 100;
	ep = 50;
	dmg = 20;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap Name Constructor called" << std::endl;
	hp = 100;
	ep = 50;
	dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& origin)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = origin;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& origin)
{
	std::cout << "ScavTrap Default copy assignment called" << std::endl;
	if (this != &origin) {
		name = origin.name;
		hp = origin.hp;
		ep = origin.ep;
		dmg = origin.dmg;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (ep == 0) {
		std::cout << "energy point is not enougf!" << std::endl;
		return;
	}
	std::cout << "ScavTrap "<< name << " attacks "<< target << ", causing " << dmg << " points of damage!" << std::endl;
	ep--;
}
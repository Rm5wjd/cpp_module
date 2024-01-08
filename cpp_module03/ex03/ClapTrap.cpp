#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hp(10), ep(10), dmg(0), name("default") 
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& origin)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = origin;
}

ClapTrap::ClapTrap(const std::string& name) : hp(10), ep(10), dmg(0), name(name)
{
	std::cout << "ClapTrap Name Constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin)
{
	std::cout << "ClapTrap Default copy assignment called" << std::endl;
	if (this != &origin) {
		name = origin.name;
		hp = origin.hp;
		ep = origin.ep;
		dmg = origin.dmg;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (ep == 0) {
		std::cout << "energy point is not enough!" << std::endl;
		return;
	}
	if (hp <= 0) {
		std::cout << "hit point is not enough!" << std::endl;
		return;
	}
	std::cout << "ClapTrap "<< name << "attacks "<< target << ", causing " << dmg << "points of damage!" << std::endl;
	ep--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp <= 0) {
		std::cout << "died" << std::endl;
		return;
	}
	std::cout << "ClapTrap is attacked" << std::endl;
	hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (ep == 0) {
		std::cout << "energy point is not enougf!" << std::endl;
		return;
	}
	if (hp <= 0) {
		std::cout << "hit point is not enough!" << std::endl;
		return;
	}
	std::cout << "ClapTrap is repaired!" << std::endl;
	hp += amount;
	ep--;
}

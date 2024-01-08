#include "HumanB.hpp"

void HumanB::attack()
{
	if (!m_Weapon) {
		std::cout << m_Name << " has not a weapon" << std::endl;
		return;
	}
	std::cout << m_Name << "  attacks with their " << m_Weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& Weapon)
{
	m_Weapon = &Weapon;
}

HumanB::HumanB() : m_Weapon(0), m_Name("") {}

HumanB::HumanB(std::string name) : m_Weapon(0), m_Name(name) {}
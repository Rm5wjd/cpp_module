#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << m_Name << "  attacks with their " << m_Weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : m_Weapon(weapon), m_Name(name) {}
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon* m_Weapon;
		std::string m_Name;
	public:
		HumanB();
		HumanB(std::string name);
		void setWeapon(Weapon& Weapon);
		void attack();
};

#endif
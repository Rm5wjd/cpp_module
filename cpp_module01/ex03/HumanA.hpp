#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon& m_Weapon; // const?
		std::string m_Name;
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack();
};

#endif
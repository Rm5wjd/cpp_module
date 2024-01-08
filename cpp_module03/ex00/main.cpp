#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct1("trap");
	ClapTrap ct2 = ct1;

	ct1.attack("el");
	ct1.beRepaired(1);
}
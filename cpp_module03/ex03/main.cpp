#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d1;
	DiamondTrap d2("dia2");
	DiamondTrap d3(d2);
	DiamondTrap d4;
	d4 = d3;

	d1.whoAmI();
	d2.whoAmI();
	d3.whoAmI();
	d4.whoAmI();

	d1.ClapTrap::attack("d1");
	d1.attack("d1");
	d2.attack("d2");
	d3.attack("d3");
	d4.attack("d4");
}
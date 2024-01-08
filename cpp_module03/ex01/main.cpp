#include "ScavTrap.hpp"

int main()
{
	ScavTrap s1("s1");
	ScavTrap s2 = s1;
	ScavTrap s3;
	s3 = s2;

	s1.attack("ww");
}
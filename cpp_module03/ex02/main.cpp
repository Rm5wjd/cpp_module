#include "FragTrap.hpp"

int main()
{
	FragTrap s1("s1");
	FragTrap s2 = s1;
	FragTrap s3;
	s3 = s2;

	s1.attack("ww");
}
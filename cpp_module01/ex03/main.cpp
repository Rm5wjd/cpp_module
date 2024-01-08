#include "HumanA.hpp"
#include "HumanB.hpp"

void check()
{
	system("leaks weapon");
}

int main()
{
	atexit(check);
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		// HumanA bob("Bob", Weapon("crude spiked club"));
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		// jim.setWeapon(Weapon("ccc"));
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
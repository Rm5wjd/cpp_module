#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
	Zombie *firstZombie = newZombie("First");
	Zombie *secondZombie = newZombie("Second");
	Zombie *thirdZombie = newZombie("Third");

	randomChump("random1");
	randomChump("random2");
	randomChump("random3");
	firstZombie->announce();
	secondZombie->announce();
	thirdZombie->announce();

	delete(firstZombie);
	delete(secondZombie);
	delete(thirdZombie);

	return 0;
}
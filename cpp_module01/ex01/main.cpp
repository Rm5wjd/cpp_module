#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* zombieArr = zombieHorde(6, "foo");
	if (!zombieArr)
		return 0;
	for (int i = 0; i < 6; i++)
		zombieArr[i].announce();
	delete[] zombieArr;
	return 0;
}
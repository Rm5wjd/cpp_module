#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) :name(name) {}

Zombie::~Zombie()
{
	std::cout << "Zombie: " << name << " is destroyed" << std::endl;
}
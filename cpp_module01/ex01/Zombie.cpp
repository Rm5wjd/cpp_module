#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie() :name("") {}

Zombie::Zombie(std::string name) :name(name) {}

Zombie::~Zombie()
{
	std::cout << "Zombie: " << name << " is destroyed" << std::endl;
}
#include "Weapon.hpp"

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string typeName)
{
	type = typeName;
}

Weapon::Weapon() :type("") {}

Weapon::Weapon(std::string typeName) :type(typeName) {}
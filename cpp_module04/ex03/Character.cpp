#include "Character.hpp"

AMateria** Character::floor = new AMateria*[4];
int Character::floorCapacity = 4;
int Character::floorSize = 0;

void Character::floorAdd(AMateria* m)
{
	if (floorSize == floorCapacity) {
		AMateria** tmp = new AMateria*[floorCapacity * 2];
		for (int i = 0; i < floorSize; i++) {
			tmp[i] = floor[i];
		}
		delete[] floor;
		floor = tmp;
		floorCapacity *= 2;
	}
	floor[floorSize++] = m;
}

Character::Character()
{
	std::cout << "\033[1;35m" << "Character Default Constructor" << "\033[0m" << std::endl;
	name = "";
	for (int i = 0; i < 4; i++) {
		inven[i] = 0;
	}
	size = 0;
}

Character::Character(std::string const& name)
	: name(name), size(0)
{
	std::cout << "\033[1;35m" << "Character Name Constructor" << "\033[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		inven[i] = 0;
	}
}

Character::Character(const Character& origin)
{
	std::cout << "\033[1;35m" << "Character Copy Constructor" << "\033[0m" << std::endl;
	name = origin.name;
	for (int i = 0; i < origin.size; i++) {
		inven[i] = origin.inven[i]->clone();
	}
	size = origin.size;
}

Character& Character::operator=(const Character& origin)
{
	std::cout << "\033[1;35m" << "Character Copy Assignment Operator" << "\033[0m" << std::endl;
	// 원래 가지고 있던 것들 잘 delete
	if ((this) != &origin) {
		for (int i = 0; i < size; i++)
			delete inven[i];
		for (int i = 0; i < origin.size; i++)
			inven[i] = origin.inven[i]->clone();
		name = origin.name;
		size = origin.size;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "\033[1;35m" << "Character Default Destructor" << "\033[0m" << std::endl;
	for (int i = 0; i < size; i++) {
		delete inven[i];
	}
}

std::string const& Character::getName() const { return name; }

void Character::equip(AMateria* m)
{
	// 초과 x
	if (size >= 4) {
		std::cout << "Slot is full" << std::endl;
		delete m;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!inven[i]) {
			inven[i] = m;
			size++;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (size == 0) {
		std::cout << "Slot is empty" << std::endl;
		return;
	}
	if (idx < 0 || idx > 3) {
		std::cout << "Index is invalid" << std::endl;
		return;
	}
	if (!inven[idx]) {
		std::cout << "Unexisting Materia" << std::endl;
		return;
	}
	floorAdd(inven[idx]);
	inven[idx] = 0;
	size--;
}

void Character::use(int idx, ICharacter& target)
{
	if (size == 0) {
		std::cout << "Slot is empty" << std::endl;
		return;
	}
	if (idx < 0 || idx > 3) {
		std::cout << "Index is invalid" << std::endl;
		return;
	}
	if (!inven[idx]) {
		std::cout << "Unexisting Materia" << std::endl;
		return;
	}
	inven[idx]->use(target);
}
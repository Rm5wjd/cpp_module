#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "\033[1;31m" << "MateriaSource Default Constructor" << "\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		slot[i] = 0;
	size = 0;
}

MateriaSource::MateriaSource(const MateriaSource& origin)
{
	std::cout << "\033[1;31m" << "MateriaSource Copy Constructor" << "\033[0m" << std::endl;
	for (int i = 0; i < origin.size; i++)
		slot[i] = origin.slot[i]->clone();
	size = origin.size;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& origin)
{
	std::cout << "\033[1;31m" << "MateriaSource Copy Assignment Operator" << "\033[0m" << std::endl;
	for (int i = 0; i < origin.size; i++)
		slot[i] = origin.slot[i]->clone();
	size = origin.size;

	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "\033[1;31m" << "MateriaSource Default Destructor" << "\033[0m" << std::endl;
	for (int i = 0; i < size; i++)
		delete slot[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (size >= 4) {
		std::cout << "Not enough slot!" << std::endl;
		delete m;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!slot[i]) {
			slot[i] = m->clone();
			size++;
			delete m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	AMateria* tmp;
	for (int i = 3; i >= 0; i--) {
		if (slot[i]) {
			if (slot[i]->getType() == type) {
				tmp = slot[i]->clone();
				return tmp;
			}
		}
	}
	std::cout << "Type is unknown" << std::endl;
	return 0;
}
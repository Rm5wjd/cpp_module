#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[1;34m" << "Brain Default Constructor" << "\033[0m" << std::endl;
}

Brain::Brain(const Brain& origin)
{
	std::cout << "\033[1;34m" << "Brain Copy Constructor" << "\033[0m" << std::endl;
	*this = origin;
}

Brain& Brain::operator=(const Brain& origin)
{
	std::cout << "\033[1;34m" << "Brain assignment operator" << "\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = origin.ideas[i];
	
	return *this;
}

Brain::~Brain()
{
	std::cout << "\033[1;34m" << "Brain Default Destructor" << "\033[0m" << std::endl;
}
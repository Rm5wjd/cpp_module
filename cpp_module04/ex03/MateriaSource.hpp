# ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *slot[4];
		int size;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& origin);
		MateriaSource& operator=(const MateriaSource& origin);
		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const& type);
};

# endif
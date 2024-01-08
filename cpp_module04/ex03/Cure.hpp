# ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& origin);
		Cure& operator=(const Cure& origin);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};

# endif
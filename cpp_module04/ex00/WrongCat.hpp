# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& origin);
		WrongCat& operator=(const WrongCat& origin);
		~WrongCat();
		void makeSound() const;
};

# endif
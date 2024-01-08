# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& origin);
		Cat& operator=(const Cat& origin);
		~Cat();
		void makeSound() const;
};

# endif
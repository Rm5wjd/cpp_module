# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& origin);
		Cat& operator=(const Cat& origin);
		~Cat();
		void makeSound() const;
	private:
		Brain* brain;
};

# endif
# ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog();
		Dog(const Dog& origin);
		Dog& operator=(const Dog& origin);
		~Dog();
		void makeSound() const;
	private:
		Brain* brain;
};

# endif
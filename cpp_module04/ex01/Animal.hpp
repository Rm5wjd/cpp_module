# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(const Animal& origin);
		Animal& operator=(const Animal& origin);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string& type);

	protected:
		std::string type;
};

# endif
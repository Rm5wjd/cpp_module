# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& origin);
		WrongAnimal& operator=(const WrongAnimal& origin);
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
		void setType(std::string& type);

	protected:
		std::string type;
};

# endif
# ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>

class AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal& origin);
		AAnimal& operator=(const AAnimal& origin);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		std::string getType() const;
		void setType(std::string& type);

	protected:
		std::string type;
};

# endif
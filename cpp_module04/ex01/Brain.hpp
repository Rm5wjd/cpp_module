# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain& origin);
		Brain& operator=(const Brain& origin);
		~Brain();

	private:
		std::string ideas[100];
};

# endif
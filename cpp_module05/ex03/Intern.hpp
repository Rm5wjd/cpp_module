# ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(const Intern& origin);
		Intern& operator= (const Intern& origin);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);
	
	private:
		std::string job;

		static std::string formSet[3];

		class FormNameException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

# endif
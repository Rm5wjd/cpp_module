# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& origin);
		Bureaucrat& operator= (const Bureaucrat& origin);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;
		void increment();
		void decrement();

		bool signForm(const std::string& formName, int signGrade);
		void executeForm(AForm const& form);
	private:
		const std::string name;
		int grade;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

# endif
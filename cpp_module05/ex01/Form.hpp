# ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& origin);
		Form& operator= (const Form& origin);
		~Form();

		const std::string& getName();
		bool getSignStatus();
		int getGradeSign();
		int getGradeExec();

		void beSigned(Bureaucrat& b);

	private:
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;

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
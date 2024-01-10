#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

std::ostream& operator<< (std::ostream& os, const AForm& form)
{
	os << "form" << form.getName() << "'s sign and execute grade info: " << form.getGradeSign() << ", " << form.getGradeExec();
	form.getSignStatus() ? os << " and signed" : os << " and not signed";
	return os;
}

int main()
{
	try
	{
		Bureaucrat b1("b1", 24);
		Bureaucrat b2("b2", 1);
		Bureaucrat b3("b3", 50);

		Intern in1;
		//Bureaucrat b2("b2", 160);
		AForm* form1 = in1.makeForm("presidential pardon", "t1");
		AForm* form2 = in1.makeForm("robotomy request", "t2");
		AForm* form3 = in1.makeForm("shrubbery creation", "t3");
		
		b2.signForm(*form1);
		b2.signForm(*form2);
		b2.signForm(*form3);
		b2.executeForm(*form1);
		b2.executeForm(*form2);
		b2.executeForm(*form3);
		//for (int i = 0; i < 200; i++)
		//	b1.increment();

		std::cout << b1 << std::endl;
		std::cout << *form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
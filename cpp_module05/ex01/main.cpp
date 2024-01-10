#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

std::ostream& operator<< (std::ostream& os, const Form& form)
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
		Bureaucrat b2("b2", 2);
		//Bureaucrat b2("b2", 160);
		Form form1("f1", 15, 10);
		b1.signForm(form1);
		//for (int i = 0; i < 200; i++)
		//	b1.increment();

		std::cout << b1 << std::endl;
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
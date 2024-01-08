#include "Bureaucrat.hpp"

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

int main()
{
	try
	{
		Bureaucrat b1("b1", 24);
		//Bureaucrat b2("b2", 160);

		for (int i = 0; i < 200; i++)
			b1.increment();

		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
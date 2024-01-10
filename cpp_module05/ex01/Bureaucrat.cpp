#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("default"), grade(150)
{
	std::cout << "Using this constructor is not recommended." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name)
{
	this->grade = grade;
	checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin)
	: name(origin.name), grade(origin.grade)
{}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& origin)
{
	std::cout << "Using this copy assignment operator is not recommended." << std::endl;
	grade = origin.grade;
	
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

const std::string& Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::increment()
{
	grade--;
	checkGrade();
}

void Bureaucrat::decrement()
{
	grade++;
	checkGrade();
}

void Bureaucrat::checkGrade() const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		if (form.beSigned(*this))
			std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}

}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}
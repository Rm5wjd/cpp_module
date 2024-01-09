#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name("default form"), sign(false), signGrade(1), execGrade(1)
{
	std::cout << "Using this constructor is not recommended." << std::endl;
}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || signGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& origin)
	: name(origin.name), sign(origin.sign), signGrade(origin.signGrade), execGrade(origin.execGrade)
{}

Form& Form::operator= (const Form& origin)
{
	std::cout << "Using this copy assignment operator is not recommended." << std::endl;
	sign = origin.sign;

	return *this;
}

Form::~Form()
{}

const std::string& Form::getName() const
{
	return name;
}
bool Form::getSignStatus() const
{
	return sign;
}
int Form::getGradeSign() const
{
	return signGrade;
}
int Form::getGradeExec() const
{
	return execGrade;
}

void Form::beSigned(Bureaucrat& b) // 무슨 exeception?
{
	if (b.signForm(name, signGrade)) {
		sign = true;
	}
	else throw Form::GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form GradeTooLowException";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form GradeTooHighException";
}
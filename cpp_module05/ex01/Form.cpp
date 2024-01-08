#include "Form.hpp"

Form::Form()
	: name("default form"), sign(false), signGrade(1), execGrade(1)
{

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
{

}

Form& Form::operator= (const Form& origin)
{

}

Form::~Form()
{

}

const std::string& Form::getName()
{
	return name;
}
bool Form::getSignStatus()
{
	return sign;
}
int Form::getGradeSign()
{
	return signGrade;
}
int Form::getGradeExec()
{
	return execGrade;
}

void Form::beSigned(Bureaucrat& b) // 무슨 exeception?
{
	if (b.signForm(name, signGrade)) {
		sign = true;
	}
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form GradeTooLowException";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form GradeTooHighException";
}
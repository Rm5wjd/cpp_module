#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: name("default AForm"), sign(false), signGrade(1), execGrade(1)
{
	std::cout << "Using this constructor is not recommended." << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || signGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& origin)
	: name(origin.name), sign(origin.sign), signGrade(origin.signGrade), execGrade(origin.execGrade)
{}

AForm& AForm::operator= (const AForm& origin)
{
	std::cout << "Using this copy assignment operator is not recommended." << std::endl;
	sign = origin.sign;

	return *this;
}

AForm::~AForm()
{}

const std::string& AForm::getName() const
{
	return name;
}
bool AForm::getSignStatus() const
{
	return sign;
}
int AForm::getGradeSign() const
{
	return signGrade;
}
int AForm::getGradeExec() const
{
	return execGrade;
}

bool AForm::beSigned(Bureaucrat& b) // 무슨 exeception?
{
	if (b.getGrade() <= signGrade) {
		if (sign)
			return false;
		sign = true;
		return true;
	}
	else throw AForm::SignGradeTooLowException();
}

void AForm::checkRequirement(Bureaucrat const& executor) const
{
	if (!sign) {
		throw AForm::SignGradeTooLowException();
	}
	if (executor.getGrade() > execGrade) {
		throw AForm::ExecuteGradeTooLowException();
	}
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Exception: grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Exception: grade is too high";
}

const char* AForm::SignGradeTooLowException::what() const throw()
{
	return "Exception: sign";
}

const char* AForm::ExecuteGradeTooLowException::what() const throw()
{
	return "Exception: exec";
}


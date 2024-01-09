#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
	: AForm(origin)
{}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& origin)
{
	// ??
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getSignStatus()) { 
		std::cout << "robotomy failed" << std::endl;
		throw AForm::SignGradeTooLowException();
	}
	if (executor.getGrade() > getGradeExec()) {
		std::cout << "robotomy failed" << std::endl;
		throw AForm::ExecuteGradeTooLowException();
	}
	std::cout << getName() << " has been robotomized successfully 50% of the time" << std::endl;
}
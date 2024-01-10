#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(), target("")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
	: AForm(origin)
{
	target = origin.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& origin)
{
	// ??
	target = origin.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkRequirement(executor);
	std::cout << getName() << " has been robotomized successfully 50% of the time" << std::endl;
}
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin)
	: AForm(origin)
{}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& origin)
{
	// ??
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getSignStatus()) {
		throw AForm::SignGradeTooLowException();
	}
	if (executor.getGrade() > getGradeExec()) {
		throw AForm::ExecuteGradeTooLowException();
	}
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
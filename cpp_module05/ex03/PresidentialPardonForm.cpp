#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(), target("")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin)
	: AForm(origin)
{
	target = origin.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& origin)
{
	// ??
	target = origin.target;
	
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkRequirement(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
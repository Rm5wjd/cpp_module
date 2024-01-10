#include "Intern.hpp"

std::string Intern::formSet[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };

Intern::Intern()
	: job("makeForm")
{}

Intern::Intern(const Intern& origin)
{
	job = origin.job;
}

Intern& Intern::operator= (const Intern& origin)
{
	job = origin.job;

	return *this;
}

Intern::~Intern()
{}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	int index = -1;
	
	for (int i = 0; i < 3; i++)
	{
		if (formSet[i] == formName) {
			index = i;
			std::cout << "Intern creates " << formName << std::endl;
			break;
		}
	}

	switch (index)
	{
	case 0:
		return new PresidentialPardonForm(target);
	case 1:
		return new RobotomyRequestForm(target);
	case 2:
		return new ShrubberyCreationForm(target);
	default:
		throw FormNameException();
		break;
	}
}

const char* Intern::FormNameException::what() const throw()
{
	return "[Exception] makeForm(): Form name doesn't exist";
}
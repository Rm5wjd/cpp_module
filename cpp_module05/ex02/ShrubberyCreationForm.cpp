#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin)
	: AForm(origin)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& origin)
{
	// ??
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getSignStatus()) {
		throw AForm::SignGradeTooLowException();
	}
	if (executor.getGrade() > getGradeExec()) {
		throw AForm::ExecuteGradeTooLowException();
	}
	std::string outFile(getName());
	outFile.append("_shrubbery");
	std::ofstream out(outFile.c_str());
}
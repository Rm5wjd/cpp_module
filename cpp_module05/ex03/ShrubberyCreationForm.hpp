# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& origin);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& origin);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const& executor) const;
	private:
		std::string target;
};

# endif
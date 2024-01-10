# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& origin);
		PresidentialPardonForm& operator= (const PresidentialPardonForm& origin);
		~PresidentialPardonForm();

		void execute(Bureaucrat const& executor) const;
	private:
		std::string target;
};

# endif
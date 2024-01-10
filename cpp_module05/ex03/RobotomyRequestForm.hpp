# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& origin);
		RobotomyRequestForm& operator= (const RobotomyRequestForm& origin);
		~RobotomyRequestForm();

		void execute(Bureaucrat const& executor) const;
	private:
		std::string target;
};

# endif
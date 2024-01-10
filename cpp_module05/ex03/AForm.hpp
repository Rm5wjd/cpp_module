# ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& origin);
		AForm& operator= (const AForm& origin);
		~AForm();

		const std::string& getName() const;
		bool getSignStatus() const;
		int getGradeSign() const;
		int getGradeExec() const;

		bool beSigned(Bureaucrat& b);
		virtual void execute(Bureaucrat const& executor) const = 0;
		void checkRequirement(Bureaucrat const& executor) const;

	protected:
		class SignGradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		class ExecuteGradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

	private:
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

# endif
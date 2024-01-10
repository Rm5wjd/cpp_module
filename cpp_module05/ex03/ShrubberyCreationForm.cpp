#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(), target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin)
	: AForm(origin)
{
	target = origin.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& origin)
{
	// ??
	target = origin.target;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkRequirement(executor);
	std::string outFile(getName());
	outFile.append("_shrubbery");
	std::ofstream out(outFile.c_str());

	out << "                                                \n";
	out << "                      O                         \n";
	out << "                     ***                        \n";
	out << "                    **O**                       \n";
	out << "                   *******                      \n";
	out << "                  *********                     \n";
	out << "                 ***********                    \n";
	out << "                  ******o**                     \n";
	out << "                 ***********                    \n";
	out << "                ****o********                   \n";
	out << "               ***************                  \n";
	out << "              ****o***o********                 \n";
	out << "             *******************                \n";
	out << "           ***********************              \n";
	out << "              *****O***********                 \n";
	out << "             **********o********                \n";
	out << "            ****************o****               \n";
	out << "           **O********************              \n";
	out << "          ***********o********O****             \n";
	out << "        *****************************           \n";
	out << "            *********************               \n";
	out << "           ***o*******************              \n";
	out << "          ***********o*******o*****             \n";
	out << "         ***************************            \n";
	out << "        ***********************O*****           \n";
	out << "       ***O***************************          \n";
	out << "     ***********************************        \n";
	out << "          *************************             \n";
	out << "         *******o********o**********            \n";
	out << "        *****************************           \n";
	out << "       **************o****************          \n";
	out << "      *************************O*******         \n";
	out << "     *****O*****************************        \n";
	out << "   **************o************************      \n";
	out << "         ***************************            \n";
	out << "        *************o***************           \n";
	out << "       ***********o*******************          \n";
	out << "      **************************O******         \n";
	out << "     ***o******************O************        \n";
	out << "   ***o***********o****************o******      \n";
	out << "                     ###                        \n";
	out << "                     ###                        \n";
	out << "                     ###                        \n";
	out << "                 ###########                    \n";
	out << "                 ###########                    \n";
}
#include "RPN.hpp"

static bool isNumber(char c);
static bool isOperator(char c);

RPN::RPN()
{

}

RPN::RPN(const RPN& origin)
{
	this->stk = origin.stk;
}

RPN& RPN::operator= (const RPN& origin)
{
	this->stk = origin.stk;

	return *this;
}

RPN::~RPN()
{

}

void RPN::convert(std::string& notation)
{
	std::stringstream ss(notation);
	std::string token;

	while (!ss.eof())
	{
		std::getline(ss, token, ' ');

		if (token.length() > 1) {
			std::cout << "Error" << std::endl;
			return;
		}

		char c = token[0];
		// std::cout << c << std::endl;

		if (isNumber(c))
			this->stk.push(c - '0');
		else
		{
			if (!isOperator(c)) {
				std::cout << "Error" << std::endl;
				return;
			}
			
			if (this->stk.size() < 2) {
				std::cout << "Error" << std::endl;
				return;
			}
			
			int num1 = this->stk.top();
			this->stk.pop();

			int num2 = this->stk.top();
			this->stk.pop();

			// std::cout << num1 << ' ' << num2 << std::endl;

			switch (c)
			{
				case '+':
					this->stk.push(num2 + num1);
					break;
				case '-':
					this->stk.push(num2 - num1);
					break;
				case '*':
					this->stk.push(num2 * num1);
					break;
				case '/':
					this->stk.push(num2 / num1);
					break;
				default:
					break;
			}
		}
	}

	std::cout << this->stk.top() << std::endl;
}

static bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
};

static bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
};
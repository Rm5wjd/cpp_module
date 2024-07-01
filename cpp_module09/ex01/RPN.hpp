# ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
	private:
		std::stack<int> stk;
	public:
		RPN();
		RPN(const RPN& origin);
		RPN& operator= (const RPN& origin);
		~RPN();

		void convert(std::string& notation);

};

# endif
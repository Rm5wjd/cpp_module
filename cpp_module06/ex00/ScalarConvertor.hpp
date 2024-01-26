# ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP

#include <iostream>
#include <sstream>
#include <limits.h>
#include <cfloat>
#include "Util.hpp"

class ScalarConvertor
{
	private:
		ScalarConvertor();
		ScalarConvertor(const ScalarConvertor& origin);
		ScalarConvertor& operator= (const ScalarConvertor& origin);
		~ScalarConvertor();
	public:
		static void convert(std::string& str);
};

# endif
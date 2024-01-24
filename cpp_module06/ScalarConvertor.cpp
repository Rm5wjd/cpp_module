#include "ScalarConvertor.hpp"

#define ERROR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

static int parseType(std::string& input)
{
	if (input.length() == 1 && !isdigit(input.at(0))) return CHAR;
	
	size_t pos = input.find('.');
	if (pos != std::string::npos) // && (pos > 0 && pos < input.length() - 1)
	{
		if (input.at(input.length() - 1) == 'f')
			return FLOAT;
		else
			return DOUBLE;
	}
	else
	{
		if (input == "-inff" || input == "+inff")
			return FLOAT;
		else if (input == "-inf" || input == "+inf" || input == "nan")
			return DOUBLE;
		else
			return INT;
	}
}

static void* convertActualType(int actual_type, std::istringstream& input_ss)
{
	void* out;

	switch (actual_type)
	{
		case CHAR:
			out = new char;
			input_ss >> *(static_cast<char *>(out));
			break;
		case INT:
			out = new int;
			input_ss >> *(static_cast<int *>(out));
			break;
		case FLOAT:
			out = new float;
			input_ss >> *(static_cast<float *>(out));
			break;
		case DOUBLE:
			out = new double;
			input_ss >> *(static_cast<double *>(out));
			break;
		default:
			break;
	}
	
	return out;
}

void ScalarConvertor::convert(std::string& input)
{
	int actual_type = parseType(input);

	if (actual_type == FLOAT)
		input.pop_back();
	std::istringstream input_ss(input);
	void *out = convertActualType(actual_type, input_ss);

	// 나머지 convert
}
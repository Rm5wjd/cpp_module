#include "ScalarConvertor.hpp"

#define ERROR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

static int parseType(std::string& input);
static void* convertActualType(int actual_type, std::istringstream& input_ss);
static void convertOtherType(int actual_type, std::istringstream& input_ss, void *out);
static void printScalar(char& c, int& i, float& f, double& d, int actual_type);
static int checkCharOverFlow(double data);
static int checkIntOverFlow(double data);
static int checkFloatOverFlow(double data);

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
		if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf")
			return FLOAT;
		else if (input == "-inf" || input == "+inf" || input == "inf" || input == "nan")
			return DOUBLE;
		else
		{
			for (int i = 0; i < static_cast<int>(input.length()); i++) {
				if (!isdigit(input.at(i)))
					return ERROR;
			}
			return INT;
		}
	}
}

static void* convertActualType(int actual_type, std::istringstream& input_ss)
{
	void* out = NULL;

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

static void convertOtherType(int actual_type, std::istringstream& input_ss, void *out)
{
	char char_data;
	int int_data;
	float float_data;
	double double_data;

	if (input_ss.fail())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	switch (actual_type)
	{
		case CHAR:
			char_data = *(static_cast<char *>(out));
			break;
		case INT:
			int_data = *(static_cast<int *>(out));
			break;
		case FLOAT:
			float_data = *(static_cast<float *>(out));
			break;
		case DOUBLE:
			double_data = *(static_cast<double *>(out));
			break;
		default:
			break;
	}
	printScalar(char_data, int_data, float_data, double_data, actual_type);
}

static void printScalar(char& c, int& i, float& f, double& d, int actual_type)
{
	switch (actual_type)
	{
		case CHAR:
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			printCharData(c);
			printIntData(i);
			printFloatData(f);
			printDoubleData(d);
			break;
		case INT:
			if (!checkCharOverFlow(static_cast<double>(i))) {
				c = static_cast<char>(i);
				printCharData(c);
			}
			printIntData(i);
			if (!checkFloatOverFlow(static_cast<double>(i))) {
				f = static_cast<float>(i);
				printFloatData(f);
			}
			d = static_cast<double>(i);
			printDoubleData(d);
			break;
		case FLOAT:
			if (!checkCharOverFlow(static_cast<double>(f))) {
				c = static_cast<char>(f);
				printCharData(c);
			}
			if (!checkIntOverFlow(static_cast<double>(f))) {
				i = static_cast<int>(f);
				printIntData(i);
			}
			printFloatData(f);
			d = static_cast<double>(f);
			printDoubleData(d);
			break;
		case DOUBLE:
			if (!checkCharOverFlow(d)) {
				c = static_cast<char>(d);
				printCharData(c);
			}
			if (!checkIntOverFlow(d)) {
				i = static_cast<int>(d);
				printIntData(i);
			}
			if (!checkFloatOverFlow(d)) {
				f = static_cast<float>(d);
				printFloatData(f);
			}
			printDoubleData(d);
			break;
		default:
			break;
	}
}

static int checkCharOverFlow(double data)
{
	if (data > 255 || isnan(data) || isinf(data)) {
		std::cout << "char: impossible" << std::endl;
		return 1;
	}
	else if ((data >= 0 && data <= 31) || data > 127 || data < 0) {
		std::cout << "char: Non displayable" << std::endl;
		return 1;
	}
	else
		return 0;
}

static int checkIntOverFlow(double data)
{
	if (data > INT_MAX || data < INT_MIN || isnan(data) || isinf(data)) {
		std::cout << "int: impossible" << std::endl;
		return 1;
	}
	return 0;
}

static int checkFloatOverFlow(double data)
{
	if (data > FLT_MAX || data < -FLT_MAX) {
		std::cout << "float: impossible" << std::endl;
		return 1;
	}
	return 0;
}

void ScalarConvertor::convert(std::string& input)
{
	int actual_type = parseType(input);
	if (actual_type == ERROR)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (actual_type == FLOAT)
		input.pop_back();

	std::istringstream input_ss(input);
	void *out = convertActualType(actual_type, input_ss);

	// 나머지 convert
	convertOtherType(actual_type, input_ss, out);
}

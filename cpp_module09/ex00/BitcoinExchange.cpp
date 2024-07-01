#include "BitcoinExchange.hpp"

static bool isNumber(const std::string str);

static bool separateCsv(std::string str, std::pair<std::string, float>& btcSet)
{
	std::string token;
	std::stringstream ss(str);
	float exchangeRate;

	std::getline(ss, token, ',');
	btcSet.first = token;

	std::getline(ss, token, ',');
	std::stringstream ss2(token);
	ss2 >> exchangeRate;
	btcSet.second = exchangeRate;

	if (ss2.fail())
		return false;
	else
		return true;
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream inputFile;
	std::string dateSet;
	std::pair<std::string, float> btcSet;

	inputFile.open("data.csv");

	if (inputFile.is_open())
	{
		while (std::getline(inputFile, dateSet))
		{
			if (separateCsv(dateSet, btcSet))
				db.insert(btcSet);
		}
		inputFile.close();
	}
	else
	{
		std::cout << "not exist database" << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& origin)
{
	this->db = origin.db;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& origin)
{
	this->db = origin.db;

	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

static bool checkFormat(const std::string& input)
{
	int count = 0;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '|')
			count++;
	}

	if (count != 1) {
		std::cout << "Error: invalid input format." << std::endl;
		return false;
	}

	return true;
}
static bool checkDate(const std::string& date)
{
	int count = 0;
	std::string ymd[3];

	for (size_t i = 0; i < date.length(); i++)
	{
		if (date[i] == '-')
			count++;
	}

	if (count != 2)
		return false;

	std::stringstream ss(date);
	std::getline(ss, ymd[0], '-');
	std::getline(ss, ymd[1], '-');
	std::getline(ss, ymd[2], ' ');

	if (!isNumber(ymd[0]) || !isNumber(ymd[1]) || !isNumber(ymd[2]))
        return false;
	// 01, 1 자릿수도 구분해야되나?

	int year = std::atoi(ymd[0].c_str());
	int month = std::atoi(ymd[1].c_str());
    int day = std::atoi(ymd[2].c_str());

    if (month < 1 || month > 12)
        return false;

    // 월별 일수 확인
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // 윤년 계산
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29; // 2월 일수 수정
    }

    // 일이 해당 월의 최대 일수 범위 내에 있는지 확인
    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

static bool checkValue(const std::string& value)
{
	std::stringstream ss(value);
	float vval;

	ss >> vval;

	if (ss.fail()) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	if (vval < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	if (vval > 1000.0) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::Exchange(const std::string& input)
{
	std::string date;
	std::string value;

	if (!checkFormat(input))
		return;

	std::stringstream ss(input);

	std::getline(ss, date, '|');
	if (!checkDate(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	std::getline(ss, value, '|');
	if (!checkValue(value))
		return;

	std::map<std::string, float>::iterator it;
	it = db.upper_bound(date);

	if (it == db.begin()) {
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	it--;
	float realVal = std::atof(value.c_str());

	std::cout << date << " => " << realVal << " = " << realVal * it->second << std::endl;

	// 2011-01-03(Date) => 3(value) = 0.9(Exchange Rate * Value)
}

static bool isNumber(const std::string str)
{
	for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
	
    return true;
}


/*
	2001-01-03 | 3

	2001-0| 1-03 | |  3 | 32 |
*/
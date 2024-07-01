#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	std::ifstream inputFile;
	std::string dateSet;
	BitcoinExchange market;

	if (argc != 2) {
		std::cout << "bad input" << std::endl;
		return 1;
	}

	inputFile.open(argv[1]);

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			std::getline(inputFile, dateSet);
			market.Exchange(dateSet);
		}
		inputFile.close();
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
	}

	return 0;
}
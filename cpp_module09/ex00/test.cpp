#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

static std::pair<std::string, float> separate(std::string str)
{
	std::pair<std::string, float> btcSet;
	std::string token;
	std::stringstream ss(str);
	float exchangeRate;

	std::getline(ss, token, ',');
	btcSet.first = token;

	std::getline(ss, token, ',');

	std::stringstream ss2(token);
	ss2 >> exchangeRate;

	if (ss2.fail())
		btcSet.second = 0;
	else
		btcSet.second = exchangeRate;
	
	return btcSet;
}

int main()
{
	std::map<std::string, float> db;

	std::ifstream inputFile;
	std::string dateSet;
	std::pair<std::string, float> btcSet;

	inputFile.open("data.csv");

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			std::getline(inputFile, dateSet);
			btcSet = separate(dateSet);
			db.insert(btcSet);
		}
		inputFile.close();

		 for (std::map<std::string, float>::iterator it=db.begin(); it!=db.end(); ++it)
    		std::cout << it->first << " => " << it->second << '\n';
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
	}

	return 0;
}
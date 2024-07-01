# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


class BitcoinExchange
{
	private:
		std::map<std::string, float> db;
	public:
		BitcoinExchange(); // data.csv 디폴트
		BitcoinExchange(const BitcoinExchange& origin);
		BitcoinExchange& operator= (const BitcoinExchange& origin);
		~BitcoinExchange();

		void Exchange(const std::string& input);
};

# endif
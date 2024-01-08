#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();
		std::string harlLevel[4];
		void (Harl::*complainFunc[4])(void);
	public:
		Harl();
		void complain(std::string level);
};


#endif
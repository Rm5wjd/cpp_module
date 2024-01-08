#include "Harl.hpp"

Harl::Harl()
{
	harlLevel[0] = "DEBUG";
	harlLevel[1] = "INFO";
	harlLevel[2] = "WARNING";
	harlLevel[3] = "ERROR";

	complainFunc[0] = &Harl::debug;
	complainFunc[1] = &Harl::info;
	complainFunc[2] = &Harl::warning;
	complainFunc[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	for(int i = 0; i < 4; i++) {
		if (harlLevel[i] == level) {
			(this->*complainFunc[i])();
			return;
		}
	}
	std::cout << "not exist level messeage." << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
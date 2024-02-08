# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T>
void easyfind(T cont, int value)
{
	typename T::iterator reitr;

	reitr = std::find(cont.begin(), cont.end(), value);

	if (reitr != cont.end())
		std::cout << *reitr << std::endl;
	else
		throw std::runtime_error("not found");
}

# endif
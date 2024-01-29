# ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

struct Funtor
{
	template <typename T>
	void operator()(T& e)
	{
		std::cout << e << std::endl;
	}
};

template <typename T, typename Func>
void iter(T* addr, std::size_t len, Func& func)
{
	for (std::size_t i = 0; i < len; i++)
		func(addr[i]);
}

# endif
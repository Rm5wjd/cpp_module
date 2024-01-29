# ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& origin);
		Array& operator= (const Array& origin);
		void* operator new[](std::size_t )
		~Array();
};


# endif
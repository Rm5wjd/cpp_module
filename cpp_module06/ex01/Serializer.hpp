# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

struct Data
{
	int a;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& origin);
		Serializer& operator=(const Serializer& origin);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

# endif
#include "Serializer.hpp"

int main()
{
	Data *d1 = new Data;
	d1->a = 20;
	Data *d2;

	uintptr_t uint1 = Serializer::serialize(d1);
	d2 = Serializer::deserialize(uint1);

	std::cout << d1 << std::endl;
	std::cout << d1->a << std::endl;
	std::cout << uint1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d2->a << std::endl;
}
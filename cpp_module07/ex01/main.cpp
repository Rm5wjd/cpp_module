#include "iter.hpp"

int main()
{
	Funtor print;
	
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	::iter(a, 10, print);
}
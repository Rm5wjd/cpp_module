#include "Base.hpp"

int main()
{
	srand(time(NULL));
	Base* b1 = generate();
	Base* b2 = generate();
	Base* b3 = generate();

	Base& b4 = *b1;
	Base& b5 = *b2;
	Base& b6 = *b3;

	identify(b1);
	identify(b2);
	identify(b3);

	identify(b4);
	identify(b5);
	identify(b6);
}
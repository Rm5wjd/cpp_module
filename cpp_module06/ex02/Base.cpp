#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{}

Base* generate()
{
	static bool seeded = false;
	
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	int r_num = rand() % 3 + 1;

	if (r_num == 1)
		return new A();
	else if (r_num == 2)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "real type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "real type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "real type is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		p = dynamic_cast<A&>(p);
		std::cout << "real type is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}

	try
	{
		p = dynamic_cast<B&>(p);
		std::cout << "real type is B" << std::endl;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}

	try
	{
		p = dynamic_cast<C&>(p);
		std::cout << "real type is C" << std::endl;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}	
}
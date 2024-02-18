#include "Span.hpp"

int main()
{
	//try
	//{
	//	Span sp = Span(5);
	//	sp.addNumber(6);

	//	sp.addNumber(3);
	//	sp.addNumber(17);
	//	sp.addNumber(9);
	//	sp.addNumber(24);

	//	//sp.addNumber(11);
	//	//sp.addNumber(12);

	//	std::cout << sp.shortestSpan() << std::endl;
	//	std::cout << sp.longestSpan() << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}

	try
	{
		Span sp2 = Span(1000);
		sp2.addManyNumber(500);
		sp2.addManyNumber(499);
		sp2.addManyNumber(2000);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
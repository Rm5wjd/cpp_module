# ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int> cont;
		int size;
		int capacity;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& origin);
		Span& operator= (const Span& origin);
		~Span();

		void addNumber(int num);
		void addManyNumber(unsigned int n);
		int shortestSpan();
		int longestSpan();
};

# endif
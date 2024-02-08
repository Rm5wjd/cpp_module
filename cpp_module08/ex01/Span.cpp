#include "Span.hpp"

int createRandValue();

Span::Span()
	: size(0), capacity(0)
{

}

Span::Span(unsigned int n)
	: size(0), capacity(n)
{

}

Span::Span(const Span& origin)
{
	*this = origin;
}

Span& Span::operator= (const Span& origin)
{
	size = origin.size;
	capacity = origin.capacity;

	for (int i = 0; i < capacity; i++) {
		cont[i] = origin.cont[i];
	}

	return *this;
}

Span::~Span()
{}

void Span::addNumber(int num)
{
	if (size < capacity) {
		cont.push_back(num);
		size++;
	}
	else {
		throw std::runtime_error("Span size is over");
	}
}

int Span::shortestSpan()
{
	if (size <= 1)
		throw std::runtime_error("Number not enough");
	std::sort(cont.begin(), cont.end());

	int min = INT_MAX;
	for (int i = 0; i < size - 1; i++) {
		if (cont[i + 1] - cont[i] < min)
			min = cont[i + 1] - cont[i];
	}

	return min;
}

int Span::longestSpan()
{
	if (size <= 1)
		throw std::runtime_error("Number not enough");
	std::sort(cont.begin(), cont.end());

	return *(cont.end() - 1) - *(cont.begin());
}

void Span::addManyNumber(unsigned int n)
{
	std::srand(unsigned(std::time(0)));
	
	for (int i = 0; i < static_cast<int>(n); i++)
		cont.push_back(0);
	
	std::generate(cont.begin(), cont.end(), createRandValue);
	size += n;

	for (int i = 0; i < 10; i++)
		std::cout << "cont:" << cont[i] << std::endl;
}

int createRandValue()
{
	int randValue = std::rand() % 1000;
	return randValue;
}
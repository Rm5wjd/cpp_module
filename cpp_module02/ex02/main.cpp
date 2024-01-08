#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}

int main(void)
{
	Fixed a(10.1016f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "\na: " << a << " b: " << b << std::endl;
	std::cout << "a: "<< a << std::endl;
	std::cout << "++a: "<< ++a << std::endl;
	std::cout << "a: "<< a << std::endl;
	std::cout << "a++: "<< a++ << "\n" << std::endl;

	std::cout << "a: "<< a << std::endl;
	std::cout << "--a: "<< --a << std::endl;
	std::cout << "a: "<< a << std::endl;
	std::cout << "a--: "<< a-- << "\n" << std::endl;

	std::cout << "b: " << b << std::endl;
	std::cout << "max( a, b ): " << Fixed::max( a, b ) << std::endl;
	std::cout << "min( a, b ): " << Fixed::min( a, b ) << "\n" << std::endl;

	std::cout << "\na: " << a << " b: " << b << std::endl;
	std::cout << "a + b: "<< a + b << std::endl;
	std::cout << "a - b: "<< a - b << std::endl;
	std::cout << "a * b: "<< a * b << std::endl;
	std::cout << "a / b: "<< a / b << "\n" << std::endl;

	std::cout << "\na: " << a << " b: " << b << std::endl;
	std::cout << "a > b: "<< ((a > b) ? "true" : "false") << std::endl;
	std::cout << "a < b: "<< ((a < b) ? "true" : "false") << std::endl;
	std::cout << "a >= b: "<< ((a >= b) ? "true" : "false") << std::endl;
	std::cout << "a <= b: "<< ((a <= b) ? "true" : "false") << std::endl;
	std::cout << "a == b: "<< ((a == b) ? "true" : "false") << std::endl;
	std::cout << "a != b: "<< ((a != b) ? "true" : "false") << std::endl;

	return 0;
}
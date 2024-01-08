#include "Fixed.hpp"

Fixed::Fixed() :intCont(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value);
}

Fixed::Fixed(const float floatNum)
{
	std::cout << "Float constructor called" << std::endl;
	intCont = (int)(std::roundf(floatNum * (1 << fracBits)));
}

Fixed& Fixed::operator=(const Fixed& origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	intCont = origin.intCont;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return intCont;
}

void Fixed::setRawBits(int const raw)
{
	intCont = (raw << 8);
}

float Fixed::toFloat(void) const
{
	return ((float)intCont / (float)(1 << fracBits));
}

int Fixed::toInt(void) const
{
	return (int)(intCont >> 8);
}
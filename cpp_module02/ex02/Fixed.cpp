#include "Fixed.hpp"

Fixed::Fixed() :intCont(0) 
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin)
{
	intCont = origin.getRawBits();
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->setRawBits(value);
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum)
{
	intCont = (int)(std::roundf(floatNum * (1 << fracBits)));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& origin)
{
	intCont = origin.getRawBits();
	// std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return intCont;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed& f) const {
	return (this->getRawBits() > f.getRawBits() ? true : false);
}

bool Fixed::operator<(const Fixed& f) const {
	return (this->getRawBits() < f.getRawBits() ? true : false);
}

bool Fixed::operator>=(const Fixed& f) const {
	return (this->getRawBits() >= f.getRawBits() ? true : false);
}

bool Fixed::operator<=(const Fixed& f) const {
	return (this->getRawBits() <= f.getRawBits() ? true : false);
}

bool Fixed::operator==(const Fixed& f) const {
	return (this->getRawBits() == f.getRawBits() ? true : false);
}

bool Fixed::operator!=(const Fixed& f) const {
	return (this->getRawBits() != f.getRawBits() ? true : false);
}

Fixed Fixed::operator+(const Fixed& f) const {
	Fixed temp(this->toFloat() + f.toFloat());
	return temp;
}

Fixed Fixed::operator-(const Fixed& f) const {
	Fixed temp(this->toFloat() - f.toFloat());
	return temp;
}

Fixed Fixed::operator*(const Fixed& f) const {
	Fixed temp(this->toFloat() * f.toFloat());
	return temp;
}

Fixed Fixed::operator/(const Fixed& f) const {
	Fixed temp;
	if (f.intCont == 0)
		return temp;
	Fixed reTemp(this->toFloat() / f.toFloat());
	return reTemp;
}

Fixed& Fixed::operator++() {
	this->intCont += 1; 
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(this->toFloat());
	this->intCont += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	this->intCont -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(this->toFloat());
	this->intCont -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& one, Fixed& two) {
	return (one > two ? two : one);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two) {
	return (one > two ? two : one);
}

Fixed& Fixed::max(Fixed& one, Fixed& two) {
	return (one < two ? two : one);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two) {
	return (one < two ? two : one);
}
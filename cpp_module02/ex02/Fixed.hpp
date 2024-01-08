#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int intCont;
		static const int fracBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float floatNum);
		Fixed(const Fixed& origin);
		Fixed& operator=(const Fixed& origin);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed& min(Fixed& one, Fixed& two);
		static const Fixed& min(const Fixed& one, const Fixed& two);
		static Fixed& max(Fixed& one, Fixed& two);
		static const Fixed& max(const Fixed& one, const Fixed& two);

		bool operator>(const Fixed& f) const;
		bool operator<(const Fixed& f) const;
		bool operator>=(const Fixed& f) const;
		bool operator<=(const Fixed& f) const;
		bool operator==(const Fixed& f) const;
		bool operator!=(const Fixed& f) const;

		Fixed operator+(const Fixed& f) const;
		Fixed operator-(const Fixed& f) const;
		Fixed operator*(const Fixed& f) const;
		Fixed operator/(const Fixed& f) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
};


#endif
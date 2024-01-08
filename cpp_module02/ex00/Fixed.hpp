#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int intCont;
		static const int fracBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& origin);
		Fixed& operator=(const Fixed& origin);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif
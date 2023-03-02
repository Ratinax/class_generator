#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed::Fixed &operator=(const Fixed &f)
{
	std::cout << "Fixed overload equal constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed destructor called" << std::endl;
}

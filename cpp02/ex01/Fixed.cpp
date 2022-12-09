#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_fractionalBits(8);

// Constructors / Destructors -----
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number << this->_fractionalBits);
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(number * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
// ----------

int	Fixed::getRawBits() const {
	return this->_intNumber;
}

void	Fixed::setRawBits(const int raw) {
	this->_intNumber = raw;
}

float	Fixed::toFloat() const {
	return ((float)this->getRawBits() / (1 << this->_fractionalBits));
}

int	Fixed::toInt() const {
	return (this->getRawBits() >> this->_fractionalBits);
}

// Operators ----------
Fixed& Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());

	return *this;
}

std::ostream&	operator<<(std::ostream &flux, const Fixed &fixed) {
	flux << fixed.toFloat();
	return flux;
}
// ----------

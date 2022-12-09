#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_fractionalBits(8);

/* ************************************************************************** */
/*                         CONSTRUCTORS / DESTRUCTORS                         */
/* ************************************************************************** */

Fixed::Fixed() {
	this->setRawBits(0);
}

Fixed::Fixed(const int number) {
	this->setRawBits(number << this->_fractionalBits);
}

Fixed::Fixed(const float number) {
	this->setRawBits((int)roundf(number * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::~Fixed() {}

/* ************************************************************************** */
/*                                  FUNCTIONS                                 */
/* ************************************************************************** */

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

Fixed&	Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

Fixed&	Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 >= fixed2)
		return fixed1;
	return fixed2;
}

const Fixed&	Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

const Fixed&	Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 >= fixed2)
		return fixed1;
	return fixed2;
}

/* ************************************************************************** */
/*                                  OPERATORS                                 */
/* ************************************************************************** */

Fixed& Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());

	return *this;
}

Fixed&	Fixed::operator++() {
	this->_intNumber++;

	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	buffer = *this;

	this->_intNumber++;
	return buffer;
}

Fixed&	Fixed::operator--() {
	this->_intNumber--;

	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	buffer = *this;

	this->_intNumber--;
	return buffer;
}

Fixed	Fixed::operator+(const Fixed &ref) {
	Fixed	buffer(this->toFloat() + ref.toFloat());

	return buffer;
}

Fixed	Fixed::operator-(const Fixed &ref) {
	Fixed	buffer(this->toFloat() - ref.toFloat());

	return buffer;
}

Fixed	Fixed::operator*(const Fixed &ref) {
	Fixed	buffer(this->toFloat() * ref.toFloat());

	return buffer;
}

Fixed	Fixed::operator/(const Fixed &ref) {
	Fixed	buffer(this->toFloat() / ref.toFloat());

	return buffer;
}

bool	Fixed::operator>(const Fixed &ref) const {
	return (this->toFloat() > ref.toFloat());
}

bool	Fixed::operator<(const Fixed &ref) const {
	return (this->toFloat() < ref.toFloat());
}

bool	Fixed::operator>=(const Fixed &ref) const {
	return (this->toFloat() >= ref.toFloat());
}

bool	Fixed::operator<=(const Fixed &ref) const {
	return (this->toFloat() <= ref.toFloat());
}

bool	Fixed::operator==(const Fixed &ref) const {
	return (this->toFloat() == ref.toFloat());
}

bool	Fixed::operator!=(const Fixed &ref) const {
	return (this->toFloat() != ref.toFloat());
}

std::ostream&	operator<<(std::ostream &flux, const Fixed &fixed) {
	flux << fixed.toFloat();

	return flux;
}

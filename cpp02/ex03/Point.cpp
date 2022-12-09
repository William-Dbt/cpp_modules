#include <iostream>
#include "Point.hpp"

Point::Point() : _x(1), _y(1) {}

Point::Point(Fixed const pointX, Fixed const pointY) : _x(pointX), _y(pointY) {}

Point::Point(Point const &point) {
	*this = point;
}

Point::~Point() {}

//	Destroy the this pointer by calling destructor
//	Crate new C object with new (this) that take the memory's place already allocate
Point& Point::operator=(Point const &point) {
	if (this != &point) {
		this->~Point();
		new (this) Point(point.getX(), point.getY());
	}
	return *this;
}

Fixed	Point::getX() const {
	return this->_x;
}

Fixed	Point::getY() const {
	return this->_y;
}

std::ostream&	operator<<(std::ostream &flux, Point const &point) {
	flux << '(' << point.getX() << ',' << point.getY() << ')';

	return flux;
}

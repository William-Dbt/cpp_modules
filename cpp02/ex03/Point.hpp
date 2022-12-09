#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class	Point {
	public:
		Point();
		Point(Fixed const pointX, Fixed const pointY);
		Point(Point const &point);
		~Point();

		Point&	operator=(Point const &point);

		Fixed	getX() const;
		Fixed	getY() const;
		float	getXVal() const;
		float	getYVal() const;

	private:
		Fixed	const _x;
		Fixed	const _y;
};

std::ostream&	operator<<(std::ostream &flux, Point const &point);

bool			bsp(Point const ptA, Point const ptB, Point const ptC, Point const ptPoint);

#endif
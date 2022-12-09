#include <iostream>
#include "Point.hpp"

/* https://math.stackexchange.com/questions/51326/determining-if-an-arbitrary-point-lies-inside-a-triangle-defined-by-three-points
	Link of stack discussion to get example of a triangle
*/
int	main() {
	Fixed	aX(1), aY(aX);
	Fixed	bX(4), bY(2);
	Fixed	cX(bY), cY(7);
	Fixed	pX(cX), pY(3);
	Point	const a(aX, aY);
	Point	const b(bX, bY);
	Point	const c(cX, cY);
	Point	const p(pX, pY);

	std::cout << "The triangle is defined by three points as:" << std::endl;
	std::cout << 'A' << a << std::endl;
	std::cout << 'B' << b << std::endl;
	std::cout << 'C' << c << std::endl;
	std::cout << "Is the point P" << p << " in the triangle?" << std::endl << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "The point P" << p << " is in the triangle." << std::endl;
	else
		std::cout << "The point P" << p << " isn't in the triangle." << std::endl;
	return 0;
}
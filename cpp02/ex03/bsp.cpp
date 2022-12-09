#include <iostream>
#include "Point.hpp"

/* 
	To know if a point is in a triangle (given by three points), we have to check two vectors from a vertex
	of the triangle (as A for example) and that the width of the vector from A to B is 1
	We get the two width of the vector A->B and A->C with w1 and w2 and,
	if w1 > 0, w2 > 0 and w1 + w2 < 1, the point P is in the triangle
	if w1 == 0 or w2 == 0, the point P is on a vertex
	if w1 == 0 and 0 < w2 < 1 or w2 == 0 and - < w1 < 1 or w1 + w2 == 1, the point P is a on edge
	Ref: https://www.youtube.com/watch?v=HYAgJN3x4GA&list=PLFt_AvWsXl0cD2LPxcjxVjWTQLxJqKpgZ&ab_channel=SebastianLague
*/
bool	bsp(Point const ptA, Point const ptB, Point const ptC, Point const ptPoint) {
	Fixed	s1, s2, s3, s4;
	Fixed	w1, w2;

	s1 = ptC.getY() - ptA.getY();
	s2 = ptC.getX() - ptA.getX();
	s3 = ptB.getY() - ptA.getY();
	s4 = ptPoint.getY() - ptA.getY();

	w1 = (ptA.getX() * s1 + s4 * s2 - ptPoint.getX() * s1) / (s3 * s2 - (ptB.getX() - ptA.getX()) * s1);
	w2 = (s4 - w1 * s3) / s1;

	if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
		return true;
	return false;
}

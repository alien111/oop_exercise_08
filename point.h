#ifndef D_POINT_H_
#define D_POINT_H_

#include <iostream>

struct Point {

	double x, y;
	
};

std::istream& operator>> (std::istream& is, Point &p);
std::ostream& operator<< (std::ostream& os, const Point &p);
bool operator == (Point a, Point b);

#endif

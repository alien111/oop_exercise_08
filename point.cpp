#include "point.h"

std::istream& operator >> (std::istream& is, Point &p) {
	return is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os, const Point &p) {
    return os << p.x << " " << p.y << '\n';
}

bool operator == (Point a, Point b) {
	return (a.x == b.x && a.y == b.y);
}
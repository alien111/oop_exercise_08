#include "vector.h"

Vector::Vector(Point a, Point b) {
	x = b.x - a.x;
	y = b.y - a.y;
}

double Vector::length() const{
	return sqrt(x * x + y * y);
}

bool isParallel(const Vector a, const Vector b) {
	return (a.x * b.y - a.y * b.y) == 0;
}

bool isPerpendicular(const Vector a, const Vector b) {
	return (a.x * b.x + a.y * b.y) == 0;
}

double operator* (Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

bool Vector::operator== (Vector b) {
	return std::abs(x - b.x) < std::numeric_limits<double>::epsilon() * 100 
	&& std::abs(y - b.y) < std::numeric_limits<double>::epsilon() * 100;
}
#ifndef VECTOR_H_
#define VECTOR_H_ 

#include "point.h"
#include <cmath>
#include <numeric>
#include <limits>

class Vector {
public:
	explicit Vector(Point a, Point b);
	double length() const;
	double x;
	double y;
	friend double operator* (Vector a, Vector b) ;
	bool operator== (Vector b);
};

bool isParallel(const Vector a, const Vector b);
bool isPerpendicular(const Vector a, const Vector b);



#endif
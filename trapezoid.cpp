#include "trapezoid.h"
#include <iostream>
#include <cmath>

Trapezoid::Trapezoid(std::istream& is) {
	is >> p1 >> p2 >> p3 >> p4;

	if (isParallel(Vector(p1, p4), Vector(p2, p3))) {

	} else if (isParallel(Vector(p1, p3), Vector(p4, p2))) {

		Point tmp;
		tmp = p2;
		p2 = p4;
		p4 = tmp;
		tmp = p3;
		p3 = p4;
		p4 = tmp;

	} else if (isParallel(Vector(p1, p3), Vector(p2, p4))) {

		Point tmp;
		tmp = p3;
		p3 = p4;
		p4 = tmp;

	} else if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("At least 2 sides of trapeze must be parallel");
	}
}

Trapezoid::Trapezoid(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4) {

	if (isParallel(Vector(p1, p4), Vector(p2, p3))) {

	} else if (isParallel(Vector(p1, p3), Vector(p4, p2))) {

		Point tmp;
		tmp = p2;
		p2 = p4;
		p4 = tmp;
		tmp = p3;
		p3 = p4;
		p4 = tmp;

	} else if (isParallel(Vector(p1, p3), Vector(p2, p4))) {

		Point tmp;
		tmp = p3;
		p3 = p4;
		p4 = tmp;

	} else if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("At least 2 sides of trapeze must be parallel");
	}

}

Point Trapezoid::center() const{
	Point p;
	p.x = (p1.x + p2.x + p3.x + p4.x) / 4;
	p.y = (p1.y + p2.y + p3.y + p4.y) / 4;
	return p; 
}

void Trapezoid::print(std::ostream& os) const{
	os << "Trapezoid\n";
	os << p1 << p2 << p3 << p4;
}

void Trapezoid::input(std::istream& is)  {
	Point p1,p2,p3,p4;
	is >> p1 >> p2 >> p3 >> p4;
	*this = Trapezoid(p1,p2,p3,p4);
}

double Trapezoid::square() const{
	
	double a = p2.y - p3.y;
	double b = p3.x - p2.x;
	double c = p2.x * p3.y - p3.x * p2.y;
	double height = (std::abs(a * p1.x + b * p1.y + c) / sqrt(a * a + b * b));
	return (Vector(p1, p2).length() + Vector(p3, p4).length()) * height / 2;
}
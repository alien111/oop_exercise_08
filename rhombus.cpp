#include "rhombus.h"
#include <iostream>
#include <cmath>


Rhombus::Rhombus(std::istream& is) {
	is >> p1 >> p2 >> p3 >> p4;

	if (Vector(p1, p2).length() == Vector(p2, p3).length() && Vector(p2, p3).length() == Vector(p3, p4).length()
	 && Vector(p1, p2).length() == Vector(p1, p4).length()) {

	} else if (Vector(p1, p2).length() == Vector(p2, p4).length() && Vector(p2, p4).length() == Vector(p3, p4).length()
	 && Vector(p1, p2).length() == Vector(p1, p3).length()) {
		Point tmp = p4;
		p4 = p3;
		p3 = tmp;
	} else if (Vector(p1, p3).length() == Vector(p4, p3).length() && Vector(p4, p3).length() == Vector(p2, p4).length()
	 && Vector(p1, p2).length() == Vector(p1, p3).length()) {
		Point tmp = p4;
		p4 = p3;
		p3 = tmp;
	} else if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("This is not a Rhombus, sides are not equal");
	}

	
	Vector v1(p1, p2);
	Vector v2(p2, p3);
	Vector v3(p3, p4);
	Vector v4(p4, p1);

	double cos1 = v1 * v2 / (v1.length() * v2.length());
	double cos2 = v2 * v3 / (v2.length() * v3.length());
	double cos3 = v3 * v4 / (v3.length() * v4.length());
	double cos4 = v1 * v4 / (v1.length() * v4.length());

	if (cos1 != cos3 || cos2 != cos4) {
		throw std::logic_error("This is not a Rhombus, opposite angles are not equal");
	}
}

Rhombus::Rhombus(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4) {

	if (Vector(p1, p2).length() == Vector(p2, p3).length() && Vector(p2, p3).length() == Vector(p3, p4).length()
	 && Vector(p1, p2).length() == Vector(p1, p4).length()) {

	} else if (Vector(p1, p2).length() == Vector(p2, p4).length() && Vector(p2, p4).length() == Vector(p3, p4).length()
	 && Vector(p1, p2).length() == Vector(p1, p3).length()) {
		Point tmp = p4;
		p4 = p3;
		p3 = tmp;
	} else if (Vector(p1, p3).length() == Vector(p4, p3).length() && Vector(p4, p3).length() == Vector(p2, p4).length()
	 && Vector(p1, p2).length() == Vector(p1, p3).length()) {
		Point tmp = p4;
		p4 = p3;
		p3 = tmp;
	} else if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("This is not a Rhombus, sides are not equal");
	}

	
	Vector v1(p1, p2);
	Vector v2(p2, p3);
	Vector v3(p3, p4);
	Vector v4(p4, p1);

	double cos1 = v1 * v2 / (v1.length() * v2.length());
	double cos2 = v2 * v3 / (v2.length() * v3.length());
	double cos3 = v3 * v4 / (v3.length() * v4.length());
	double cos4 = v1 * v4 / (v1.length() * v4.length());

	if (cos1 != cos3 || cos2 != cos4) {
		throw std::logic_error("This is not a Rhombus, opposite angles are not equal");
	}

}

Point Rhombus::center() const{
	Point p;
	p.x = (p1.x + p2.x + p3.x + p4.x) / 4;
	p.y = (p1.y + p2.y + p3.y + p4.y) / 4;
	return p;
}

void Rhombus::print(std::ostream& os) const{
	os << "Rhombus\n";
	os << p1 << p2 << p3 << p4;
}

void Rhombus::input(std::istream& is)  {
	Point p1,p2,p3,p4;
	is >> p1 >> p2 >> p3 >> p4;
	*this = Rhombus(p1,p2,p3,p4);
}

double Rhombus::square() const{
	return Vector(p1, p3).length() * Vector(p2, p4).length() / 2;
}
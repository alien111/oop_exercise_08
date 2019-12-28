#include "rectangle.h"
#include <iostream>
#include <cmath>


Rectangle::Rectangle(std::istream& is) {
	is >> p1 >> p2 >> p3 >> p4;

	if (isPerpendicular(Vector(p1, p2), Vector(p1, p4)) && isPerpendicular(Vector(p1, p2), Vector(p2, p3)) && 
		isPerpendicular(Vector(p2, p3), Vector(p3, p4)) && isPerpendicular(Vector(p3, p4), Vector(p1, p4))) {



	} else if (isPerpendicular(Vector(p1, p4), Vector(p4, p2)) && isPerpendicular(Vector(p4, p2), Vector(p2, p3)) && 
		isPerpendicular(Vector(p2, p3), Vector(p3, p1)) && isPerpendicular(Vector(p1, p3), Vector(p1, p4))) {

			Point tmp;
			tmp = p1;
			p1 = p4;
			p4 = tmp;

	} else if (isPerpendicular(Vector(p1, p2), Vector(p2, p4)) && isPerpendicular(Vector(p2, p4), Vector(p4, p3)) && 
		isPerpendicular(Vector(p4, p3), Vector(p3, p1)) && isPerpendicular(Vector(p3, p1), Vector(p1, p2))) {

			Point tmp;
			tmp = p3;
			p3 = p4;
			p4 = tmp;

	} else if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("That's not a Rectangle, sides are not Perpendicular");
	}

	if (!(Vector(p1, p2).length() == Vector(p3, p4).length() && Vector(p2, p3).length() == Vector(p1, p4).length())) {
		throw std::logic_error("That's not a Rectangle, sides are not equal");
	}

}

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4) {

	if (isPerpendicular(Vector(p1, p2), Vector(p1, p4)) && isPerpendicular(Vector(p1, p2), Vector(p2, p3)) && 
		isPerpendicular(Vector(p2, p3), Vector(p3, p4)) && isPerpendicular(Vector(p3, p4), Vector(p1, p4))) {



	} else if (isPerpendicular(Vector(p1, p4), Vector(p4, p2)) && isPerpendicular(Vector(p4, p2), Vector(p2, p3)) && 
		isPerpendicular(Vector(p2, p3), Vector(p3, p1)) && isPerpendicular(Vector(p1, p3), Vector(p1, p4))) {

			Point tmp;
			tmp = p1;
			p1 = p4;
			p4 = tmp;

	} else if (isPerpendicular(Vector(p1, p2), Vector(p2, p4)) && isPerpendicular(Vector(p2, p4), Vector(p4, p3)) && 
		isPerpendicular(Vector(p4, p3), Vector(p3, p1)) && isPerpendicular(Vector(p3, p1), Vector(p1, p2))) {

			Point tmp;
			tmp = p3;
			p3 = p4;
			p4 = tmp;

	} else if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("That's not a Rectangle, sides are not Perpendicular");
	}

	if (!(Vector(p1, p2).length() == Vector(p3, p4).length() && Vector(p2, p3).length() == Vector(p1, p4).length())) {
		throw std::logic_error("That's not a Rectangle, sides are not equal");
	}


}

Point Rectangle::center() const{
	Point p;
	p.x = (p1.x + p2.x + p3.x + p4.x) / 4;
	p.y = (p1.y + p2.y + p3.y + p4.y) / 4;
	return p;
}

void Rectangle::print(std::ostream& os) const{
	os << "Rectangle\n";
	os << p1 << p2 << p3 << p4;
}

void Rectangle::input(std::istream& is) {
	Point p1,p2,p3,p4;
	is >> p1 >> p2 >> p3 >> p4;
	*this = Rectangle(p1,p2,p3,p4);
}

double Rectangle::square() const{
	
	return Vector(p1, p2).length() * Vector(p2, p3).length();

}
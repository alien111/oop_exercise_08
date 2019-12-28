#ifndef D_TRAPEZOID_H_
#define D_TRAPEZOID_H_ 

#include "figure.h"

class Trapezoid : public Figure {
public:
	Trapezoid() = default;
	Trapezoid (std::istream&);
	Trapezoid (Point p1, Point p2, Point p3, Point p4);

	Point center() const override;
	void print(std::ostream&) const override;
	void input(std::istream&) override;
	double square() const override;
private:
	Point p1, p2, p3, p4;
};


#endif
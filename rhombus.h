
#ifndef D_RHOMBUS_H_
#define D_RHOMBUS_H_ 

#include "figure.h"

class Rhombus : public Figure {
public:
	Rhombus() = default;
	Rhombus (std::istream&);
	Rhombus (Point p1, Point p2, Point p3, Point p4);

	Point center() const override;
	void print(std::ostream&) const override;
	void input(std::istream&) override;
	double square() const override;
private:
	Point p1, p2, p3, p4;
};


#endif
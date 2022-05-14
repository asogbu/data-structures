#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle: public Shape {
	private:
		int length;
		int width;

	public:
		Rectangle(int length_in = 0, int width_in = 0): length(length_in), width(width_in) {}
		virtual int GetArea() const {return length * width;}
		virtual void Draw() const {std::cout << "Drawing a rectangle..." << std::endl;}
		virtual ~Rectangle() {}
};

#endif

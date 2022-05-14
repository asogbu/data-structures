#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle: public Shape {
	private:
		int length;
		int height;
	
	public:
		Triangle(int length_in = 0, int height_in = 0): length(length_in), height(height_in) {}
		virtual int GetArea() const {return (length * height)/2;}
		virtual void Draw() const {std::cout << "Drawing a triangle..." << std::endl;}
		virtual ~Triangle() {}
};

#endif

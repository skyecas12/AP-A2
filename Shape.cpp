#include "Shape.h"
Shape::Shape()
{
	isCircular = 0;
	x = 0;
	y = 0;
	area = 0;
	perimeter = 0;
	isCircular = false;
	leftTop.first = 0;
	leftTop.second = 0;
	//initalising shape protected variables with default constructor.
}
//no methods initalised in CPP file due to using method overriding as Shape is a virtual class which will-
// - be inherited from rectangle, square, and circle.


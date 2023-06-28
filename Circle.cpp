#include "Circle.h"

Circle::Circle(float _x, float _y, float r)
{
	radius = r;
	x = _x;
	y = _y;
	leftTop.first = _x;
	leftTop.second = _y;
	isCircular = true;
	//setting isCircular to true for Circle class.
	//initalising Circle members and assigning them to constructor parameters
}
float Circle::calculateArea()
{
	area = 3.14159 * radius * radius;
	return area;
	//calculating the area with pi and radius using protected shape member "area".
	//returning area
}
float Circle::calculatePerimeter()
{
	perimeter = 2 * 3.14159 * radius;
	return perimeter;
	//calculating the perimeter with pi^2 and radius using protected shape member "perimeter".
	//returning perimeter.
}
string Circle::calculatePoints()
{
	Points.clear();
	//clearing Points vector for when another shape is called or move/scale is called.
	pair<int, int>left_Top(leftTop.first, leftTop.second);
	//assigning left_top with the pair leftTop, with regards to x as first, and y as second.
	pntObj.calculateCoordinates(left_Top);
	Points.push_back(pntObj);
	//assigning left_top into Point class calculateCoordinates, pushing back to store into Points vector object.

	pair<int, int>right_Bottom(leftTop.first + 2 * radius, leftTop.second + 2 * radius);
	pntObj.calculateCoordinates(right_Bottom);
	Points.push_back(pntObj);
	//assigning right_bottom to point method calculateCoordinate then pushing back the pair into Points vector.

	string printPts;
	//creating a string to return all the Points from printPoints method in points, which returns x and y in the class.
	for (auto pnt : Points)
	{
		printPts = printPts + pnt.printPoints();
	}
	//Using for expressed range loop to loop in Points and to assign printPts with all points from in vector and being returned
	//from printPoints methods.

	
	return "[" + printPts + "]";
	//returning Points.
}
void Circle::move(int x, int y)
{
	leftTop.first = x;
	leftTop.second = y;
	calculatePoints();
	//assigning leftTop pair with method argument x and y.
	//calling out calculatePoints to re-calculate new points when move called.
}
void Circle::scale(float newX, float newY)
{
	radius = radius * x;
	//scaling the radius with x.
	calculatePoints();
	//calling calculatePoints to update Points.
}
string Circle::toString()
{
	stringstream circleStr;
	circleStr.precision(1);
	//creating a stringstream variable and setting precision to 1 to stop excessive decimal numbers after 1 decimal place.
	circleStr << fixed << "Circle[r=" << radius << "]" << "\n" << "Points " << calculatePoints() << 
		"\n" << "Area=" << calculateArea() << " " << "Perimeter=" << calculatePerimeter();
	//formatting fixed circleStr and assigning multiple functions to the stringstream so it can be converted to 1 string
	//and the one string can be returned.
	string circleInfo = circleStr.str();
	//converting circleStr to string circleInfo.addR 100 100 50 200 
	return circleInfo;
	//returning circleInfo.
}


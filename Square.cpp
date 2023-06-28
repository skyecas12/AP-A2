#include "Square.h"
Square::Square(float _x, float _y, float _e)
{
	edge = _e;
	leftTop.first = _x;
	leftTop.second = _y;
	//setting leftTop for x and y in constructor, and setting edge to _e parameter in constructor.
	//initalising Rectangle members by assigning them to constructor parameters
}
float Square::calculateArea()
{
	area = edge * edge;
	return area;
	//working out area of Square by assigning area with the calculation of edges.
	//returning area.
}
float Square::calculatePerimeter()
{
	perimeter = edge * 4;
	return perimeter;
	//calculating the perimeter with edge using protected member variable "perimeter".
	//returning perimeter.
}
string Square::calculatePoints()
{
	Points.clear();
	//clearing Points vector for when another shape is called or move/scale is called.
	pair<int, int>left_Top(leftTop.first, leftTop.second);
	//assigning left_top with the pair leftTop, with regards to x as first, and y as second.
	pntObj.calculateCoordinates(left_Top);
	Points.push_back(pntObj);
	//assigning left_top into Point class calculateCoordinates, pushing back to store into Points vector object.
	pair<int, int>right_Top(leftTop.first + edge, leftTop.second);
	pntObj.calculateCoordinates(right_Top);
	Points.push_back(pntObj);
	//assigning right_top into Point class calculateCoordinates, pushing back to store into Points vector object.
	pair<int, int>right_Bottom(leftTop.first + edge, leftTop.second + edge);
	pntObj.calculateCoordinates(right_Bottom);
	Points.push_back(pntObj);
	//assigning right_bottom into Point class calculateCoordinates, pushing back to store into Points vector object.
	pair<int, int>left_Bottom(leftTop.first, leftTop.second + edge);
	pntObj.calculateCoordinates(left_Bottom);
	Points.push_back(pntObj);
	//assigning left_bottom into Point class calculateCoordinates, pushing back to store into Points vector object.
	string printPnts;
	//creating a string to return all the Points from printPoints method in points, which returns x and y in the class.
	for (Point p : Points)
	{
		printPnts += p.printPoints();
	}
	return "Points[" + printPnts + "]";
	//Using for expressed range loop to loop in Points and to assign printPts with all points from in vector and being returned
	//from printPoints methods.
}
void Square::move(int newX, int newY)
{
	leftTop.first = newX;
	leftTop.second = newY;
	calculatePoints();
	//assigning leftTop pair with method argument x and y.
	//calling out calculatePoints to re-calculate new points when move called.
}
void Square::scale(float newX, float newY)
{
	edge = edge * newX;
	//scaling edge with x
	calculatePoints();
	//calling calculatePoints to update Points.
}
string Square::toString()
{
	stringstream squareStr;
	squareStr.precision(1);
	//creating a stringstream variable and setting precision to 1 to stop excessive decimal numbers after 1 decimal place.
	squareStr << fixed << "Square[e=" << edge << "] \n" << calculatePoints() << "\n" << "Area=" << calculateArea()
		<< " " << "Perimeter=" << calculatePerimeter();
	//formatting fixed squareStr and assigning multiple functions to the stringstream so it can be converted to 1 string
	//and the one string can be returned.
	string squareInfo = squareStr.str();
	//converting squareStr to string squareInfo.
	return squareInfo;
	//returning squareInfo
}
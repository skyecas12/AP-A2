#include "Point.h"
Point::Point()
{
	x = 0;
	y = 0;
	//initalising points to 0 with default constructor;
}
void Point::calculateCoordinates(pair<int, int>calcuatePoint)
{
	x = calcuatePoint.first;
	y = calcuatePoint.second;
	//assigning x and y to the method arguement pair calculatePoint.
}
string Point::printPoints()
{
	string _x = to_string(x);
	string _y = to_string(y);
	return "(" + _x + "," + _y + ")";
	//converts x and y to string, and then returns it, when called with a shape or move/scale, the printPoints will also be called.
}
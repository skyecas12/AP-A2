#include "Rectangle.h"

Rectangle::Rectangle(int X, int Y, int H, int W)
{
	height = H;
	width = W;
	y = Y;
	x = X;
	leftTop.first = X;
	leftTop.second = Y;
	//setting leftTop for x and y in constructor, and assigniny height and width to H and W..
	//initalising square members by assigning them to constructor parameters
}
float Rectangle::calculateArea()
{
	area = width * height;
	return area;
	//calculating the area of Rectangle by assigning area with the calculation of height and width.
	//returning area.
}
float Rectangle::calculatePerimeter()
{
	perimeter = (width * 2) + (height * 2);
	return perimeter;
	//calculating the perimeter by assigning perimeter with calculation of height and width.
	//returning perimeter
}
string Rectangle::calculatePoints()
{
	Points.clear();
	//clearing Points vector for when another shape is called or move/scale is called.
	pair<int, int>left_Top(leftTop.first, leftTop.second);
	//assigning left_top with the pair leftTop, with regards to x as first, and y as second.
	pntObj.calculateCoordinates(left_Top);
	Points.push_back(pntObj);
	//assigning left_top into Point class calculateCoordinates, pushing back to store into Points vector object.
	pair<int, int>right_Top(leftTop.first + width, leftTop.second);
	pntObj.calculateCoordinates(right_Top);
	Points.push_back(pntObj);
	//assigning right_top into Point class calculateCoordinates, pushing back to store into Points vector object.
	pair<int, int>right_Bottom(leftTop.first + width, leftTop.second + height);
	pntObj.calculateCoordinates(right_Bottom);
	Points.push_back(pntObj);
	//assigning right_bottom into Point class calculateCoordinates, pushing back to store into Points vector object.
	pair<int, int>left_Bottom(leftTop.first, leftTop.second + height);
	pntObj.calculateCoordinates(left_Bottom);
	Points.push_back(pntObj);
	//assigning left_bottom into Point class calculateCoordinates, pushing back to store into Points vector object.
	string printPnts;
	//creating a string to return all the Points from printPoints method in points, which returns x and y in the class.
	for (Point p : Points)
	{
		printPnts += p.printPoints();
	}
	//cout << "[" << printPts << "]";
	return "Points[" + printPnts + "]";
	//Using for expressed range loop to loop in Points and to assign printPts with all points from in vector and being returned
	//from printPoints methods.
}
void Rectangle::move(int x, int y)
{
	leftTop.first = x;
	leftTop.second = y;
	calculatePoints();
	//assigning leftTop pair with method argument x and y.
	//calling out calculatePoints to re-calculate new points when move called.
}
void Rectangle::scale(float x, float y)
{
	width = width * x;
	height = height * y;
	//scaling width and height with x and y.
	calculatePoints();
	//calling calculatePoints to update Points.
}
string Rectangle::toString()
{
	stringstream rectStr;
	rectStr.precision(1);
	//creating a stringstream variable and setting precision to 1 to stop excessive decimal numbers after 1 decimal place.
    rectStr << fixed << "Rectangle[h=" << height <<",w=" << width << "]" << "\n"
		<< calculatePoints() << "\n" << "Area=" << calculateArea() << " Perimeter=" << calculatePerimeter();
	//formatting fixed recteStr and assigning multiple functions to the stringstream so it can be converted to 1 string
	//and the one string can be returned.
	string rectangleInfo = rectStr.str();
	//converting rectangleStr to string rectangleInfo.
	return rectangleInfo;
	//returning rectangleInfo
}





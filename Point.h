#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <vector>
using namespace std;
class Point
{
private:
	int x;
	int y;
	//defining private member variables to be used in point class.
public:
	Point();
	void calculateCoordinates(pair<int, int>);
	string printPoints();
	//defining default constructor to be used in Point class to initalise variables.
	//defining public member variables to be called in other classes.
};


#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include "Point.h"
#include <sstream>
#include <map>

using namespace std;

class Shape
{
    protected:
        //using protected for child classes to use members below.
        vector<Point>Points;
        Point pntObj;
        bool isCircular;
        int x;
        int y;
        float area;
        float perimeter;
        pair<int, int>leftTop;
        //defining protected variables and objects to be used in child classes.
    public:
        Shape();
        virtual float calculateArea()=0;
        virtual float calculatePerimeter()=0;
        virtual string calculatePoints()=0;
        virtual string toString()=0; 
        //defining public pure virtual methods to be overriden by classes inheriting shape and defining default constructor.
};
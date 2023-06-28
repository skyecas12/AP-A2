#pragma once
#include "Movable.h"
#include "Shape.h"
using namespace std;
class Rectangle: public Shape, public Movable
{
    private:
        int height;
        int width;
        //defining private variables to be used in rectangle.
    public:
        Rectangle(int x, int y, int h, int w);
        float calculateArea();
        float calculatePerimeter();
        string calculatePoints();
        void move(int x, int y);
        void scale(float x, float y);
        string toString();
        //defining public members + overriding methods from shape, and movable for circle and defining parameterised constructor.
};


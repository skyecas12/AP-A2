#pragma once
#include "Shape.h"
#include "Movable.h"

class Circle: public Shape, public Movable
{
private:
    int radius;
    //defining private variables to be used in circle.
public:
    Circle(float x, float y, float r);
    float calculateArea();
    float calculatePerimeter();
    string calculatePoints();
    void move(int x, int y);
    void scale(float x, float y);
    string toString();
    //defining public methods + overriding methods from shape and movable, for Circle and defining parameterised constructor.
};


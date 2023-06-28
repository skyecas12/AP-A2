#pragma once
#include "Shape.h"
#include "Movable.h"
class Square: public Shape,  public Movable
{
    private:
        int edge;
        //defining private variables to be used in sqaure.
    public:
        Square(float x, float y, float e);
        float calculateArea();
        float calculatePerimeter();
        string calculatePoints();
        void move(int newX, int newY);
        void scale(float newX, float newY);
        string toString();
        //defining puiblic members + overriding methods from shape and movable for square, and defining parameterised constructor.
};


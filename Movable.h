#pragma once

#include <iostream>
class Movable
{
public:
	virtual void move(int newX, int newY) = 0;
	virtual void scale(float scaleX, float scaleY) = 0;
	//defining pure virtual function move and scale to be overidden in child classes square, circle and rectangle.
};


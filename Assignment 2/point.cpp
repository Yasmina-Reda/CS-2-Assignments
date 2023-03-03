#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;

point::point() //default constructor
{
	x = 0;y = 0;
}

point::point(float x, float y) //argument constructor
{
	this->x = x; this->y = y;
}

void point::setX(float x)
{
	this->x = x;
}

void point::setY(float y)
{
	this->y = y;
}

float point::getX()
{
	return x;
}

float point::getY()
{
	return y;
}

void point::display() //displays the point
{
	cout << '(' << x << "," << y << ')'; 
}

float point::distancebtw(point p) //computes distance
{

	return float(sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)));
}
#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;

point::point()
{
	x = 0;y = 0;
}

point::point(double x, double y)
{
	this->x = x; this->y = y;
}

void point::setX(double x)
{
	this->x = x;
}

void point::setY(double y)
{
	this->y = y;
}

double point::getX()
{
	return x;
}

double point::getY()
{
	return y;
}

void point::display()
{
	cout << '(' << x << "," << y << ')'; 
}

double point::distancebtw(point p)
{

	return double(sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)));
}
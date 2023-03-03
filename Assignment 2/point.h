#ifndef point_h
#define point_h

class point {
private:
	double x, y;
public:
	point();
	point(double, double); 
	~point() {};
	void setX(double);
	void setY(double);
	double getX();
	double getY();
	void display();
	double distancebtw(point);
};
#endif


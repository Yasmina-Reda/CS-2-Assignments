#ifndef point_h
#define point_h

class point {
private:
	float x, y;
public:
	point();
	point(float, float); 
	~point() {};
	void setX(float);
	void setY(float);
	float getX();
	float getY();
	void display();
	float distancebtw(point);
};
#endif


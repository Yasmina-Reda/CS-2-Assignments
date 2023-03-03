#include "point.h"
#include "point.cpp" //for some reason it gives me a linking error if i do not include the .cpp file
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Don't understand the difference between  "user application function" and "user application progarm" in the question
//I added some extra features such as displaying the centers and displaying the distance between each point and center to make the program more friendly and understandable


//Prototypes

void positive(int&);

void generateCluster(point*&, int, float, float);

void generatePoints(point*&, int);

point Center(point*, int);

void whichCluster(point*, int, point*, int, point);

void deleteArray(point*&);



int main() //main to run program
{
	point *A, *B, *p; int nA, nB, m;

	cout << "Please input size of cluster A: "; cin >> nA; positive(nA); generateCluster(A, nA, 70.0, 70.0); //instead of presetting it I gave the user the option to decide how many points
	cout << "Please input size of cluster B: "; cin >> nB; positive(nB); generateCluster(B, nB, 20.0, 20.0);
	cout << "Please input number of random points to be generated: "; cin >> m; positive(m); generatePoints(p,m);

	cout << "\nCluster A center: "; Center(A, nA).display(); cout << "  Cluster B center: ";Center(B, nB).display(); cout << "\n\n"; //This is just to display the centers 
	for (int i = 0;i < m;i++) 
	{
		cout<<"Point "<<i+1<<":"; whichCluster(A, nA, B, nB, *(p + i));
		cout << "\n\n";
	}

	deleteArray(A);
	deleteArray(B);
	deleteArray(p);

	return 0;
}

void positive(int& n) //rejects non-positive number of points
{
	while (n <= 0)
	{
		cout << "Non-positive numbers not accepted. Please Enter a positive number: "; cin >> n;
	}
}

void generateCluster(point*& cluster, int n, float xMin, float yMin) //generates a cluster of n points
{
	cluster = new point[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n;i++)
	{
		(cluster + i)->setX(rand() % 21 + xMin); //Note to self: how to use (xRange != 0 ? xRange : 20) here?
		(cluster + i)->setY(rand() % 21 + yMin); //e.g. current range is 70<=x<=90 for how to limit range to 70.0<y<90.0
	}
}

point Center(point* C, int n )//finds center and returns it as a point
{
	point center; float sumX = 0, sumY = 0;

	for (int i = 0;i < n;i++)
	{
		sumX += (C + i)->getX();
		sumY += (C + i)->getY();
	}

	center.setX(sumX / n); center.setY(sumY / n);

	return center;
}

void whichCluster(point* A, int nA, point* B, int nB, point p) //outputs which cluster p belongs to
{
	p.display(); cout << endl; 
	cout << "distance to A: " << p.distancebtw(Center(A, nA)); cout << " distance to B: " << p.distancebtw(Center(B, nB))<<endl;
	if (p.distancebtw(Center(A, nA)) > p.distancebtw(Center(B, nB))) cout << "Point belongs to cluster B\n";
	else if (p.distancebtw(Center(A, nA)) < p.distancebtw(Center(B, nB))) cout << "Point belongs to cluster A\n";
	else cout << "Point is equidisant from clusters A and B\n";
}

void generatePoints(point*& p, int m) //generates m points
{
	p = new point[m]; //note to self: is it alright to do it in the form of an array or do I use which cluster on one variable point that I change in the loop?
	srand((unsigned int)time(NULL));
	for (int i = 0;i < m;i++)
	{
		(p + i)->setX(float(rand() % 96 + 5));
		(p + i)->setY(float(rand() % 96 + 5));
	}
}

void deleteArray(point*& array)
{
	delete[]array;
}


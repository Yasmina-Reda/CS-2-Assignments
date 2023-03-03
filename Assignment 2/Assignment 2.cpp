#include "point.h"
#include "point.cpp" //for some reason it gives me a linking error if i do not include the .cpp file
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//upoad to github
//figure out errors and loopholes
//comment
//test

//can I do a class for clusters?
//what does "user application function" and "user application progarm" mean?
//is it alright if I use double instead of float

void positive(int&);

void generateCluster(point*&, int, double, double);

void generatePoints(point*&, int);

point Center(point*, int);

void whichCluster(point*, int, point*, int, point);

void deleteArray(point*&);



int main()
{
	point *A, *B, *p; int nA, nB, m;

	cout << "Please input size of cluster A: "; cin >> nA; positive(nA); generateCluster(A, nA, 70.0, 70.0);
	cout << "Please input size of cluster B: "; cin >> nB; positive(nB); generateCluster(B, nB, 20.0, 20.0);
	cout << "Please input number of random points to be generated: "; cin >> m; positive(m); generatePoints(p,m);

	cout << "\nCluster A center: "; Center(A, nA).display(); cout << "  Cluster B center: ";Center(B, nB).display(); cout << "\n\n";
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

void positive(int& n)
{
	while (n <= 0)
	{
		cout << "Non-positive numbers not accepted. Please Enter a positive number: "; cin >> n;
	}
}

void generateCluster(point*& cluster, int n, double xMin, double yMin)
{
	cluster = new point[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n;i++)
	{
		(cluster + i)->setX(rand() % 21 + xMin); //how do I generate rand double? //how to use (xRange != 0 ? xRange : 20) here
		(cluster + i)->setY(rand() % 21 + yMin); //e.g. current range is 70<=x<=90 for how to limit range to 70.0<y<90.0
	}
}

point Center(point* C, int n)
{
	point center; double sumX = 0, sumY = 0;

	for (int i = 0;i < n;i++)
	{
		sumX += (C + i)->getX();
		sumY += (C + i)->getY();
	}

	center.setX(sumX / n); center.setY(sumY / n);

	return center;
}

void whichCluster(point* A, int nA, point* B, int nB, point p) //is cout what is needed or?
{
	p.display(); cout << endl;//remove before submitting
	cout << "distance to A: " << p.distancebtw(Center(A, nA)); cout << " distance to B: " << p.distancebtw(Center(B, nB))<<endl;
	if (p.distancebtw(Center(A, nA)) > p.distancebtw(Center(B, nB))) cout << "Point belongs to cluster B\n";
	else if (p.distancebtw(Center(A, nA)) < p.distancebtw(Center(B, nB))) cout << "Point belongs to cluster A\n";
	else cout << "Point is equidisant from clusters A and B\n";
}

void generatePoints(point*& p, int m)
{
	p = new point[m]; //is it alright to do it in the form of an array or do I use which cluster on one variable point that I change in the loop
	srand((unsigned int)time(NULL));
	for (int i = 0;i < m;i++)
	{
		(p + i)->setX(double(rand() % 96 + 5));
		(p + i)->setY(double(rand() % 96 + 5));
	}
}

void deleteArray(point*& array)
{
	delete[]array;
}


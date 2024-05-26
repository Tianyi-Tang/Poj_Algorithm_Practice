#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

#define Pi 3.141592653589793

struct Position{
	double xValue;
	double yValue;
};

void findDistance(Position& a, Position& b, double& distance){
	double xDifferent = a.xValue - b.xValue;
	double yDifferent = a.yValue - b.yValue;

	distance = sqrt(pow(xDifferent,2) + pow(yDifferent,2));
}

int main()
{
	double x,y,lineA,lineB,lineC,p,r,cir;
	Position a,b,c;

	while(cin >> x >> y){
		a.xValue = x;
		a.yValue = y;
		cin >> x >> y;
		b.xValue = x;
		b.yValue = y;
		cin >> x >> y;
		c.xValue = x;
		c.yValue = y;

		findDistance(a,b,lineA);
		findDistance(a,c,lineB);
		findDistance(b,c,lineC);

		p = (lineA + lineB + lineC) * 0.5;
		r = lineA * lineB * lineC * 0.25 / sqrt(p*(p-lineA)*(p-lineB)*(p-lineC));
		cir = 2 * r * Pi;

		printf("%.2lf\n",cir);
	}


	

	return 0;
}
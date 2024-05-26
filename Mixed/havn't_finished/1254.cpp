#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;

#define Pi 3.141592653589793238462643383279502884197

struct LineEquation{
	bool yvalue;
	double slope;
	double constance;
};

void findEquation(LineEquation& a,int x,int y, int degree){
	bool isY_axs;
	if(degree <= 90){
		degree = 90 - degree;
		isY_axs = true;
	}
	else if(degree <= 180){
		degree = 270 - degree;
		isY_axs = false;
	}
	else if(degree <= 270){
		degree = 270 - degree;
		isY_axs = true;
	}
	else{
		degree = 450 - degree;
		isY_axs = false;
	}

	if(degree != 90)
		a.slope = tan(degree * Pi / 180.0);
	else
		a.slope = 0;

	if(a.slope == 0)
		a.yvalue = isY_axs;
	a.constance = y - x * a.slope;
}

void slopeZero(LineEquation & a, LineEquation& zero,double& x,double& y){
	if(zero.yvalue){
		y = zero.constance;
		x = (y - a.constance) / a.slope;
	}
	else{
		x = zero.constance;
		y = x * a.slope + a.constance;
	}
}

void findIntersectPoint(LineEquation & a, LineEquation& b){
	double x,y;

	if(a.slope == 0 && b.slope ==0){
		if(a.yvalue){
			y = a.constance;
			x = b.constance;
		}
		else{
			y = b.constance;
			x = a.constance;
		}
	}
	else if(a.slope == 0 || b.slope ==0){
		if(a.slope ==0)
			slopeZero(b,a,x,y);
		else
			slopeZero(a,b,x,y);
	}
	else{
		x = (b.constance - a.constance)/(a.slope -b.slope);
		y = a.slope * (b.constance - a.constance)/(a.slope -b.slope) + a.constance;
	}
	printf("%.4f %.4f\n",x,y);
}

// void findLine(LineEquation& a,double x1,double y1,int x2,int y2){
// 	a.slope = (y1 - y2)/(x1 - x2);
// 	a.constance = y2 - a.slope * x2;
// }

int main()
{
	// LineEquation a, b;
	// int n,x,y,degree;
	// cin >> n;
	// for(int i =0;i < n;i++){
	// 	cin >> x >> y >> degree;
	// 	findEquation(a,x,y,degree);
	// 	cin >> x >> y >> degree;
	// 	findEquation(b,x,y,degree);
	// 	findIntersectPoint(a,b);
	// }

	cout << tan(90 * Pi /180.0) << endl;

	return 0;
}

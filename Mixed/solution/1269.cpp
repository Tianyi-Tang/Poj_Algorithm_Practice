#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Equation{
	bool yValue;
	double m;
	double c;

};

void calculateEquation(Equation& a,double x1,double y1,double x2,double y2){
	if(x1 - x2 == 0){
		a.m = 0;
		a.yValue = false;
		a.c = x1;
	}
	else if(y1 - y2 ==0){
		a.m = 0;
		a.yValue = true;
		a.c = y1;
	}
	else{
		a.m = (double) (y1-y2) / (x1-x2);
		a.c = y1 - x1 * a.m;
		 if(abs(a.c) < 0.001)
		 	a.c = 0;
		a.yValue = false;
	}

}

void linePoint(Equation& line, Equation& a){
	double x,y;
	if(line.yValue){
		y = line.c;
		x = (y - a.c) / a.m;
	}
	else{
		x = line.c;
		y = line.c * a.m + a.c;
	}

	printf("%.2f %.2f \n",x,y);
}

int main()
{
	int n;
	double x1,y1,x2,y2,xPoint, yPoint;
	Equation a,b;

	cin >> n;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	for(int i =0;i < n;i++){
		scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		calculateEquation(a,x1,y1,x2,y2);
		scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		calculateEquation(b,x1,y1,x2,y2);

		if(a.m == b.m && a.yValue == b.yValue){
			if(a.c == b.c)
				cout << "LINE" << endl;
			else
				cout << "NONE" << endl;
		}
		else{
			cout << "POINT ";

			if(a.m == 0 && b.m ==0){
				if(a.yValue)
					printf("%.2f %.2f\n",b.c,a.c);
				else
					printf("%.2f %.2f\n",a.c,b.c);
			}
			else if(a.m ==0)
				linePoint(a,b);
			else if(b.m == 0)
				linePoint(b,a);
			else{
				xPoint = (a.c - b.c) / (b.m - a.m);
				yPoint = xPoint * a.m + a.c;
				printf("%.2f %.2f\n",xPoint, yPoint);
			}

		}

	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}
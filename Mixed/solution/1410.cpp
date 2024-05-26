#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct Line{
	bool yValue;
	double slope;
	double constance;
};

int lineX1,lineY1,lineX2,lineY2,maxX,maxY,minX,minY,resultX,resultY;


void findLine(Line & a,int x1,int y1,int x2,int y2){
	if(x1 - x2 ==0){
		a.yValue = false;
		a.slope = 0;
		a.constance = x1;
	}
	else if(y1-y2 ==0){
		a.yValue = true;
		a.slope = 0;
		a.constance = y1;
	}
	else{
		a.slope = ((double) y2 - y1) / (x2-x1);
		a.constance = y1 - a.slope * x1;
		if(abs(a.constance) < 0.000001)
			a.constance = 0;
	}

}

bool inRectangle(int value,int biggerValue, int smallerValue){
	if(value >= smallerValue && value <= biggerValue)
		return true;
	else
		return false;
}

bool withinRange(double value, bool yValue,int rectangleValue){
	double lineMax, lineMin;
	if(yValue){
		lineMax = lineY1;
		lineMin = lineY2;
		if(lineMax < lineMin)
			swap(lineMax,lineMin);

		if( lineMax >= rectangleValue && lineMin <= rectangleValue &&  value <= maxX && value >= minX)
			return true;
		else
			return false;
	}
	else{
		lineMax = lineX1;
		lineMin = lineX2;
		if(lineMax < lineMin)
			swap(lineMax,lineMin);

		if(lineMax >= rectangleValue && lineMin <= rectangleValue && value <= maxY && value >= minY)
			return true;
		else
			return false;
	}
	
}

bool isIntersct(Line& a, Line& b){
	if(a.slope == 0){
		if(a.yValue != b.yValue){
				return withinRange(a.constance,b.yValue,b.constance);
		}
		else if(a.constance == b.constance){
			if(a.yValue){
				if((lineX1 <= maxX && lineX1 >= minX) || (lineX2 <= maxX && lineX2 >= minX))
					return true;
				else
					return false;
			}
			else{
				if((lineY1 <= maxY && lineY1 >= minY) || (lineY2 <= maxY && lineY2 >= minY))
					return true;
				else
					return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		double value;
		if(b.yValue)
			value = (b.constance - a.constance) /a.slope;
		else
			value = b.constance * a.slope + a.constance;
		return withinRange(value,b.yValue,b.constance);
	}
}






int main(int argc, char const *argv[])
{
	int n;
	Line a,b;
	cin >> n;

	for(int i =0;i < n;i++){
		cin >> lineX1 >>lineY1 >>lineX2 >>lineY2;


		findLine(a,lineX1,lineY1,lineX2,lineY2);

		cin >> maxX >> maxY >> minX >> minY;
		if(maxX < minX)
			swap(maxX,minX);
		if(maxY < minY)
			swap(maxY,minY);

		if((inRectangle(lineX1,maxX,minX) && inRectangle(lineY1,maxY,minY)) || (inRectangle(lineX2,maxX,minX) && inRectangle(lineY2,maxY,minY))){
			cout << "T" << endl;
			continue;
		}


		findLine(b,maxX,maxY,maxX,minY);
		if(isIntersct(a,b)){
			cout << "T" << endl;
			continue;
		}
		findLine(b,minX,maxY,minX,minY);
		if(isIntersct(a,b)){
			cout << "T" << endl;
			continue;
		}
		findLine(b,minX,maxY,maxX,maxY);
		if(isIntersct(a,b)){
			cout << "T" << endl;
			continue;
		}
		findLine(b,minX,minY,maxX,minY);
		if(isIntersct(a,b)){
			cout << "T" << endl;
			continue;
		}
		cout << "F" << endl;

	}

	return 0;
}
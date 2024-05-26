#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define N 10000

int soldierNum;
int xPosition[N], yPosition[N];
int step;

 int main()
{
	int xValue,yValue;
	while(cin >> soldierNum){

		step = 0;
		for(int i =0;i < soldierNum;i++){
			cin >> xValue >> yValue;
			xPosition[i] = xValue;
			yPosition[i] = yValue;
		}
		sort(xPosition, xPosition+ soldierNum);
		sort(yPosition, yPosition + soldierNum);

		for(int i =0;i < soldierNum;i++)
			xPosition[i] -= i;
		sort(xPosition, xPosition + soldierNum);

		xValue = xPosition[soldierNum /2];
		yValue = yPosition[soldierNum/2];

		for(int i =0;i < soldierNum;i++)
			step += abs(xPosition[i] - xValue) + abs(yPosition[i] - yValue);

		cout << step << endl;
	}
	return 0;
}
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;

#define Pi acos(-1.0)
#define maxNailNum 100

int nailNum;
double nailPos[maxNailNum][2];


int main()
{
	double totalDistance,radius,xValue,yValue;

	while(scanf("%d %lf",&nailNum,&radius) != EOF){
		for(int i =0;i < nailNum;i++){
			scanf("%lf %lf",&xValue,&yValue);
			nailPos[i][0] = xValue;
			nailPos[i][1] = yValue;
		}

		totalDistance = 0;
		for(int i =0;i < nailNum-1;i++){
			totalDistance += sqrt(pow(nailPos[i][0]- nailPos[i+1][0],2)+pow(nailPos[i][1]- nailPos[i+1][1],2));
		}
		totalDistance += sqrt(pow(nailPos[0][0]- nailPos[nailNum-1][0],2)+pow(nailPos[0][1]- nailPos[nailNum-1][1],2));
		totalDistance += 2 * radius * Pi;

		printf("%.2lf \n",totalDistance);
	}

	return 0;
}
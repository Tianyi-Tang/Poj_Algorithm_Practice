#include <iostream>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <cstdio>
using namespace std;

#define Pi acos(-1.0)


int main()
{
	double R,r;
	int cycleNum,n;

	scanf("%d",&n);
	for(int i =0;i < n;i++){
		scanf("%lf %d",&R,&cycleNum);
		r = (R * sin(Pi/cycleNum))/(1+sin(Pi/cycleNum));
		printf("Scenario #%d:\n",i+1);
		printf("%.3lf\n",r);
		printf("\n");
	}


	return 0;
}
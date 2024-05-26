#include <cstdio>
#include <iostream>
#include <cstring>
#include <math.h>
#include <cstdlib>
using namespace std;


int main()
{
	float ka,c,x,m,n;
	while(scanf("%lf%lf%lf%lf",&ka,&c,&m,&n)){
		if(ka == 0 && c ==0 && m ==0 && n ==0)
			break;
		x = (-ka + sqrt(ka * ka + 4 * m * n * c * ka))/(2 * n);
		printf("%.3f\n", -log10(x));
	}
	return 0;
}
#include <stdio.h>
#include <math.h>
int main()
{
	float vs,r,c,w,vr;
	int n;
	scanf("%f %f %f %d",&vs,&r,&c,&n);
	for(int i=0 ;i< n;i++)
	{
		scanf("%f",&w);
		vr=c*r*w*vs/sqrt(1+c*r*w*c*r*w);
		printf("%.3lf\n",vr);
	}
	return 0;
}


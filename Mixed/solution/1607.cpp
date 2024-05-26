#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;


int main()
{
	int num,denominator;
	long double result;
	
	printf("%s\n", "Cards  Overhang");
	while(scanf("%d",&num) != EOF){
		result = 0;
		denominator = 2;

		for(int i =0;i < num;i++){
			result += 1.0 / denominator;
			denominator += 2;
		}
		printf("%5d     %.3Lf\n",num,result);
	}
	return 0;
}

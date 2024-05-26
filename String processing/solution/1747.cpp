#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

void findEquation(int i){
	if(i == 1)
		printf("%s","(A0|B0)|(A0|B0)");
	else{
		printf("(A%d|B%d)|((",i-1,i-1);
		findEquation(i-1);
		printf(")|((A%d|A%d)|(B%d|B%d)))",i-1,i-1,i-1,i-1);
	}
}

int main()
{
	int n;

	while(scanf("%d",&n)!=EOF){
		printf("(");
		findEquation(n);
		printf(")\n");
	}
	
	return 0;
}
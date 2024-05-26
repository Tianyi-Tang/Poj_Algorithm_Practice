#include<stdio.h>
#include<cstdlib>
using namespace std;

#define maxReferNum 1000

int apperRef[maxReferNum] = {0},referOrder[maxReferNum] = {0},correctOrder;
char allRef[maxReferNum][4][100], input[100];

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%s",input) != EOF){
		printf("%s\n",input);
	}
	return 0;
}


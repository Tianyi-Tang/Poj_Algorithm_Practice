#include<stdio.h>
#include<math.h>
#include<cstring>
using namespace std;

#define maxNum 1000

char mapX[maxNum][maxNum];

void AddAllX(int n,int xPos,int yPos){
	if(n == 1){
		mapX[xPos][yPos] = 'X';
		return;
	}
	int distance = pow(3.0,n-2);

	AddAllX(n-1,xPos,yPos);
	AddAllX(n-1,xPos,2*distance+yPos);
	AddAllX(n-1,xPos+distance,yPos+distance);
	AddAllX(n-1,xPos+2*distance,yPos);
	AddAllX(n-1,xPos+2*distance,yPos+2*distance);
}

int main()
{
	int n,lastPos;
	while(scanf("%d",&n)){
		if(n == -1)
			break;

		memset(mapX,' ',sizeof(mapX));
		AddAllX(n,1,1);

		lastPos = pow(3.0,n-1);
		for(int i =1;i <= lastPos;i++)
			mapX[i][lastPos+1] = '\0';
		
		for(int i =1;i <= lastPos;i++)
			printf("%s\n",mapX[i]+1);
		printf("-\n");
	}


	return 0;

}
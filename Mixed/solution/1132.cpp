#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define mapLength 32

char map[mapLength][mapLength];

void inital(){
	for(int i =0;i < mapLength;i++){
		for(int j =0;j < mapLength;j++)
			map[i][j] = '.';
	}
}


int main()
{
	int n,currentX,currentY,index;
	char moving[1000];
	scanf("%d",&n);
	for(int i =0;i < n;i++){
		inital();
		scanf("%d %d %s",&currentX,&currentY,moving);
		index = 0;
		while(moving[index] != '.'){
			if(moving[index] == 'E'){
				currentX ++;
				map[currentY-1][currentX-1] = 'X';
			}
			else if(moving[index] == 'W'){
				currentX --;
				map[currentY][currentX] = 'X';
			}
			else if(moving[index] == 'N'){
				currentY ++;
				map[currentY-1][currentX] = 'X';
			}
			else{
				currentY --;
				map[currentY][currentX-1] = 'X';
			}
			index ++;
		}

		cout << "Bitmap #" << i +1 << endl;
		for(int i = mapLength -1;i >=0;i--){
			for(int j =0;j < mapLength;j++)
				cout << map[i][j];
			cout << endl;
		}
		cout << endl;

	}

	return 0;
}
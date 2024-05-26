#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxLength 100

int rowNum,columnNum,currentIndex,writeIndex;
char table[2][maxLength][maxLength];


bool win(char a, char b){
	if(a == 'R' && b == 'S')
		return true;
	else if(a == 'S' && b == 'P')
		return true;
	else if(a == 'P' && b == 'R')
		return true;
	else
		return false;
}

void findPossibleOccupy(int row,int column){
	char a = table[currentIndex][row][column];
	if(row != 0){
		if(win(a,table[currentIndex][row-1][column]))
			table[writeIndex][row-1][column] = a;
	}
	if(row < rowNum-1){
		if(win(a,table[currentIndex][row+1][column]))
			table[writeIndex][row+1][column] = a;
	}
	if(column != 0){
		if(win(a,table[currentIndex][row][column-1]))
			table[writeIndex][row][column-1] = a;
	}
	if(column < columnNum-1){
		if(win(a,table[currentIndex][row][column+1]))
			table[writeIndex][row][column+1] = a;
	}
}

void action(){
	for(int i = 0;i < rowNum;i++){
		for(int j = 0; j < columnNum;j++){
			findPossibleOccupy(i,j);
		}
	}
}


int main()
{
	int n,time;
	char civil;

	cin >> time;
	while(time){
		scanf("%d %d %d",&rowNum,&columnNum,&n);
		currentIndex = 0;
		writeIndex = 1;
		for(int i =0;i < rowNum;i++){
			scanf("%s",table[currentIndex][i]);
		}


		while(n){
			for(int i =0;i < rowNum;i++)
				for(int j =0;j < columnNum;j++)
					table[writeIndex][i][j] = table[currentIndex][i][j];
			action();
			swap(currentIndex,writeIndex);
			n --;
		}

		for(int i =0;i < rowNum;i++){
				for(int j = 0;j < columnNum;j++)
				cout << table[currentIndex][i][j];
			cout << endl;
		}
		cout << endl;

		time --;
	}

	

	return 0;
}




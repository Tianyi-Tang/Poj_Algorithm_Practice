#include<cstring>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<cstdio>
using namespace std;

#define maxMapLength 15

int rowNum,columnNum,numOrder;
char puzzle[maxMapLength][maxMapLength];
int order[maxMapLength*maxMapLength][2];
bool visited[maxMapLength][maxMapLength];

bool hasOrder(char c,int rowCurrrent,int columnCurrrent){
	if(c != '*'){
		if(rowCurrrent == 0)
			return true;
		else if(puzzle[rowCurrrent-1][columnCurrrent] == '*')
			return true;
		else if(columnCurrrent == 0)
			return true;
		else if(puzzle[rowCurrrent][columnCurrrent-1] == '*')
			return true;
		else
			return false;
	}

	return false;
}

int main()
{
	string line;
	int counter,puzzleNum,rowCurrrent,columnCurrrent;
	char c;
	puzzleNum = 1;
	while(cin >> rowNum){
		if(rowNum == 0)
			break;

		if(puzzleNum != 1)
			cout << endl;

		counter = 0;
		cin >> columnNum;
		getchar();
		for(int i =0;i < rowNum;i++){
			getline(cin,line);
			for(int j = 0;j < columnNum;j++){
				puzzle[i][j] = line[j];
				visited[i][j] = false;
				if(hasOrder(line[j],i,j)){
					order[counter][0] = i;
					order[counter++][1] = j; 
				}
			}
		}

		
		printf("puzzle #%d:\n",puzzleNum);
		printf("Across\n");
		for(int i =0;i < counter;i++){
			line = "";
			rowCurrrent = order[i][0];
			columnCurrrent = order[i][1];
			if(visited[rowCurrrent][columnCurrrent] == true)
				continue;
			c = ' ';
			while( columnCurrrent < columnNum){
				c = puzzle[rowCurrrent][columnCurrrent];
				if(c == '*')
					break;
				line += c;
				visited[rowCurrrent][columnCurrrent] = true;
				columnCurrrent ++;
			}
			printf("%3d.",i+1);
			cout << line << endl;
		}

		for(int i =0;i < rowNum;i++){
			for(int j =0;j < columnNum;j++)
				visited[i][j] = false;
		}

		printf("Down\n");
		for(int i =0;i < counter;i++){
			line = "";
			rowCurrrent = order[i][0];
			columnCurrrent = order[i][1];
			if(visited[rowCurrrent][columnCurrrent] == true)
				continue;
			c = ' ';
			while(rowCurrrent < rowNum){
				c = puzzle[rowCurrrent][columnCurrrent];
				if(c == '*')
					break;
				line += c;
				visited[rowCurrrent][columnCurrrent] = true;
				rowCurrrent ++;
			}
			printf("%3d.",i+1);
			cout << line << endl;
		}
		puzzleNum ++;

		
	}

	return 0;
}
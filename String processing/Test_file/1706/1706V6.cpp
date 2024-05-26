#include<stdio.h>
#include<cstdlib>
#include <cstring>
using namespace std;

#define maxReferNum 1000

int apperRef[maxReferNum] ={0}, referOrder[maxReferNum] = {0};
char allRefer[maxReferNum][4][100],input[100];
int correctOrder,referNum;
bool appearNum;

void excuteInput(char s[]){
	appearNum = false;
	for(int i =0;i < strlen(s);i++){
		if(appearNum && s[i] == ']'){
			appearNum = false;
			if(!apperRef[referNum]){
				printf("[%d]",correctOrder);
				apperRef[referNum] =correctOrder;
				referOrder[correctOrder++] = referNum;
			}
			else
				printf("[%d]",apperRef[referNum]);
		}
		else if(appearNum){
			referNum = referNum * 10 + s[i] - '0';
		}
		else if(s[i] == '['){
			appearNum = true;
			referNum = 0;
		}
		else
			putchar(s[i]);
	}
	putchar('\n');
}

bool isBlank(char s[]){
	for(int i =0;i < strlen(s);i++){
		if(input[i] != ' ')
			return true;
	}
	return false;
}

void getAllinput(){
	int n;
	while(gets(input)!= NULL){
		if(isBlank(input))
			continue;
		else if(input[0] == '['){
			referNum = input[1] - '0';
			n = 2;
			while(input[n] != ']'){
				referNum = referNum * 10 + input[n] - '0';
				n++;
			}
			n = 0;
			while(true){
				memcpy(allRefer[referNum][n],input,sizeof(input));
				n++;
				if(gets(input) == NULL || isBlank(input))
					break;
			}
		}
		else{
			while(true){
				excuteInput(input);
				if(gets(input) == NULL || isBlank(input))
					break;
			}
			putchar('\n');
		}
	}
}

// void printRefer(){
// 	for(int i =1;i <correctOrder;i++){
// 		appearNum = false;
// 		printf("[%d]",i);
// 		for(int j = 0;j < strlen(allRefer[referOrder[i]][0]);j++){
// 			if(appearNum)
// 				putchar(allRefer[referOrder[i]][0][j]);
// 			else if(allRefer[referOrder[i]][0][j] == ']')
// 				appearNum = true;
// 		}
// 		putchar('\n');
// 		referNum = 1;

// 		while(strlen(allRefer[referOrder[i]][referNum]) != 0){
// 			printf("%s\n",allRefer[referOrder[i]][referNum]);
// 			referNum++;
// 		}
// 		putchar('\n');

// 	}
// }

int main()
{
	freopen("input.txt","r",stdin);
	correctOrder = 1;
	getAllinput();
	//printRefer();
	return 0;
}
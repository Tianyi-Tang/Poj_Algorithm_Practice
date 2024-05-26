#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define D 10
#define inputLength 100

char input[inputLength];
int buttonSize;
char button[D];

int maxLength;
char finalPosition[D];

void intial(){
	maxLength = 0;
	for(int i =0;i < D;i++)
		finalPosition[i] = '0';
}

void convert(){
	buttonSize = 0;
	int length = strlen(input);
	for(int i = length - 1;i >=0;i--){
		if(input[i] >= '0' && input[i] <= '9')
			button[buttonSize++] = input[i];
	}
}


void addingButton(){
	int index = 0;
	for(int i = 0;i < buttonSize;i++){
		finalPosition[index] = (finalPosition[index] - '0' + button[i] - '0') % 10 + '0';
		index ++;
	}

	if(buttonSize > maxLength)
		maxLength = buttonSize;
}

void printResult(){
	for(int i = maxLength -1;i >=0;i--)
		printf("%c",finalPosition[i]);
	printf("\n");
}


int main()
{
	intial();
	while(scanf("%s",input) != EOF){
		convert();
		addingButton();
	}
	printResult();
	
	return 0;
}


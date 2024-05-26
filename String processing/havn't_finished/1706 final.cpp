#include<cstring>
#include<cstdlib>
#include<stdio.h>
using namespace std;

#define maxReferNum 1000

int appearRefer[maxReferNum] ={0}, orderRef[maxReferNum] = {0};
char allRefer[maxReferNum][4][100],input[100];
int correctRef;

bool isBlank(char s[]){
	for(int i =0;i < strlen(s);i++){
		if(s[i] != ' ')
			return false;
	}
	return true;
}

void executeInput(){
	printf("This is input: %s\n",input);
}

void getAllInput(){
	while(gets(input) != NULL){
		if(isBlank(input))
			continue;
		else if(input[i] == '['){
			while(true){
				executeInput();
				if(gets(input) == NULL || isBlank(input))
			}
		}
		else{
			while(true){
				executeInput();
				if(gets(input) == NULL || isBlank(input))
			}
		}
	}
}
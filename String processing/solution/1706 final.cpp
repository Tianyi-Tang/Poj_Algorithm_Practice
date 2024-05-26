#include<cstring>
#include<cstdlib>
#include<stdio.h>
using namespace std;

#define maxReferNum 1000

int appearRefer[maxReferNum] ={0}, orderRef[maxReferNum] = {0};
char allRefer[maxReferNum][4][100],input[100];
int correctRef,referNum;

bool isBlank(char s[]){
	for(int i =0;i < strlen(s);i++){
		if(s[i] != ' ')
			return false;
	}
	return true;
}

void executeInput(){
	bool appearNum = false;
	for(int i =0;i < strlen(input);i++){
		if(appearNum && input[i] == ']'){
			appearNum = false;
			if(!appearRefer[referNum]){
				printf("[%d]",correctRef);
				appearRefer[referNum] = correctRef;
				orderRef[correctRef++] = referNum;
			}
			else
				printf("[%d]",appearRefer[referNum]);
		}
		else if(appearNum){
			referNum = referNum * 10 + input[i] - '0';
		}
		else if(input[i] == '['){
			appearNum = true;
			referNum = 0;
		}
		else
			putchar(input[i]);
	}
	putchar('\n');
}

void getAllInput(){
	int n;
	while(gets(input) != NULL){
		if(isBlank(input))
			continue;
		else if(input[0] == '['){
			referNum = input[1] - '0';
			n = 2;
			while(input[n] != ']'){
				referNum = referNum * 10 + input[n++] - '0';
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
				executeInput();
				if(gets(input) == NULL || isBlank(input))
					break;
			}
			putchar('\n');
		}
	}
}

void pringAllRefer(){
	bool afterNum;
	for(int i =1;i < correctRef;i++){
		printf("[%d]",i);
		afterNum = false;

		for(int j =0;j < strlen(allRefer[orderRef[i]][0]);j++){
			if(!afterNum && allRefer[orderRef[i]][0][j] == ']')
				afterNum = true;
			else if(afterNum)
				putchar(allRefer[orderRef[i]][0][j]);
		}
		putchar('\n');
		for(int j=1;j < 4 && !isBlank(allRefer[orderRef[i]][j]);j++){
			printf("%s\n",allRefer[orderRef[i]][j]);
		}
		putchar('\n');

	}
}

int main()
{
	correctRef = 1;
	getAllInput();
	pringAllRefer();
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long tenBaseNum;
char result[8];


int covenrtChar(char a){
	if(a <= '9')
		return a - '0';
	else
		return a - 'A' + 10;
}

char covenrtInt(int num){
	if(num <= 9)
		return num + '0';
	else
		return num - 10 + 'A';
}

void findTenBaseNum(char num[8],int base){
	tenBaseNum = 0;
	long long power = 1;

	for(int i = strlen(num) -1;i >=0;i--){
		if(num[i] == ' ')
			break;
		if(num[i] != '0'){
			tenBaseNum += covenrtChar(num[i]) * power;
		}
		power *= base;
	}
}

void assignedError(){
	result[0] = 'E';
	result[1] = 'R';
	result[2] = 'R';
	result[3] = 'O';
	result[4] = 'R';
	result[5] = '\0';
}

void translateTen(int base){
	int counter = 1;
	long long power = 1;

	while(power * (base-1) < tenBaseNum && counter < 8){
		power *= base;
		counter ++;
	}

	if(power > tenBaseNum){
		power = power / base;
		counter --;
	}

	if(counter == 8)
		assignedError();
	else{
		int index = 0;
		for(int i = counter;i >=1;i--){
			result[index++] = covenrtInt(tenBaseNum / power);
			tenBaseNum = tenBaseNum % power;
			power = power / base;
		}
		result[index] = '\0';
	}
}

int main()
{
	char number[8];
	int orgBase,covBase;
	while(scanf("%s %d %d",number,&orgBase,&covBase) != EOF){
		findTenBaseNum(number,orgBase);
		translateTen(covBase);
		printf("%7s\n",result);
	}
	return 0;

	// char num[8] = "1111000";
	// findTenBaseNum(num,2);
	// translateTen(16);
	// printf("%s\n", result);

}
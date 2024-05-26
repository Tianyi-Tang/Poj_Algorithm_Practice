#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int sum,maxValue;
int num[10000];
char input[32000];


void inital(){
	sum = 0;
	maxValue = 2;
}


void addChar(char a){
	int value = 0;
	if(a >= '0' && a <= '9')
		value = a - '0';
	else if(a <='Z' && a >= 'A')
		value = a - 'A' + 10;
	else if(a <= 'z' && a >= 'a')
		value = a - 'a' + 36;

	if(maxValue < value)
		maxValue = value;

	sum += value;
	
}

int main()
{
	int storing,index;
	while(scanf("%s", input) != EOF){
		index = 0;
		inital();
		while(input[index] != '\0'){
			addChar(input[index]);
			index ++;
		}

		int i;
		for(i = maxValue+1;i <63;i++){
			if(sum %(i-1) == 0)
				break;
		}

		if(i < 63)
			cout << i << endl;
		else
			cout << "such number is impossible!" << endl;

	}

	
	return 0;
}


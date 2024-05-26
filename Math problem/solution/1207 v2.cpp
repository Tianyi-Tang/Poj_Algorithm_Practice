#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int max(int a , int b){
	if(a < b)
		return b;
	else
		return a;
}

int min(int a, int b){
	if(a < b)
		return a;
	else
		return b;
}


int findLength(int number){
	int storeNum = number;
	int counter = 1;
	while(number != 1){

		if(number % 2 ==0)
			number = number /2;
		else
			number = number * 3 + 1;
		counter ++;
	}

	return counter;
}

int main()
{
	int num1, num2,start,end,maxValue,number;
	while(cin >> num1){
		cin >> num2;
		maxValue = 0;
		start = min(num1,num2);
		end = max(num1,num2);
		for(int i = start;i <= end;i++){
			number = findLength(i);
			if(maxValue < number)
				maxValue = number;
		}
		cout << num1 << " " << num2 << " " << maxValue << endl;
	}
	return 0;
}
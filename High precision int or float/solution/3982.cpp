#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 100
#define size 10000

int series [N][size];
int firstNum, secondNum,thirdNum;

void storeInt(int number, int index){
	int length = 0;
	while(number != 0){
		series[index][++length] = number % 10;
		number = number / 10;
	}

	if(length == 0)
		series[index][++length] = 0;
	
	series[index][0] = length;
}

void print(int index){
	string number;
	for(int i = series[index][0];i >=1;i--)
		number += series[index][i] + '0';
	cout << number << endl;
}

void carry(int index,int length){
	for(int i =1;i <= length;i++){
		if(series[index][i] >= 10){
			if(i == length)
				series[index][++length] = 0;
			series[index][i+1] += series[index][i] / 10;
			series[index][i] = series[index][i] % 10;
		}
	}

	series[index][0] = length;
}

void addThree(int a2){
	int index = a2 +1;
	int length = series[a2][0];

	for(int i = 1;i <= length;i++)
		series[index][i] = series[a2][i];

	for(int i = 2;i <=3;i++){
		for(int j = 1;j <= series[index-i][0];j++)
			series[index][j] += series[index-i][j];
	}
	carry(index,length);
}


int getVlaue(int index){
	if(series[index][0] != 0)
		return index;
	else{
		getVlaue(index -3);
		getVlaue(index -2);
		getVlaue(index -1);
		addThree(index -1);
		return index;
	}
}

void addFourthNum(){
	int length;
	if(series[0][0] >= series[1][0] && series[0][0] >= series[2][0])
		length = series[0][0];
	else if(series[1][0] >= series[0][0] && series[1][0] >= series[2][0])
		length = series[1][0];
	else
		length = series[2][0];

	for(int i =1;i <= length;i++)
		series[3][i] = 0;

	for(int i = 0;i <=2 ;i++){
		for(int j = 1;j <= series[i][0];j++)
			series[3][j] += series[i][j];
	}
	carry(3,length);
		
}

void intal(){
	for(int i =0;i < N;i++)
		series[i][0] = 0;

	storeInt(firstNum,0);
	storeInt(secondNum,1);
	storeInt(thirdNum,2);
	addFourthNum();
}


int main()
{
	while(cin >> firstNum){
		cin >> secondNum;
		cin >> thirdNum;
		intal();
		getVlaue(99);
		print(99);
	}
	return 0;
}





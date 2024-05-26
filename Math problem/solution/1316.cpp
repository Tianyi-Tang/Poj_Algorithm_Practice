#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 10000

bool allNum[N];

int plusSum(int number){
	int temp = number;
	while(temp != 0){
		number += temp % 10;
		temp = temp / 10;
	}
	return number;
}

void inital(){
	for(int i =0;i < N;i++)
		allNum[i] = true;

	int number;
	for(int i = 1;i <= N;i++){
		number = plusSum(i);
		if(number < N)
			allNum[number-1] = false;
	}

}


int main()
{
	inital();
	for(int i =0;i < N;i++){
		if(allNum[i] && i != 9999)
			cout << i + 1 <<endl;
	}
	return 0;
}
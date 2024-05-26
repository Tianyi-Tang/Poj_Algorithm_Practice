#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 1000000

bool allNumber[N];
int number;

void findAllPrime(){
	allNumber[0] = true;
	int i;
	for(i = 2;(long) i * i <= N;i++){
		if(!allNumber[i-1]){
			for(long j = i *i;j <= N;j+= i)
				allNumber[j-1] = true;
		}
	}
}

void printResult(int i){
	cout << number << " = " << number - i -1 << " + " << i + 1 << endl;
}



int main()
{
	findAllPrime();
	
	while(cin >> number){
		if(number == 0)
			break;
		int i;
		int halfway = number /2 -1;
		for(i = number -2;i >= halfway;i--){
			if(!allNumber[i] && !allNumber[number-i-2] && number-i-2 != 1)
				break;
		}

		if(i == halfway -1)
			cout << "Goldbach's conjecture is wrong." << endl;
		else
			printResult(i);

	}
	return 0;
}
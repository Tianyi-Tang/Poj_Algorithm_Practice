#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define allNumLength 300
#define primeLength 62

bool allNum[allNumLength];
int primeSize;
int primes[primeLength];
int factor[primeLength];




void findPrime(){
	primeSize = 0;
	int i;
	for(i =2;i * i <= allNumLength;i++){
		if(!allNum[i-1]){
			for(int j = i * i; j <= allNumLength;j+=i)
				allNum[j-1] = true;
			primes[primeSize++] = i;
		}
	}

	for(int j = i;j < allNumLength;j++){
		if(!allNum[j])
			primes[primeSize++] = j+1;
	}
}


void findFactor(int number){
	for(int i =0;i < primeLength;i++)
		factor[i] =0;


	int index,counter;
	index = 0;
	while(number != 1 && index < primeLength){
		counter = 0;
		while(number % primes[index] == 0){
			number = number / primes[index];
			counter ++;
		}
		cout << "factor " << primes[index] << ":" << counter << endl;
		factor[index] = counter;
		index++;
	}
}


int main()
{
	findPrime();
	findFactor(1679616);
	return 0;
}
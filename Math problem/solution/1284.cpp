#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 65536
#define primeLength 6542

bool allNumber[N];
int primeSize = 0;
int primes[primeLength];

int factors[primeLength/2];
int factorsSize;

void findAllPrime(){
	for(int i =0;i < N;i++)
		allNumber[i] = true;

	int i;
	for(i = 2;i * i <= N;i++){
		if(allNumber[i-1]){
			for(int j = i * i; j <= N;j+= i)
				allNumber[j-1] = false;
			primes[primeSize++] = i;
		}
	}

	for(int j = i; j <= N;j++){
		if(allNumber[j-1])
			primes[primeSize++] = j;
	}
}

void factorization(int number){
	int prime;
	int counter;
	factorsSize = 0;
	for(int i =0;i < primeSize;i++){
		prime = primes[i];
		counter = 0;
		while(number % prime == 0){
			number = number / prime;
			if(counter ==0)
				factors[factorsSize++] = prime;
			counter ++;
		}
		if(number ==1)
			break;
	}
}

int findPrimitiveRoot(int number){
	int d = 1;
	for(int i =0;i < factorsSize;i++){
		number = number / factors[i];
		d *= factors[i] -1;
	}
	return d * number;
}




int main()
{
	findAllPrime();
	int number;
	while(scanf("%d",&number) != EOF){
		factorization(number -1);
		cout << findPrimitiveRoot(number) << endl;
	}
	
	
	return 0;
}
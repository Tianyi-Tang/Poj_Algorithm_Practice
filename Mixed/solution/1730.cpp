#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define numberLength 65536
#define primeLength 6742

bool allNum[numberLength];
int primeSize,storingIndex;
int primes[primeLength],storIndex[32];

void findPrime(){
	int i;
	for(i = 2; i * i <= numberLength;i++){
		if(!allNum[i-1]){
			for(int j = i * i;j <= numberLength;j+=i)
				allNum[j-1] = true;
		}
		primes[primeSize ++] = i;
	}

	for(int j = i;j < numberLength;j++){
		if(!allNum[j])
			primes[primeSize++] = j+1;
	}
}


int findGcd(int a, int b){
	int t;
	if(a < b)
		swap(a,b);
	while(b){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}


int main()
{
	long long inputNum;
	int index,prime,counter,gcd;
	bool negative;
	findPrime();

	while(cin >> inputNum){
		if(inputNum == 0)
			break;

		if(inputNum < 0){
			inputNum *= -1;
			negative = true;
		}
		else
			negative = false;

		index = storingIndex = 0;
		while(inputNum != 1 && index < primeLength){
			prime = primes[index];
			counter = 0;
			while(inputNum % prime == 0){
				inputNum = inputNum / prime;
				counter ++;
			}
			if(counter !=0)
				storIndex[storingIndex++] = counter;
			index ++;
		}
		if(inputNum != 1)
			cout << 1 << endl;
		else{
			if(storingIndex == 1)
				gcd =storIndex[0];
			else{
				gcd = findGcd(storIndex[0],storIndex[1]);
				for(int i =2;i < storingIndex;i++){
					gcd = findGcd(gcd,storIndex[i]);
					if(gcd == 1)
						break;
				}
			}
			if(negative){
				while(gcd % 2 ==0)
					gcd = gcd / 2;
			}
			cout << gcd << endl;
		}
	}
	
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 10000
#define primeLength 1229

bool allNumber[N];
int primeSize;
int primes[primeLength];

void findAllPrimes(){
	for(int i =0;i < N;i++)
		allNumber[i] = true;

	primeSize = 0;
	int i;
	for(i = 2;(long) i * i <= N;i++){
		if(allNumber[i-1]){
			for(int j = i * i; j <= N;j+=i)
				allNumber[j-1] = false;
			primes[primeSize++] = i;
		}
	}

	for(int j = i; j <= N;j++){
		if(allNumber[j-1])
			primes[primeSize++] = j;
	}
}

int digtalAdding(int number){
	int digital = 0;
	while(number!= 0){
		digital += number % 10;
		number = number / 10;
	}

	return digital;
}


int main()
{
	int number, digitalAdding1,digitalAdding2,temp,index,prime,counter;
	bool flag;
	findAllPrimes();

	while(cin >> number){
		if(number == 0)
			break;
		flag =false;
		while(flag == false){
			number ++;
			index = 0;
			counter = 0;
			temp = number;
			prime = primes[index];
			digitalAdding1 = digtalAdding(temp);
			digitalAdding2 = 0;
			while(temp != 1 && index < primeLength){
				if(temp % prime == 0){
					temp = temp / prime;
					digitalAdding2 += digtalAdding(prime);
					counter ++;
				}
				else
					prime = primes[++index];
			}
			if(temp != 1){
				digitalAdding2 += digtalAdding(temp);
				counter ++;
			}
			if(digitalAdding2 == digitalAdding1 && counter > 1)
				flag = true;
		}
		cout << number << endl;
	}
	
	return 0;
}

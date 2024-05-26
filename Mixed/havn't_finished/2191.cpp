#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define numberLength 600
#define primeLength 109
bool allNum[numberLength];
int primeSize;
int primes[primeLength];


void findPrime(){
	int i;
	for(i = 2; i * i <= numberLength;i++){
		if(!allNum[i-1]){
			for(int j = i * i;j <= numberLength;j+=i)
				allNum[j-1] = true;
			primes[primeSize ++] = i;
		}
	}

	for(int j = i;j < numberLength;j++){
		if(!allNum[j])
			primes[primeSize ++] = j+1;
	}
}

long long powerMode(int x,long long d, long long mode){
	long long res = 1;
	x = x % mode;
	cout << mode << endl;

	while(d > 0){
		if(d & 1)
			res = (res * x) % mode;
		d >>= 1;
		x = (x*x) % mode;
	}
	return res;
}

int maxIndex(long long num){
	int i;
	for(i = primeSize -1;i >=0;i--){
		if(num - 4 > primes[i])
			break;
	}
	return i;
}

bool millerTest(long long n, long long d,int r){
	int range = maxIndex(n) + 1;
	int a = primes[rand() % range];
	long long x = powerMode(a,d,n);

	if(x == 1 || x == n-1)
		return true;

	while(r){
		x = (x * x) % n;
		r --;

		if(x == 1)
			return false;
		if(x == n-1)
			return true;
	}
	return false;
}



 bool isPrime(long long num,int times){
	if(num % 2 ==0)
		return false;
	else if (num <= 3)
		return true;

	int d = num -1;
	int index = 0;
	while(!(d & 1)){
		d >>= 1;
		index ++;
	}
	
	for(int i =0;i < times;i++){
		if(!millerTest(num,d,index))
			return false;
	}
	return true;

}



int main()
{
	findPrime();
	cout << isPrime(16777215,10) << endl;


	return 0;
}
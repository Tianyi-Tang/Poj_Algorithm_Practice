#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[500];
};

int N = 10000;

bool number[10000];
int primes[1299];
int primeSize = 0;


int factors[1299];

void findPrime(){
	for(int i =0;i < 1299;i++)
		factors[i] = 0;

	for(int i =0;i < N;i++)
		number[i] = true;


	for(int i =2; i * i <= N;i++){
		if(number[i-1]){
			for(int j = i * i;j <=N;j+=i)
				number[j-1] = false;
			primes[primeSize++] = i;
		}
	}

	for(int i = 100;i < N;i++){
		if(number[i])
			primes[primeSize++] = i+1;
	}
}

void factorization(int num){
	int index = 0;
	int time, prime;
	prime = primes[index];

	while(num > prime){
		time = 0;
		while(num % prime ==0){
			time++;
			num = num / prime;
		}
		if(time > factors[index])
			factors[index] = time;
		prime = primes[++index];
	}
}

void intToBigInt(BigInt& a, int number){
	a.size = 0;
	while(number != 0){
		a.num[a.size++] = number % 10;
		number = number / 10;
	}

	if(a.size == 0){
		a.size = 1;
		a.num[0] = 0;
	}
}

void print(BigInt& a){
	string num;
	for(int i = a.size -1;i >=0;i--)
		num += a.num[i] + '0';
	cout << num << endl;
}

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size-1] == 0)
		a.size --;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void carry(BigInt& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(a.size -1 == i)
				a.num[a.size++] = 0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

bool bigger(BigInt& a, BigInt& b){
	if(a.size > b.size)
		return true;
	else if(a.size < b.size)
		return false;
	else{
		for(int i = a.size -1;i >=0;i--){
			if(a.num[i] > b.num[i])
				return true;
			else if(a.num[i] < b.num[i])
				return false;
		}
		return true;
	}
}

void multiple(BigInt& a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i =0;i < a.size;i++){
		for(int j = 0;j < b.size;j++)
			c.num[i + j] += a.num[i] * b.num[j];
	}
	carry(c);
	removeHeadingZero(c);
	copy(a,c);
}

void lcm(BigInt& a){
	BigInt result,temp;
	intToBigInt(a,1);

	for(int i =0;i < 1299;i++){
		intToBigInt(result,1);
		if(factors[i] != 0){
			intToBigInt(result,primes[i]);

			int j;
			for(j =1;j * 2 <= factors[i];j *=2){
				copy(temp,result);
				multiple(result,temp);
			}

			intToBigInt(temp,primes[i]);
			for(int z = j;z < factors[i];z ++)
				multiple(result,temp);
		}
		multiple(a,result);
	}
}


void gcd(int a, int b){
	
}



int main()
{
	BigInt a;
	findPrime();


	return 0;
}






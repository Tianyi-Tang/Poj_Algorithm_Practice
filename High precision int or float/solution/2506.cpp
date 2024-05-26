#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[400];
};

int storage[301][401];
BigInt two;

void intToBigInt(BigInt& a, int number){
	a.size = 0;
	while(number != 0){
		a.num[a.size++] = number % 10;
		number = number / 10;
	}

	if(a.size ==0){
		a.size = 1;
		a.num[0] = 0;
	}
}

void print(BigInt& a){
	string number;
	for(int i = a.size -1;i >=0;i--)
		number += a.num[i] + '0';
	cout << number << endl;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void removeHeadingZero(BigInt& a){
	while(a.size >=2 && a.num[a.size -1] ==0)
		a.size --;
}

void carry(BigInt& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(a.size == i + 1)
				a.num[a.size++] = 0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void add(BigInt& a,BigInt& b){
	for(int i = a.size;i < b.size;i++)
		a.num[a.size++] = 0;

	for(int i =0;i < b.size;i++)
		a.num[i] += b.num[i];
	carry(a);
}

void multiple(BigInt& a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i =0;i < a.size;i++){
		for(int j = 0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}
	carry(c);
	removeHeadingZero(c);
	copy(a,c);
}

void sotreReuslt(BigInt& a, int index){
	storage[index][0] = a.size;
	for(int i = 0;i < a.size;i++)
		storage[index][i+1] = a.num[i];
}

void getResult(BigInt& a,int index){
	a.size = storage[index][0];
	for(int i = 0;i < a.size;i++)
		a.num[i] = storage[index][i+1];
}

void numberOfTile(BigInt& a,int n){
	if(storage[n][0] != 0)
		getResult(a,n);
	else{
		BigInt b,c;
		numberOfTile(c,n-2);
		numberOfTile(b,n-1);
		multiple(c,two);
		add(b,c);
		sotreReuslt(b,n);
		copy(a,b);
	}
}

void inital(){
	for(int i = 0;i <= 300;i++)
		storage[i][0] = 0;

	for(int i = 0;i < 2;i++){
		storage[i][0] = 1;
		storage[i][1] = 1;
	}
	intToBigInt(two,2);
}

int main()
{
	inital();
	BigInt a;
	int number;
	while(cin >> number){
		numberOfTile(a,number);
		print(a);
	}
	
	return 0;
}








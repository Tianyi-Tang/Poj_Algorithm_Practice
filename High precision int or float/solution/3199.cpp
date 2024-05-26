#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[50];
};

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

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] ==0)
		a.size --;
}

void copy(BigInt & a, BigInt& b){
	a.size = b.size;
	for(int i = 0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void carry(BigInt& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(a.size -1 == i)
				a.num[a.size++] =0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void multiple(BigInt& a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i =0;i < a.size;i++){
		for(int j =0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}
	carry(c);
	removeHeadingZero(c);
	copy(a,c);
}

void power(BigInt& a, int number, int time){
	BigInt childrenNum;
	intToBigInt(a,1);
	intToBigInt(childrenNum,number);

	for(int i = 0;i < time;i++){
		multiple(a,childrenNum);
	}
}

int main()
{
	BigInt a;
	int childNum,cdNum;
	while(cin >> childNum){
		cin >> cdNum;
		if(childNum == 0 && cdNum ==0)
			break;
		power(a,childNum,cdNum);
		print(a);
	}

	return 0;
}



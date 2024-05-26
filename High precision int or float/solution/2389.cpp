#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[200];
};

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] == 0)
		a.size --;
}

void stringToBigInt(BigInt& a, string number){
	a.size = 0;
	for(int i = number.length() -1;i >=0;i--)
		a.num[a.size++] = number[i] - '0';
	removeHeadingZero(a);
}

void print(BigInt& a){
	string number;
	for(int i = a.size -1;i >=0;i--)
		number += a.num[i] + '0';
	cout << number << endl;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++){
		a.num[i] = b.num[i];
	}
}

void carry(BigInt& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(a.size - 1 == i)
				a.num[a.size++] = 0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void multiple(BigInt& a,BigInt& b){
	BigInt c;
	c.size = a.size + b.size;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i = 0;i < a.size;i++){
		for(int j =0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}
	carry(c);
	removeHeadingZero(c);
	copy(a,c);
}

int main()
{
	BigInt a,b;
	string num1,num2;
	while(cin >> num1){
		cin >> num2;
		stringToBigInt(a,num1);
		stringToBigInt(b,num2);
		multiple(a,b);
		print(a);
	}
	return 0;
}









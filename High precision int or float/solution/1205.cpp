#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct BigInt
{
	int size;
	int num[10000];
};

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size-1] ==0)
		a.size --;
}

void print(BigInt& a){
	string number;
	for(int i=a.size-1;i >=0;i--)
		number += a.num[i] + '0';
	cout << number << endl;
}

void stringToBigInt(BigInt& a, string number){
	a.size =0;

	for(int i= number.size() -1;i >=0;i--)
		a.num[a.size++] = number[i] -'0';

	removeHeadingZero(a);
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i=0; i < b.size;i++){
		a.num[i] = b.num[i];
	}
}

void carry(BigInt& a){
	for(int i=0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i +1 == a.size){
				a.num[i+1] = 0;
				a.size ++;
			}
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void add(BigInt& a,BigInt& b){
	int i;
	for(i =0;i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] += b.num[i];
	}

	for(int j =i;j < b.size;j++)
		a.num[j] = b.num[j];

	carry(a);
}

void sub(BigInt& a,BigInt& b){
	for(int i=0;i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] -= b.num[i];
	}

	for(int i =0;i < a.size;i++){
		if(a.num[i] < 0){
			a.num[i + 1] -= 1;
			a.num[i] += 10;
		}
	}
	removeHeadingZero(a);
}

void mult(BigInt& a, BigInt&b){
	BigInt c;
	c.size = a.size + b.size;

	for(int i=0;i < c.size;i++)
		c.num[i] =0;

	for(int i=0;i < a.size;i++){
		for(int j =0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}

	carry(c);
	removeHeadingZero(c);
	copy(a,c);
}

void moveUp(BigInt& a,BigInt& b){
	BigInt c,three,two;
	stringToBigInt(three,"3");
	stringToBigInt(two,"2");
	copy(c,a);
	sub(a,b);
	mult(a,three);
	mult(b,two);
	add(a,b);
	copy(b,c);
}

void result(BigInt& a, BigInt& b){
	BigInt two;
	stringToBigInt(two, "2");
	sub(a,b);
	mult(a,two);
	add(a,b);
}

void possibleSetUp(int number){
	if(number <3){
		if(number <2)
			cout << number << endl;
		else
			cout << 3 << endl;
		return;
	}
	BigInt a,b;
	stringToBigInt(a,"5");
	stringToBigInt(b, "2");

	for(int i =0; i < number-3;i++)
		moveUp(a,b);
	result(a,b);
	print(a);
}


int main(int argc, char const *argv[])
{
	int number;
	while(cin >> number){
		possibleSetUp(number);
	}

	return 0;
}

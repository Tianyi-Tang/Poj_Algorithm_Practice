#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[100000];
};

void removeHeadZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] == 0)
		a.size --;
}

void stringToBigInt(string number, BigInt& a){
	a.size = 0;
	for(int i= number.size() -1;i >=0;i--)
		a.num[a.size ++] = number[i] - '0';

	removeHeadZero(a);
}

void print(BigInt a){
	string number;
	for(int i= a.size -1; i >=0;i--)
		number += a.num[i] + '0';

	cout << number << endl;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i=0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void carry(BigInt& a){
	for(int i=0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i == a.size -1){
				a.num[i+1] = 0;
				a.size ++;
			}
			a.num[i +1] += a.num[i] /10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void add(BigInt& a, BigInt& b){
	for(int i= a.size;i < b.size;i++){
		a.num[i] = 0;
		a.size ++;
	}

	for(int i =0; i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] += b.num[i];
	}

	carry(a);
}

void multi(BigInt& a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;

	for(int i=0;i < c.size;i++)
		c.num[i] = 0;

	for(int i=0;i < a.size;i++){
		for(int j =0;j <b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	} 

	carry(c);
	removeHeadZero(c);
	copy(a,c);
}

int main()
{
	int number;
	BigInt a,b,one;

	stringToBigInt("1",one);
	while(cin >>number){
		if(number >= 1)
			cout << 2 << endl;
		if(number >=2)
			cout << 3 << endl;

		stringToBigInt("2",a);
		stringToBigInt("3",b);
		for(int i =2;i < number;i++){
			multi(a,b);
			copy(b,a);
			add(a,one);
			print(a);
		}

	}


	return 0;
}




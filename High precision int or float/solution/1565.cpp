#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[100000];
};

void charToBigInt(char number, BigInt& a){
	a.size =1;
	a.num[0] = number - '0';
}

void carry(BigInt& a){
	for(int i=0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(a.size -1 == i){
				a.num[i+1] = 0;
				a.size ++;
			}
			a.num[i+1] += a.num[i] /10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void removeHeadZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] == 0)
		a.size --;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i=0;i < b.size;i++)
		a.num[i] = b.num[i];
}

void print(BigInt& a){
	string number;
	for(int i= a.size -1;i >=0;i--)
		number += a.num[i] + '0';

	cout << number << endl;
}

void add(BigInt& a, BigInt& b){
	for(int i= a.size;i < b.size;i++){
		a.num[i] =0;
		a.size ++;
	}

	for(int i=0;i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] += b.num[i];
	}

	carry(a);
}


void mult(BigInt& a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;

	for(int i=0;i < c.size;i++)
		c.num[i] = 0;

	for(int i=0;i < a.size;i++){
		for(int j=0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}

	carry(c);
	removeHeadZero(c);
	copy(a,c);
}

void power(BigInt& a, int time, BigInt& b){
	charToBigInt('1',b);

	for(int i=0;i < time;i++){
		mult(b,a);
	}
}

void translateToDecimal(string number,BigInt& b){
	BigInt a, c,one,two;
	charToBigInt('0',b);
	charToBigInt('1',one);
	charToBigInt('2',two);
	for(int i =0;i < number.size();i++){
		charToBigInt(number[number.size() -1 -i],a);
		power(two,i+1,c);
		sub(c,one);
		mult(c,a);
		add(b,c);
	}
}



int main()
{
	BigInt a;
	string number;
	while(cin >> number){
		if(number == "0")
			break;
		translateToDecimal(number,a);
		print(a);
	}

}





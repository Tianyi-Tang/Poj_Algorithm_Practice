#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[10000];
};



void intToBigInt(int number, BigInt& a){
	int size = 0;

	while(number != 0){
		a.num[size++] = number % 10;
		number = number / 10;
	}
	a.size = size;
	if(a.size ==0){
		a.size = 1;
		a.num[0] = 0;
	}

}

void print(BigInt& a){
	string number;
	for(int i = a.size -1; i >=0;i--){
		number += a.num[i] + '0';
	}
	cout << number << endl;
}

void result(BigInt& a, int number){
	cout << number;
	cout << "! --" << endl;
	cout << "   ";
	int counter;

	for(int i=0;i <= 9;i++){
		counter = 0;
		for(int j =0; j < a.size;j++){
			if(i == a.num[j])
				counter ++;
		}

		cout << "(";
		cout << i;
		cout << ")";
		if(counter < 10)
			cout << "    ";
		else if(counter < 100)
			cout << "   ";
		else
			cout << "  ";
		cout << counter;
		cout << "    ";
		if(i == 4){
			cout << endl;
			cout << "   ";
		}
	}
	cout << endl;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i=0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void removeHeadZero(BigInt& a){
	while(a.size >=2 && a.num[a.size-1] ==0)
		a.size --;
}

void carry(BigInt& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i == a.size -1){
				a.num[i+1] = 0;
				a.size ++;
			}
			a.num[i+1] += a.num[i] /10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void mult(BigInt& a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;

	for(int i=0;i < c.size;i++)
		c.num[i] =0;

	for(int i=0;i < a.size;i++){
		for(int j=0;j < b.size;j++){
			c.num[i+j] += a.num[i] * b.num[j];
		}
	}

	carry(c);
	removeHeadZero(c);
	copy(a,c);
}

void factorial(int number, BigInt& a){
	BigInt b;
	intToBigInt(1,a);

	for(int i=1;i < number+1;i++){
		intToBigInt(i,b);
		mult(a,b);
	}

}

int main()
{
	BigInt a;
	int number;
	while(cin >> number){
		if(number ==0)
			break;
		factorial(number,a);
		result(a,number);
	}

	return 0;
}
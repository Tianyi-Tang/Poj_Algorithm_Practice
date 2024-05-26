#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num [500];
};

void removeHeadZero(BigInt& a){
	while(a.size >=2 && a.num[a.size -1] == 0)
		a.size --;
}

void stringToBigInt(string number,BigInt& a){
	a.size = 0;
	for(int i= number.size() -1;i >= 0;i--){
		a.num[a.size ++] = number[i] - '0';
	}
	removeHeadZero(a);
}

void print(BigInt& a){
	string number;
	for(int i= a.size -1; i>=0;i--)
		number += a.num[i] + '0';

	cout << number << endl;
}

void carry(BigInt& a){
	for(int i=0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(a.size -1 ==i){
				a.num[i+1] = 0;
				a.size ++;
			}
			a.num[i+1] += a.num[i] /10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void add(BigInt& a ,BigInt& b){

	for(int i =a.size;i < b.size;i++){
		a.num[i] = 0;
		a.size ++;
	}

	for(int i=0;i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] += b.num[i];
	}
	carry(a);
	removeHeadZero(a);
}

int main()
{
	BigInt a,b;
	string number;
	stringToBigInt("0",a);
	while(cin >> number){
		if(number == "0")
			break;
		stringToBigInt(number,b);
		add(a,b);
	}
	print(a);
	return 0;
}
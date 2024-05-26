#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[1000];
};

void removeHeadZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] == 0)
		a.size --;

}

void stringToBigInt(string number, BigInt& a){
	a.size =0;
	for(int i=0;i < number.size();i++)
		a.num[a.size ++] = number[i] - '0'; 
	
	removeHeadZero(a);
}

void print(BigInt& a){
	string number;
	for(int i= a.size -1; i >=0;i--)
		number += a.num[i] + '0';
	
	cout << number << endl;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < b.size;i++){
		a.num[i] = b.num[i];
	}
}

void reversed(BigInt& a){
	BigInt b;
	b.size =0;
	for(int i= a.size -1; i >= 0;i--){
		b.num[b.size ++] = a.num[i];
	}
	removeHeadZero(b);
	copy(a,b);
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
	for(int i = a.size;i < b.size;i++){
		a.num[i] = 0;
		a.size ++;
	}

	for(int i=0;i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] += b.num[i];
	}
	carry(a);
}

void spiltNumber(string number,string& num1, string& num2){
	int i;
	for(i = 0;i < number.size();i++){
		if(number[i] == ' ')
			break;
		num1 += number[i];
	}

	for(int j= i+1;j < number.size();j++)
		num2 += number[j];
}

int main()
{
	int times;
	cin >> times;
	string number1, number2, line;
	BigInt a,b;
	for(int i=0;i < times;i++){
		cin >> number1;
		cin >> number2;
		stringToBigInt(number1,a);
		stringToBigInt(number2,b);
		add(a,b);
		reversed(a);
		print(a);
	}
	return 0;
}
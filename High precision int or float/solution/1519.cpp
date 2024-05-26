#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num [1000];
};

void removeHeadZero(BigInt& a){
	while(a.size >=2 && a.num[a.size -1] == 0)
		a.size --;
}

void stringToBigInt(string number,BigInt& a){
	a.size =0;
	for(int i= number.size()-1;i >= 0;i--)
		a.num[a.size++] = number[i] -'0';

	removeHeadZero(a);
}

void print(BigInt& a){
	string number;
	for(int i= a.size -1; i >=0;i--)
		number += a.num[i] + '0';

	cout << number << endl;

}

void carry(BigInt& a){
	for(int i=0;i < a.size;i ++){
		if(a.num[i] >= 10){
			if(a.size -1 == i){
				a.num[i +1] = 0;
				a.size ++; 
			}
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}


void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i= 0;i < a.size;i++)
		a.num[i] = b.num[i];
}

bool isRoot(BigInt& a){
	if(a.size > 1)
		return false;

	if(a.num[0] < 10)
		return true;
	else 
		return false;
}

void addTogether(BigInt& a){
	for(int i = 1;i < a.size;i++)
		a.num[0] += a.num[i];
	a.size = 1;
}

int main()
{
	string number;
	BigInt a;
	while(cin >> number){
		if(number == "0")
			break;
		stringToBigInt(number,a);
		addTogether(a);
		while(!isRoot(a)){
			carry(a);
			addTogether(a);
		}
		print(a);
	}



	return 0;
}



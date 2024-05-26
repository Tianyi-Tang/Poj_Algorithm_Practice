#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[50000];
	bool postive;
};

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] == 0)
		a.size --;
}

void stringToBigInt(BigInt& a,string number){
	a.size =0;
	int end =0;
	a.postive = true;

	if(number[0] == '+')
		end = 1;
	else if(number[0] == '-'){
		end = 1;
		a.postive = false;
	}

	for(int i = number.length() -1;i >=end;i--)
		a.num[a.size++] = number[i] - '0';
	removeHeadingZero(a);
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	a.postive = b.postive;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void print(BigInt& a){
	string number;
	if(!a.postive && !(a.size == 1 && a.num[0] == 0))
		number += '-';

	for(int i= a.size -1;i >=0;i--)
		number += a.num[i] + '0';

	cout << number << endl;
}

void carry(BigInt& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(a.size -1 == i)
				a.num[a.size++] = 0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

bool bigger(BigInt& a ,BigInt & b){
	if(a.size > b.size)
		return true;
	else if(a.size < b.size)
		return false;
	else{
		for(int i = a.size -1;i >=0;i--){
			if(a.num[i] > b.num[i])
				return true;
			else if(a.num[i] < b.num[i])
				return false;
		}
		return true;
	}
}

void add(BigInt& a, BigInt& b){
	for(int i = a.size;i < b.size;i++)
		a.num[a.size++] = 0;

	for(int i =0; i < b.size;i++)
		a.num[i] += b.num[i];
	carry(a);
}

void subtract(BigInt& a, BigInt& b){
	for(int i =0;i < b.size;i++)
		a.num[i] -= b.num[i];

	for(int i =0;i < a.size;i++){
		if(a.num[i] < 0){
			a.num[i] += 10;
			a.num[i+1] -= 1;
		}
	}
	removeHeadingZero(a);
}

void pluse(BigInt& a,BigInt& b,BigInt& c){
	if(a.postive == b.postive){
		add(a,b);
		copy(c,a);
	}
	else{
		if(bigger(a,b)){
			subtract(a,b);
			copy(c,a);
		}
		else{
			subtract(b,a);
			copy(c,b);
		}
	}
}

int main()
{	
	BigInt a, b,c;
	int number;
	string num1,num2;
	cin >> number;
	for(int i =0;i < number;i++){
		cin >> num1;
		cin >> num2;
		stringToBigInt(a,num1);
		stringToBigInt(b,num2);
		pluse(a,b,c);
		print(c);
	}
	return 0;
}







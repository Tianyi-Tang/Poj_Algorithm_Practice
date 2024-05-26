#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 200

struct BigInt{
	int size;
	int num[1000];
};

void intToBigInt(BigInt& a, int number){
	a.size = 0;
	while(number != 0){
		a.num[a.size++] = number % 10;
		number = number / 10;
	}

	if(a.size == 0){
		a.size = 1;
		a.num[0] = 0;
	}
}

void copy(BigInt& a, BigInt & b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] == 0)
		a.size --;
}

bool bigger(BigInt& a, BigInt& b){
	if(a.size > b.size)
		return true;
	else if(a.size < b.size)
		return false;
	else{
		for(int i =a.size -1;i >=0;i--){
			if(a.num[i] > b.num[i])
				return true;
			else if(a.num[i] < b.num[i])
				return false;
		}
		return true;
	}
}

void print(BigInt& a){
	string number;
	for(int i = a.size -1 ;i >=0;i--)
		number += a.num[i] + '0';
	cout << number << endl;
}

void carry(BigInt& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i == a.size -1)
				a.num[a.size++] = 0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10; 
		}
	}
}

void add(BigInt& a, BigInt& b){
	for(int i = a.size;i < b.size;i++)
		a.num[a.size++] = 0;

	for(int i =0;i < b.size;i++)
		a.num[i] += b.num[i];
	carry(a);
}

void subtract(BigInt& a, BigInt& b){
	for(int i =0;i < b.size;i++)
		a.num[i] -= b.num[i];

	for(int i =0;i < a.size;i++){
		if(a.num[i] < 0){
			a.num[i+1] -= 1;
			a.num[i] += 10;
		}
	}
	removeHeadingZero(a);
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

bool compareString(string a, string b){
	for(int i =0;i < a.length();i++){
		if(a[i] < b[i])
			return false;
		else if(a[i] > b[i])
			return true;
	}
	return true;
}

string divideInt(BigInt& a, BigInt& b){
	string number;
	BigInt c;
	copy(c,a);
	int digtial = 0;
	while(bigger(c,b)){
		subtract(c,b);
		digtial++;
	}
	number += digtial + '0';
	return number;
}

string divide(BigInt& a, BigInt& b){
	BigInt c,ten;
	intToBigInt(ten,10);
	copy(c,a);
	string number;
	int digtial;
	for(int i =0;i < 3;i++){
		digtial = 0;
		while(bigger(c,b)){
			subtract(c,b);
			digtial ++;
		}
		number += digtial + '0';
		if(i == 0)
			number += '.';
		multiple(c,ten);
	}

	return number;
}

int main()
{
	
	
	string floatInt,result;
	BigInt a, b,temp;
	int counter, number;
	while(cin >> result){
		if(result  == "0.00")
			break;

		counter = 1;
		number = 3;
		intToBigInt(a,1);
		intToBigInt(b,2);
		floatInt = divideInt(a,b);

		while(!compareString(floatInt,result)){
			intToBigInt(temp,number);
			multiple(a,temp);
			add(a,b);
			multiple(b,temp);
			counter ++;
			number ++;
			floatInt = divideInt(a,b);
		}

		floatInt = divide(a,b);
		while(!compareString(floatInt,result)){
			intToBigInt(temp,number);
			multiple(a,temp);
			add(a,b);
			multiple(b,temp);
			counter ++;
			number ++;
			floatInt = divide(a,b);
		}

		cout << counter << " card(s)" << endl;

	}
	return 0;
}










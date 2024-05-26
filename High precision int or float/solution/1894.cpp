#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[150];
};

void print(BigInt& a){
	string number;
	for(int i =a.size -1;i >=0;i--)
		number += a.num[i] + '0';

	cout << number << endl;
}

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size-1] == 0)
		a.size --;
}

void stringToBigInt(BigInt& a, string number){
	a.size =0;
	for(int i = number.length() -1;i >=0;i--){
		a.num[a.size++] = number[i] - '0'; 
	}
}

void intToBigInt(BigInt& a, int number){
	a.size = 0;
	while(number != 0){
		a.num[a.size++] = number % 10;
		number = number / 10;
	}

	if(a.size ==0){
		a.size = 1;
		a.num[0] = 0;
	}
}

bool bigger(BigInt& a,BigInt& b){
	if(a.size > b.size)
		return true;
	else if(a.size < b.size)
		return false;
	else{
		for(int i = a.size-1;i >=0;i--){
			if(a.num[i] > b.num[i])
				return true;
			else if(a.num[i] < b.num[i])
				return false;
		}
		return true;
	}
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
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

void add(BigInt& a, BigInt& b,BigInt& c){
	copy(c,a);

	for(int i = a.size;i < b.size;i++)
		c.num[c.size++] = 0;

	for(int i =0;i < b.size;i++){
		c.num[i] += b.num[i];
	} 

	carry(c);
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

void divid(BigInt& a, BigInt& b){
	BigInt r,c,ten;
	r.size = 1;
	r.num[0] = 0;
	intToBigInt(ten,10);

	c.size = a.size - b.size +1;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i = a.size -1; i >=0;i--){
		multiple(r,ten);
		r.num[0] = a.num[i];

		while(bigger(r,b)){
			subtract(r,b);
			c.num[i]++;
		}
	}
	removeHeadingZero(c);
	copy(a,c);
}

string convert(BigInt& a,int B){
	string convertNumber;
	int size = 0;
	BigInt powerNum,totalSum,power,temp;
	intToBigInt(power,B);
	intToBigInt(powerNum,1);
	intToBigInt(totalSum,0);

	while(bigger(a,powerNum)){
		add(totalSum,powerNum,temp);
		copy(totalSum,temp);
		multiple(powerNum,power);
		size++;
	}

	add(totalSum,powerNum,temp);
	while(!bigger(a,temp)){
		divid(powerNum,power);
		subtract(totalSum,powerNum);
		size--;
		add(totalSum,powerNum,temp);
	}

	int digital;
	for(int i = size;i >= 0;i--){
		digital = 0;
		add(totalSum,powerNum,temp);
		while(bigger(a,temp)&& digital < B){
			digital ++;
			subtract(a,powerNum);
		}
		convertNumber += digital + '0';
		if(i != 0){
			divid(powerNum,power);
			subtract(totalSum,powerNum);
		}
	}

	return convertNumber;
}

int main()
{

	BigInt a;
	string number,convertNumber;
	int power;
	while(cin >> power){
		cin >> number;
		stringToBigInt(a,number);
		convertNumber = convert(a,power);
		cout << convertNumber << endl;
	}

	return 0;
}






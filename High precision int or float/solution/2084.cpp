#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[1000];
};

void intToBigInt(BigInt& a,int number){
	a.size = 0;
	while(number != 0){
		a.num[a.size++] = number % 10;
		number = number /10;
	}

	if(a.size == 0){
		a.size = 1;
		a.num[0] = 0;
	}
}

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size-1] == 0)
		a.size --;
}

void print(BigInt& a){
	string number;
	for(int i = a.size -1;i >= 0;i--)
		number += a.num[i] + '0';
	cout << number << endl;
}

void carry(BigInt& a){

	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i == a.size -1)
				a.num[a.size++] = 0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] =  a.num[i] % 10;
		}
	}
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

bool bigger(BigInt& a, BigInt& b){
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


void subtract(BigInt& a, BigInt& b){
	for(int i =0;i < b.size;i++){
		a.num[i] -= b.num[i];
	}

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
	intToBigInt(r,0);
	intToBigInt(ten,10);

	c.size = a.size - b.size +1;
	for(int i=0;i < c.size;i++)
		c.num[i] = 0;

	for(int i = a.size -1;i >=0;i--){
		multiple(r,ten);
		r.num[0] = a.num[i];

		while(bigger(r,b)){
			subtract(r,b);
			c.num[i] ++;
		}
	}
	removeHeadingZero(c);
	copy(a,c);
}

void catalanNumber(BigInt& a,int n){
	BigInt b,c,two;
	int startNum, end;
	if(n % 2 != 0){
		startNum = n +2;
		end = (startNum - 1) /2;
	}
	else{
		startNum = n +3;
		end = (startNum -3) /2;
	}

	intToBigInt(a,1);
	intToBigInt(c,1);
	for(int i = startNum;i <= 2*n;i = i+2){
		intToBigInt(b,i);
		multiple(a,b);
	}

	intToBigInt(two,2);
	for(int i =0;i < n - end;i++)
		multiple(a,two);

	for(int i = 1;i <= end;i++){
		intToBigInt(b,i);
		multiple(c,b);
	}

	divid(a,c);
}

int main()
{
	BigInt a;
	int number;
	while(cin >> number){
		if(number == -1)
			break;
		catalanNumber(a,number);
		print(a);
	}
	
	return 0;
}








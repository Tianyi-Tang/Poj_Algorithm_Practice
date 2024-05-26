#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[1000];
};

int connectGraphNumber[50][1001];

void intToBigInt(BigInt& a, int num){
	a.size = 0;
	while(num != 0){
		a.num[a.size++] = num % 10;
		num = num / 10;
	}

	if(a.size == 0){
		a.size = 1;
		a.num[0] = 0;
	}
}

void arryToBigInt(BigInt& a, int number){
	a.size = connectGraphNumber[number-1][0];
	for(int i =0;i < a.size;i++)
		a.num[i] = connectGraphNumber[number-1][i+1];
}

void BigIntToArray(BigInt&a,int number){
	connectGraphNumber[number-1][0] = a.size;
	for(int i=0;i < a.size;i++)
		connectGraphNumber[number-1][i+1] = a.num[i];
}

void print(BigInt& a){
	string number;
	for(int i =a.size -1;i >=0;i--)
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

void copy(BigInt& a, BigInt& b){
	a.size = b.size;

	for(int i= 0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size-1] == 0)
		a.size --;
}

bool bigger(BigInt& a, BigInt& b){
	if(a.size > b.size)
		return true;
	else if(a.size < b.size)
		return false;
	else{
		for(int i = b.size -1;i >= 0;i--){
			if(a.num[i] > b.num[i])
				return true;
			else if(a.num[i] < b.num[i])
				return false;
		}
		return true;
	}
}

void add(BigInt& a, BigInt& b){
	for(int i = a.size; i < b.size;i++){
		a.num[i] = 0;
		a.size++;
	}

	for(int i =0;i < b.size;i ++)
		a.num[i] += b.num[i];

	carry(a);
}

void subtract(BigInt& a, BigInt& b){
	for(int i =0;i < b.size;i++){
		a.num[i] -= b.num[i];
	}

	for(int i = 0;i < a.size;i++){
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
		for(int j = 0;j < b.size;j++){
			c.num[i+j] += a.num[i] * b.num[j];
		}
	}

	carry(c);
	removeHeadingZero(c);
	copy(a,c);
}

void factorial(BigInt& a, int num){
	BigInt b;
	intToBigInt(a,num);

	for(int i = num -1;i >=1;i--){
		intToBigInt(b,i);
		multiple(a,b);
	}
}

void divid(BigInt& a, BigInt& b){
	BigInt r,c,ten;
	r.size = 1;
	r.num[0] = 0;
	intToBigInt(ten, 10);

	c.size = a.size - b.size + 1;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i=a.size -1;i >=0;i--){
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

void select(BigInt& a, int total, int k){
	if(k ==0)
		intToBigInt(a,1);
	else{
		BigInt b,c;
		factorial(a,total);
		factorial(b,k);
		factorial(c,total-k);

		multiple(b,c);
		divid(a,b);
	}
}

void totalGraph(BigInt& a,int n){
	BigInt two;
	intToBigInt(two,2);
	intToBigInt(a,1);

	n = (n * (n-1))/2;
	for(int i=0;i < n;i++){
		multiple(a,two);
	}
}


void connectGraph(BigInt& a, int number){
	if(connectGraphNumber[number-1][0] != 0){
		arryToBigInt(a,number);
	}
	else{
		BigInt total,unconnect;
		BigInt partTotal,connect,selectNumber;
		intToBigInt(unconnect,0);
		for(int i = 1;i < number;i++){
			connectGraph(connect,i);
			select(selectNumber,number-1,i-1);
			totalGraph(partTotal,number-i);
			multiple(selectNumber,partTotal);
			multiple(selectNumber,connect);
			add(unconnect,selectNumber);
		}

		totalGraph(total,number);
		subtract(total,unconnect);
		BigIntToArray(total,number);
		copy(a,total);
	}
}

int main()
{
	for(int i=0;i <50;i++)
		connectGraphNumber[i][0] = 0;

	for(int i =0;i <2;i++){
		connectGraphNumber[i][0] = 1;
		connectGraphNumber[i][1] = 1;
	}

	int number;
	BigInt a;
	while(cin >> number){
		if(number == 0)
			break;
		connectGraph(a,number);
		print(a);
	}
}




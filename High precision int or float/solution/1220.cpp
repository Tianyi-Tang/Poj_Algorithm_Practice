#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct BigInt{
	int size;
	int num[10000];
};

void removeHeadZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] ==0)
		a.size --;

}

void carry(BigInt& a){
	for(int i=0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i +1 == a.size){
				a.num[i+1] = 0;
				a.size ++;
			}
			a.num[i+1] += a.num[i] /10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

bool bigger(BigInt& a, BigInt& b){
	if(a.size > b.size)
		return true;
	else if(a.size == b.size){
		for(int i=a.size -1;i >=0 ;i --){
			if(a.num[i] > b.num[i])
				return true;
			else if(a.num[i] < b.num[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;

	for(int i=0; i < a.size;i++)
		a.num[i] = b.num[i];
}

void intToBigInt(BigInt& a, int number){
	a.size =0;
	int remain;
	while(number > 0){
		remain = number % 10;
		a.num[a.size++] = remain;
		number = (number - remain) / 10;
	}
	if(a.size ==0){
		a.size = 1;
		a.num[0] = 0;
	}

}

void print(BigInt& a, int digitalA, int digitalB,string orgNumber){
	string number;
	for(int i= a.size -1; i >=0;i--){
		if(a.num[i] < 10){
			number += a.num[i] + '0';
		}
		else if(a.num[i] < 36)
			number += a.num[i] + 55;
		else
			number += a.num[i] + 61;
	}
	cout << digitalA;
	cout << " ";
	cout << orgNumber << endl;

	cout << digitalB;
	cout << " ";
	cout << number << endl;

	cout << endl;
}

int charToInt(int number){
	if(number <= 57)
		return number - '0';
	else if(number <= 90)
		return number - 55;
	else
		return number - 61;

 }

void add(BigInt& a, BigInt& b){
	int i;
	for(i=0;i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] += b.num[i];
	}

	for(int j =i;j < b.size;j++){
		a.num[j] = b.num[j];
		a.size ++;
	}
	
	carry(a);
	removeHeadZero(a);
}

void sub(BigInt& a, BigInt& b){
	for(int i=0;i < a.size;i++){
		if(i == b.size)
			break;
		a.num[i] -= b.num[i];
	}

	for(int i=0;i < a.size;i++){
		if(a.num[i] < 0){
			a.num[i +1] -= 1;
			a.num[i] += 10;
		}
	}

	removeHeadZero(a);
}

void mult(BigInt& a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;

	for(int i=0;i < c.size;i++)
		c.num[i] =0;

	for(int i =0;i < a.size;i++){
		for(int j =0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}

	carry(c);
	removeHeadZero(c);
	copy(a,c);
}

int partialDivide(BigInt& a,BigInt& b,int numberDigt){
	int number = 0;
	while(bigger(a,b)){
		if(number == numberDigt -1)
			break;
		sub(a,b);
		number ++;
	}

	return number;
}

void divide(BigInt& a, BigInt& b){
	BigInt r,c;
	r.size = 1;
	r.num[0] =0;

	c.size = a.size - b.size +1;
	for(int i=0;i < c.size;i++)
		c.num[i] = 0;

	BigInt t,ten;
	intToBigInt(ten,10);

	for(int i = a.size -1;i >=0;i--){
		mult(r, ten);
		r.num[0] = a.num[i];

		while(bigger(r,b)){
			sub(r,b);
			c.num[i] ++;
		}
	}
	removeHeadZero(c);
	copy(a,c);

}

void transitToTenDitial(string number,int digital,BigInt& a){
	BigInt b,c,d;
	intToBigInt(b,1);
	intToBigInt(d,digital);
	intToBigInt(a,0);


	for(int i=number.size()-1;i >=0;i--){
		intToBigInt(c,charToInt(number[i]));
		mult(c,b);
		add(a,c);
		mult(b,d);
	}
}

void transitToAnyDitial(BigInt& a, BigInt& b,int digital){
	BigInt c,d;
	intToBigInt(c,digital);
	intToBigInt(d,digital);

	b.size =1;
	while(bigger(a,c)){
		mult(c,d);
		b.size++;
	}
	divide(c,d);

	for(int i= b.size -1;i >=0;i--){
		b.num[i] = partialDivide(a,c,digital);
		divide(c,d);
	}
}



int main()
{
	BigInt a, b;
	int times, digitalA, digitalB;
	string number;
	cin >> times;
	for(int i=0;i < times;i++){
		cin >> digitalA;
		cin >> digitalB;
		cin >> number;
		transitToTenDitial(number,digitalA,a);
		transitToAnyDitial(a,b,digitalB);
		print(b,digitalA,digitalB,number);
	}
	
	return 0;
}



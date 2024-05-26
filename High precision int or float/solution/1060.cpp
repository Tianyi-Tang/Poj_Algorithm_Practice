#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigNum
{
	int degree;
	int num[2000];
};

void stringToBigNum(BigNum& a){
	int degree;
	cin >> degree;
	a.degree = degree;

	int index;
	for(int i= degree -1; i >=0;i--){
		cin >> index;
		a.num[i] = index;
	}
}

void pirntBigNum(BigNum& a){
	cout << a.degree;
	for(int i= a.degree -1;i >=0;i--){
		cout << " ";
		cout << a.num[i];
	}
	cout << endl;
}

void intToBigNum(BigNum& a, int power){
	a.degree = power+1;
	a.num[a.degree-1] = 1;
	for(int i=0;i < a.degree-1;i++)
		a.num[i] = 0; 
}

void modeTwo(BigNum& a){
	for(int i=0;i < a.degree;i++)
		a.num[i] = a.num[i] % 2;
}

bool bigger(BigNum& a, BigNum& b){
	if(a.degree > b.degree)
		return true;
	else if(a.degree == b.degree){
		for(int i=a.degree-1;i >=0;i++){
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

void copy(BigNum& a,BigNum& b){
	a.degree = b.degree;
	for(int i=0;i < b.degree;i++)
		a.num[i] = b.num[i];
}

void ignoreZero(BigNum& a){
	while(a.degree !=0 && a.num[a.degree-1] ==0)
		a.degree -=1;
}

void mult(BigNum& a, BigNum& b){
	BigNum c;
	c.degree = a.degree + b.degree;
	if(a.degree > 0 && b.degree > 0)
		c.degree -= 1;

	for(int i=0;i < c.degree;i++)
		c.num[i] = 0;

	for(int i=0;i < a.degree;i++){
		for(int j=0;j < b.degree;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}
	modeTwo(c);
	copy(a,c);
	
}

void mode(BigNum& a, BigNum& b){
	while(bigger(a,b)){
		BigNum c;
		intToBigNum(c, a.degree - b.degree);
		mult(c,b);
		for(int i=0;i < c.degree;i++)
			a.num[i] += c.num[i];
		modeTwo(a);
		ignoreZero(a);
	}
}



int main(){
	int times;
	cin >> times;

	for(int i=0;i < times;i++){
		BigNum a,b ,c;
		stringToBigNum(a);
		stringToBigNum(b);
		mult(a,b);

		stringToBigNum(c);

		
		mode(a,c);
		pirntBigNum(a);
	}


	return 0;
}

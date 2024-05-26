#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigFloat{
	int size;
	int floatNum;
	int num[1000];
};

void removeTailZero(BigFloat& a){
	while(a.floatNum != -1 && a.num[0] == 0){	
		for(int i=0;i < a.size;i++)
			a.num[i] = a.num[i+1];
		a.size -= 1;
		a.floatNum -=1;
	}
}

void stringToBigFloat(BigFloat& a, string number){
	a.floatNum = -1;
	a.size = -1;
	for(int i= number.size()-1;i >=0;i--){
		if(number[i] == '.'){
			a.floatNum = a.size;
			continue;
		}
		a.size += 1;
		a.num[a.size] = number[i] - '0';
	}
	removeTailZero(a);
}

void carry(BigFloat& a){
	for(int i=0; i <= a.size;i++){
		if(a.num[i] >= 10){
			if(i+1 > a.size){
				a.size += 1;
				a.num[i+1] = 0;
			}
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void copy(BigFloat& a, BigFloat& b){
	a.size = b.size;
	a.floatNum = b.floatNum;

	for(int i=0;i <= b.size;i++)
		a.num[i] = b.num[i];
}



void mult(BigFloat& a, BigFloat& b){
	BigFloat c;
	c.size = a.size + b.size;
	if(a.floatNum != -1 && b.floatNum != -1)
		c.floatNum = a.floatNum + b.floatNum +1;
	else if(a.floatNum != -1)
		c.floatNum = a.floatNum;
	else if(b.floatNum != -1)
		c.floatNum = b.floatNum;
	else
		c.floatNum = -1;

	for(int i=0;i <= c.size;i++)
		c.num[i] = 0;

	for(int i =0; i <= a.size;i++){
		for(int j=0;j <= b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}

	carry(c);
	copy(a,c);
}

void power(BigFloat& a, int number){
	BigFloat b;
	copy(b,a);

	for(int i=0;i < number-1;i++){
		mult(a,b);
	}

	removeTailZero(a);
}


string print(BigFloat& a){
	string number;
	for(int i = a.size;i >=0 ;i--){
		if(i == a.floatNum)
			number += '.';
		number += '0' + a.num[i];
	}
	while(number[0] == '0' && number.size() > 1)
		number.erase(0,1);

	return number;
}

int main()
{
	
	string R;
	int n;
	while(cin>>R>>n){
		BigFloat a;
		stringToBigFloat(a,R);
		power(a,n);
		cout << print(a) << endl;
	}

	return 0;
}
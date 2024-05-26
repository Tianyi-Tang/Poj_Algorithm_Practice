#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigFloat{
	int size;
	int floatPoint;
	int num[10000];
};

void stringToBigFloat(BigFloat& a, string number){
	a.size = 0;
	a.floatPoint = -1;
	for(int i =number.size() -1;i >=0;i--){
		if(number[i] == '.'){
			a.floatPoint = a.size -1;
			continue;
		}
		a.num[a.size] = number[i] - '0';
		a.size ++;
	}

}

void print(BigFloat& a, BigFloat& b){
	string numberA, numberB;
	for(int i= a.size -1;i >=0;i--){
		if(i == a.floatPoint && a.size != 1)
			numberA += '.';
		numberA += a.num[i] + '0';
	}

	for(int i= b.size -1;i >=0;i--){
		if(i == b.floatPoint && b.size != 1)
			numberB += '.';
		numberB += b.num[i] + '0';
	}

	cout << numberA;
	cout << " [8] = ";
	cout << numberB;
	cout << " [10]" << endl;
	
}

void copy(BigFloat& a, BigFloat& b){
	a.size = b.size;
	a.floatPoint = b.floatPoint;

	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void carry(BigFloat& a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i == a.size-1){
				a.size +=1;
				a.num[i+1] = 0;
			}
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void removeTailZero(BigFloat& a){
	while(a.num[0] == 0 && a.size > 1){
		for(int i=0;i < a.size;i++)
			a.num[i] = a.num[i+1]; 
		a.size -=1;
		a.floatPoint -=1;
	}
}

void removeHeadZero(BigFloat& a){
	while(a.num[a.size -1] ==0 && a.floatPoint+1 != a.size -1)
		a.size --;
}

bool bigger(BigFloat& a, BigFloat& b){
	if(a.size - a.floatPoint -1 > b.size - b.floatPoint - 1)
		return true;
	else if(a.size - a.floatPoint -1 == b.size - b.floatPoint - 1){
		int a_degree = a.size -1;
		int b_degree = b.size -1;
		for(int i = a.size -1;i >=0;i--){
			if(b_degree < 0)
				return true;
			else if(a.num[a_degree] > b.num[b_degree])
				return true;
			else if(a.num[a_degree] <b.num[b_degree])
				return false;
			a_degree --;
			b_degree --;
		}
		if(b_degree >= 0)
			return false;
		else
			return true;
	}
	else
		return false;
}

void add(BigFloat& a, BigFloat& b){
	BigFloat c;
	c.size = a.size;
	c.floatPoint = a.floatPoint;	

	for(int i=0;i  < c.size;i++)
		c.num[i] = a.num[i] + b.num[i];

	carry(c);
	copy(a,c);
}

void subtract(BigFloat& a, BigFloat& b){
	BigFloat c;
	c.size = a.size;
	c.floatPoint = a.floatPoint;

	int c_degree = 0;
	if(c.floatPoint == -1 && b.floatPoint != -1){
		c.floatPoint = b.floatPoint;
		c_degree = c.floatPoint +1;
		c.size += c_degree;
	}
	else if(c.floatPoint != -1 && c.floatPoint < b.floatPoint){
		c_degree = b.floatPoint - c.floatPoint;
		c.floatPoint += c_degree;
		c.size += c_degree; 
	}

	for(int i=0;i < c_degree;i++)
		c.num[i] = 0;

	int a_degree = 0;
	for(int i = c_degree;i < c.size;i++)
		c.num[i] = a.num[a_degree ++];

	for(int i =0;i < c.size;i++)
		c.num[i] -= b.num[i];
	
	for(int i = 0;i < c.size;i++){
		if(c.num[i] < 0){
			c.num[i + 1] -= 1;
			c.num[i] += 10;
		}
	}
	removeTailZero(c);
	copy(a,c);
} 

void mult(BigFloat& a, BigFloat& b){
	BigFloat c;
	c.size = a.size + b.size -1;

	if(a.floatPoint == -1 && b.floatPoint == -1)
		c.floatPoint = -1;
	else if(a.floatPoint == -1)
		c.floatPoint = b.floatPoint;
	else if(b.floatPoint == -1)
		c.floatPoint = a.floatPoint;
	else
		c.floatPoint = a.floatPoint + b.floatPoint + 1;

	for(int i=0;i < c.size;i++)
		c.num[i] = 0;

	for(int i=0;i < a.size;i++){
		for(int j =0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}

	carry(c);
	removeTailZero(c);
	removeHeadZero(c);
	copy(a,c);
}

void divide(BigFloat& a, BigFloat& b,int times){
	string number;
	int num;
	BigFloat zeroPoint1, copyB;
	stringToBigFloat(zeroPoint1, "0.1");
	copy(copyB,b);
	for(int i =0;i < times* 3+1;i++){

		num = 0;
		if(i == 1)
			number += '.';

		while(bigger(a,b)){
			subtract(a,b);
			num ++;
		}
		mult(b,zeroPoint1);
		number += num + '0';
	}
	stringToBigFloat(a,number);
	copy(b,copyB);
}

int main(){
	string input;
	BigFloat a,b,c,d,eight;
	while(cin >> input){
		string number = "0.";
		stringToBigFloat(a,input);
		stringToBigFloat(b, "1");
		stringToBigFloat(eight, "8");
		int size = a.size -1;
		for(int i =0;i < size*3;i++)
			number += '0';
		stringToBigFloat(d, number);
		for(int i =a.size-2;i >= 0;i--){
			number = a.num[i] + '0';
			stringToBigFloat(c,number);
			mult(b,eight);
			divide(c,b,size);
			add(d,c);
		}
		removeTailZero(d);
		print(a,d);
	}
	
	

	return 0;
}


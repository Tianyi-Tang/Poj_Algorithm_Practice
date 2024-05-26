#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[1050];
};

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] == 0)
		a.size --;
}

void print(BigInt& a){
	string number;
	for(int i= a.size -1;i >=0;i--)
		number += a.num[i] + '0';
	cout << number << endl;
}


void stringToBigInt(BigInt& a,string number){
	a.size = 0;
	for(int i = number.length() - 1;i >= 0;i--)
		a.num[a.size ++] = number[i] - '0';
	removeHeadingZero(a);
}

void intBitToBigInt(BigInt& a, int number){
	a.size = 1;
	a.num[0] = number;
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

bool equalToDigital(BigInt& a,int digital){
	if(a.size == 1 && a.num[0] == digital)
		return true;
	else
		return false;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
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
		for(int j = 0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}
	carry(c);
	removeHeadingZero(c);
	copy(a,c);
}

bool divid(BigInt& a, BigInt& b){
	BigInt remain,ten,c;
	stringToBigInt(remain,"0");
	stringToBigInt(ten,"10");

	c.size = a.size - b.size +1;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i = a.size -1; i >=0;i--){
		multiple(remain,ten);
		remain.num[0] = a.num[i];

		while(bigger(remain,b)){
			subtract(remain,b);
			c.num[i] ++;
		}
	}

	if(equalToDigital(remain,0
		)){
		removeHeadingZero(c);
		copy(a,c);
		return true;
	}
	else
		return false;
}

string persistence(string number){
	string output;
	BigInt num,divisor,temp;
	if(number.length() == 1){
		output = "1";
		output += number[0];
		return output;
	}

	stringToBigInt(num,number);
	temp.size = 0;

	bool flag;
	while(!equalToDigital(num,1)){
		flag = false;
		for(int i = 9;i >=2;i--){
			intBitToBigInt(divisor,i);
			flag = divid(num,divisor);
			if(flag == true)
				break;
		}
		if(flag == false)
			return "There is no such number.";
		else
			temp.num[temp.size++] = divisor.num[0];
	}

	for(int i =temp.size -1;i >=0;i--)
		output += temp.num[i] + '0';
	return output;
}

int main()
{
	string number;
	while(cin >> number){
		if(number == "-1")
			break;
		cout << persistence(number) << endl;
	}

	return 0;
}






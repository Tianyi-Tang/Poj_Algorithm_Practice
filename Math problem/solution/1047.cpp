#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

string input;
int zeroNum;

struct BigInt{
	int size;
	int num[150];
};

void findZeroNum(){
	zeroNum = 0;
	for(int i = 0;i < input.length();i++){
		if(input[i] != '0')
			break;
		zeroNum ++;
	}
}

void removeHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size-1] == 0)
		a.size --;
}


void removeZero(BigInt& a){
	for(int i =0;i < zeroNum;i++){
		if(a.num[a.size-1] == 0)
			a.size --;
	}
}

void stringToBigInt(BigInt& a, string number){
	a.size = 0;
	for(int i = number.length() -1;i >=0;i--)
		a.num[a.size++] = number[i] - '0';
}

void intToBigInt(BigInt& a, int number){
	a.size = 0;
	while(number != 0){
		a.num[a.size++] = number % 10;
		number = number / 10;
	}
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

void print(BigInt& a){
	string number;
	for(int i = a.size -1;i >=0;i--)
		number += a.num[i] + '0';
	cout << number << endl;
}

void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

void multiple(BigInt& a, BigInt& b,BigInt& c){
	c.size = a.size + b.size;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i =0;i < a.size;i++){
		for(int j =0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}
	carry(c);

	if(zeroNum != 0){
		if(b.size == 2 && b.num[0] == 1 && b.num[1] == 1 && zeroNum != 0)
			zeroNum ++;

		if(!(b.size == 1 && b.num[0] == 1) && b.size)
			removeZero(c);
	}
	else{
		removeHeadingZero(c);
	}

}

bool cyclic(BigInt& a){
	bool same;
	int existNumber;

	for(int i = a.size -1;i >=0;i--){;
		existNumber = 0;
		same = true;
		for(int j = 0;j < input.length();j++){
			if(i-j < 0 && existNumber == 0)
				existNumber = a.size;
			if(input[j] - '0' != a.num[i-j+existNumber]){
				same = false;
				break;
			}
		}
		if(same)
			return true;
	}
	return false;
}

void result(bool same){
	cout << input << " is ";
	if(same)
		cout << "cyclic" << endl;
	else
		cout << "not cyclic" << endl;
}

int main()
{
	BigInt a, b, c;
	int size;
	bool same;
	while(cin >> input){
		same = true;
		size = input.length();
		stringToBigInt(a,input);
		findZeroNum();
		for(int i =1;i<= size;i++){
			intToBigInt(b,i);
			multiple(a,b,c);
			if(!cyclic(c)){
				same = false;
				break;
			}
		}
		result(same);
	}

	return 0;
}


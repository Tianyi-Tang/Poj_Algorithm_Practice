#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

long long divisorNum;
long long remain;

void convert_divisor(string number,int base){
	long long multiper = 1;
	divisorNum = 0;

	for(int i = number.length() -1;i >=0;i--){
		divisorNum += (multiper * (number[i] - '0'));
		multiper *= base;
	}
}

void convert_remain(int base){
	string number;
	int digtal,size = 0;
	long long multiper =1 ;

	while(remain >= multiper){
		multiper *= base;
		size ++;
	}
	multiper = multiper / base;

	for(int i =0;i < size;i++){
		digtal = 0;
		while(remain >= multiper){
			remain -= multiper;
			digtal ++;
		}
		number += digtal + '0';
		multiper = multiper / base;
	}

	if(number == "")
		number = "0";

	cout << number << endl;
}

void findRemain(string dividend,string divisor,int base){
	remain = 0;
	convert_divisor(divisor,base);

	for(int i = 0;i < dividend.length();i++){
		remain = (remain * base + (dividend[i] -'0'))% divisorNum;
	}

	convert_remain(base);
}



int main()
{
	int base;
	string dividend,divisor;
	while(cin >> base){
		if(base == 0)
			break;
		cin >> dividend;
		cin >> divisor;
		findRemain(dividend,divisor,base);
	}
	return 0;
}
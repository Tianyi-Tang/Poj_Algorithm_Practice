#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int N = 1000000;
int k[34]; int ksize = 0;
int primeNums[80000];
int size = 0;
bool number[1000000];


void inital(){
	for(int i=0;i < sizeof(number);i++)
		number[i] = true;
}

void findPrime(){
	for(int i =2; (long) i * i <= N;i++){
		if(number[i-1]){
			for(long j = i * i;j <= N;j += i)
				number[j-1] = false;
			primeNums[size++] = i;
		}
	}

	for(int i = 1000;i < sizeof(number);i++){
		if(number[i]){
			primeNums[size] = i +1;
			size += 1;
		}
	}

}

void convert(string number){
	ksize = 0;
	int i;
	for(i = number.length() -1;i -3 >= -1;i -= 3){
		k[ksize++] = (number[i] - '0') + (number[i -1] - '0') * 10 + (number[i-2] -'0')* 100;
	}

	int num = 0;
	for(int j = 0;j <= i;j++){
		num *= 10;
		num += number[j] -'0';
	}
	if(i != -1)
		k[ksize++] = num;
}

void goodNum(int minNum){
	int digital = 0;
	int prime = primeNums[digital];
	unsigned long remain = 0;

	while(prime < minNum && digital < size){
		for(int i = ksize -1;i >=0;i--){
			remain = (remain * 1000 + k[i]) % prime;
		}

		if(remain == 0)
			break;
		digital ++;
		prime = primeNums[digital];
		remain = 0;
	}

	
	if(digital < size && prime < minNum)
		cout << "BAD " << prime << endl;
	else
		cout << "GOOD" << endl;
}

int main()
{
	inital();
	findPrime();
	string number;
	int minNum;
	while(cin >> number){
		cin >> minNum;
		if(number.length() ==1 && number[0] == '0' && minNum == 0)
			break;
		convert(number);
		goodNum(minNum);
	}
	return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[120];
};

void stringToBigInt(BigInt& a,string number){
	a.size =0;
	for(int i = number.length() -1;i >=0;i--)
		a.num[a.size++] = number[i] - '0';
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

void copy(BigInt& a,BigInt& b){
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

void add(BigInt& a, BigInt& b,BigInt& c){
	copy(c,a);
	for(int i = a.size;i < b.size;i++)
		a.num[a.size++] = 0;

	for(int i =0;i < b.size;i++){
		a.num[i] += b.num[i];
	}
	carry(a);
	copy(b,c);
}

void counter(string samllest,string biggest){
	int count = 0;
	BigInt fib1,fib2,temp,samllNum,bigNum;
	stringToBigInt(fib1,"1");
	stringToBigInt(fib2,"1");
	stringToBigInt(samllNum,samllest);
	stringToBigInt(bigNum,biggest);
	
	while(!bigger(fib1,samllNum))
		add(fib1,fib2,temp);

	while(bigger(bigNum,fib1)){
		count ++;
		add(fib1,fib2,temp);
	}

	cout << count << endl;
}

int main()
{
	string samllest,biggest;
	while(cin >> samllest){
		cin >> biggest;
		if(samllest  == "0" && biggest == "0")
			break;
		counter(samllest,biggest);
	}
	return 0;
}




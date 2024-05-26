#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct BigInt{
	int size;
	int num[500];
};

void intToBigInt(BigInt & a,int number){
	a.size = 0;
	while(number !=0){
		a.num[a.size++] = number % 10;
		number = number / 10;
	}

	if(a.size ==0){
		a.size = 1;
		a.num[0] = 0;
	}
}

void removingHeadingZero(BigInt& a){
	while(a.size >= 2 && a.num[a.size -1] ==0)
		a.size --;
}


void result(int n, int m, BigInt & a){
	cout << n << " things taken " << m << " at a time is ";
	for(int i = a.size -1;i >= 0;i--)
		cout << a.num[i];
	cout << " exactly." << endl;
}



void copy(BigInt& a, BigInt& b){
	a.size = b.size;
	for(int i =0;i < a.size;i++)
		a.num[i] = b.num[i];
}

bool bigger(BigInt& a, BigInt& b){
	if(a.size > b.size)
		return true;
	else if( a.size < b.size)
		return false;
	else{
		for(int i = a.size -1;i >=0;i--){
			if(a.num[i] < b.num[i])
				return false;
			else if(a.num[i] > b.num[i])
				return true;
		}
		return true;
	}
}

void carry(BigInt & a){
	for(int i =0;i < a.size;i++){
		if(a.num[i] >= 10){
			if(i == a.size -1)
				a.num[a.size++] = 0;
			a.num[i+1] += a.num[i] / 10;
			a.num[i] = a.num[i] % 10;
		}
	}
}

void multiple(BigInt & a, BigInt& b){
	BigInt c;
	c.size = a.size + b.size;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i =0;i < a.size;i++){
		for(int j =0;j < b.size;j++)
			c.num[i+j] += a.num[i] * b.num[j];
	}
	carry(c);
	removingHeadingZero(c);
	copy(a,c);
}

void subtract(BigInt& a, BigInt& b){
	for(int i =0;i < b.size;i++)
		a.num[i] -= b.num[i];

	for(int i =0;i< a.size;i++){
		if(a.num[i] < 0){
			a.num[i+1] -= 1;
			a.num[i] += 10;
		}
	}
	removingHeadingZero(a);
}

void divid(BigInt& a, BigInt& b, BigInt& c){
	BigInt remain,ten;
	intToBigInt(ten,10);
	intToBigInt(remain,0);

	c.size = a.size - b.size +1;
	for(int i =0;i < c.size;i++)
		c.num[i] = 0;

	for(int i = a.size -1;i >=0;i--){
		multiple(remain,ten);
		remain.num[0] = a.num[i];

		while(bigger(remain,b)){
			subtract(remain,b);
			c.num[i]++;
		}
	}
	removingHeadingZero(c);
}


void choseNumber(int N, int M){
	int storeM = M;
	if(N /2 < M)
		M = N - M;

	BigInt a, b,temp;
	intToBigInt(a,1);
	intToBigInt(b,1);

	for(int i = N;i > N - M;i--){
		intToBigInt(temp,i);
		multiple(a,temp);
	}

	for(int i = 2;i <= M;i++){
		intToBigInt(temp,i);
		multiple(b,temp);
	}

	divid(a,b,temp);
	result(N,storeM,temp);
}

int main()
{
	int N,M;
	while(cin >> N){
		cin >> M;
		if(N == 0 && M == 0)
			break;
		choseNumber(N,M);
	}
	return 0;
}









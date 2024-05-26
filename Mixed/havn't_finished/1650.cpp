#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	double A,approximateValue,limit;
	int L,n,d;
	bool swaping;

	swaping = false;
	A = 0.14159265358979;
	if(A < 1){
		A = 1 / A;
		swaping = true;
	}

	L = 100000;
	limit = 1 / (L * 10.0);

	d = 1;
	n = A * d;

	approximateValue = n/(d * 1.0);
	while(abs(approximateValue - A) > limit){
		if(approximateValue < A)
			n++;
		else if(approximateValue > A)
			d++;
		approximateValue =  n/(d * 1.0);
	}

	if(swaping)
		swap(n,d);
	

	return 0;
}
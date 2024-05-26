#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

long long t,p,gcd;

long long Mod(long long a, int b){
	if(a > 0)
		return a % b;
	else
		return abs(b) + (a % b);

}

void extend_Eulid(long a , long b){
	if(b ==0){
		t = 1;
		p = 0;
		gcd = a;
	}
	else{
		extend_Eulid(b,a%b);
		int temp = t;
		t = p;
		p = temp - (a / b) * p;
	}
}

int main()
{

	long x,y,m,n,L,a,d,L1;
	while(scanf("%ld %ld %ld %ld %ld",&x,&y,&m,&n,&L) != EOF){
		a = n - m;
		d = x - y;

		if(x % L == y % L){
			cout << "x % L =" << x % L << "; y % L =" << y % L << endl;
			cout << 0 << endl;
			continue;
		}

		if(a < L){
			extend_Eulid(L,a);
			swap(t,p);
		}
		else
			extend_Eulid(a,L);

		if(d % gcd != 0)
		 	cout << "Impossible" << endl;
		else
		{
			L1= L/gcd;
			if(L1  < 0)
				L1 *= -1;
			t = L1+ Mod( (long long) t * d/gcd, L1);
			t = Mod(t, L1);
			if(t == 0)
				t = L1;
			cout << t << endl;
		}
	}

	return 0;
}
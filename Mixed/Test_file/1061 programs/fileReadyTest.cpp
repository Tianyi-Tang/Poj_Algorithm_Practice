#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

long t,p,gcd;


int Mod(int a, int b){
	if(a > 0)
		return a % b;
	else
		return abs(b) + (a % b);

}

void extend_Eulid(int a , int b){
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
	ifstream inputfile("input.txt");
	ofstream outputfile("output.txt");
	int x,y,m,n,L,a,d,L1;
	while(inputfile >> x >> y >> m >> n >> L){
		a = n - m;
		d = x - y;

		if(x % L == y % L){
			outputfile << 0 << "\n";
			continue;
		}


		if(a < L){
			extend_Eulid(L,a);
			swap(t,p);
		}
		else
			extend_Eulid(a,L);
		if(d % gcd != 0)
			outputfile << "Impossible\n";
		else{
			L1= abs(L/gcd);
			t = L1+ Mod(t * d/gcd, L1);
			t = Mod(t, L1);
			if(t == 0)
				t = L1;
			outputfile << t << "\n";
		}
	}
	inputfile.close();
	outputfile.close();


	return 0;
}
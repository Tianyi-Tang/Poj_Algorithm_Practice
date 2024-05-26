#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int a, b;

int GCD(int x,int y){
	int t;
	if(x < y)
		swap(x,y);
	while(y){
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}


int main()
{
	int p,q,gcd,max,prevP,prevQ;
	while(cin >> a){
		cin >> b;
		gcd = GCD(a,b);
		a = a / gcd;
		b = b / gcd;
		q = 1;
		prevP = prevQ = 0;
		while(q!= b){
			p = (double) (a * q) / (double) b + 0.5;
			if(prevP == 0 && prevQ == 0){
				prevP = p;
				prevQ = q;
				cout << p << "/" << q << endl;
			}
			else if(prevQ * abs(a*q - b*p) < q * abs(a*prevQ - b*prevP)){
				prevP = p;
				prevQ = q;
				cout << p << "/" << q << endl;
			}
			q++;
		}
		p = (double) (a * q) / (double) b + 0.5;
		cout << p << "/" << q << endl;
		cout << endl;
	}
	return 0;
}


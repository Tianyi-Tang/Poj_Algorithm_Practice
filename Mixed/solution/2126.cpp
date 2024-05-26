#include <iostream>
#include <cstring>
#include <cstdlib>
#include <math.h>
using namespace std;

#define twoDegree 3

int ai[twoDegree];

int main()
{
	int degree,value,result;
	bool isIrreducible;
	while(cin >> degree){
		for(int i =0;i <= degree;i++){
			cin >> value;
			if(degree == 2)
				ai[i] = value;
		}

		if(degree == 2){
			value = ai[1];
			result = pow(value,2) - 4 * ai[0] * ai[2];
			if(result >= 0 && ai[0] != 0)
				isIrreducible = false;
			else
				isIrreducible = true;
		}
		else if(degree < 2)
			isIrreducible = true;
		else
			isIrreducible = false;

		if(isIrreducible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
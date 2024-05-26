#include <iostream>
#include <cstring>
#include <cstdlib>
#include <math.h>
using namespace std;

#define minDifferent 1e-9

int main()
{
	double A,value,different;
	int n,d,L,finalN,finalD;

	while(cin >> A >> L){
		different = 50000;
		d = finalD = 1;
		n = finalN = 1;

		while(d <= L  && n <= L){
			value = (double) n / d - A;
			if(fabs(value) < minDifferent){
				finalD = d;
				finalN = n;
				break;
			}
			if(fabs(value) < different){
				finalN = n;
				finalD = d;
				different = fabs(value);
			}
			if(value < 0)
				n++;
			else 
				d ++;
		}

		cout << finalN << " " << finalD << endl;
	}
	return 0;
}
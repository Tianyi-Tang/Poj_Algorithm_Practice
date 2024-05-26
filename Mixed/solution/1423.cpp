#include <iostream>
#include <cstring>
#include <cstdlib>
#include <math.h>
using namespace std;



int main()
{
	int n,num,digital;
	cin >> n;
	for(int i =0;i < n;i++){
		cin >> num;
		if(num == 1){
			cout << 1 << endl;
			continue;
		}
		digital = log10(sqrt(2*acos(-1.0)*num))+num*log10(num/exp(1.0))+1; 
		cout << digital << endl;
	}
	return 0;
}

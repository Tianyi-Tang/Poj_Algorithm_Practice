#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


int main()
{
	long long sum,different,a,b,n;

	cin >> n;

	for(int i =0;i < n;i++){
		cin >> sum >> different;

		if(sum < different || (sum + different)%2 != 0){
			cout << "impossible" << endl;
			continue;
		}

		a = (sum + different) /2;
		b = sum - a;

		cout << a << " " << b << endl;
	}

	


	return 0;
}
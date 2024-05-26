#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



int main()
{
	int n,num,counter;
	cin >> n;
	for(int i =0;i < n;i++){
		cin >> num;
		counter = 0;
		while(num / 5 != 0){
			num = num /5;
			counter += num;
		}
		cout << counter << endl;
	}
	return 0;
}
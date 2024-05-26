#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

bool allNumber[3012501];
int m;
int series[500001];

void findNumber(int number){
	if(number < m)
		return;

	int temp;
	while(number >= m){
		temp = series[m-1] - m;
		if(temp <= 0 || allNumber[temp]){
			temp = series[m-1] + m;
		}
		allNumber[temp] = true;
		series[m] = temp;
		m++;
	}
}

int main()
{
	series[0] = 0;
	m = 1;

	int number;
	while(cin >> number){
		if(number == -1)
			break;
		findNumber(number);
		cout << series[number] << endl;
	}
	return 0;
}
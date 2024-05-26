#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define patternLength 45

long pattern[45];
int counter;

void inital(){
	for(int i = 2;i < patternLength;i++)
		pattern[i] = 0;
	pattern[0] = 2;
	pattern[1] = 3;
}

long findNumber(int number){
	if(pattern[number -1] !=0)
		return pattern[number-1];
	else{
		long num = findNumber(number-1);
		num += findNumber(number-2);
		pattern[number-1] = num;
		return num;
	}
}

void result(long number){
	cout << "Scenario #" << counter << ":" << endl;
	cout << number << endl;
	cout << endl;
}


int main()
{
	inital();
	int n,number;
	long value;
	cin >> n;
	counter = 1;
	for(int i =0;i < n;i++){
		cin >> number;
		value = findNumber(number);
		result(value);
		counter ++;
	}
	return 0;
}


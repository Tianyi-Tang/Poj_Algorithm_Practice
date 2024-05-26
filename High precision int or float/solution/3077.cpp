#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string roundUp(string number){
	string num;
	int highest;
	int start = 0;

	if(start == number.length() -1){
		num += number[start];
		return num;
	}

	highest = number[start] - '0';
	bool flag = false;
	for(int i = start +1;i < number.length();i++){
		if(number[i] - '0' < 4)
			break;
		else if(number[i] - '0' >=5){
			flag = true;
			break;
		}
	}

	if(flag == true)
		highest += 1;

	if(highest == 10){
		num += '1';
		highest = 0;
	}
	num += highest + '0';

	for(int i = start+1;i < number.length();i++)
		num += '0';

	return num;
} 

int main(int argc, char const *argv[])
{
	string number,num;
	int times;
	cin >> times;
	for(int i =0;i < times;i++){
		cin >> number;
		num = roundUp(number);
		cout << num << endl;
	}
	return 0;
}
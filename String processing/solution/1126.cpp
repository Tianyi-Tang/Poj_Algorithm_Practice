#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;



bool validChar(char a){
	if(a >= 'p' && a <= 'z')
		return true;
	else
		return false;
}


bool correctHedonianStr(string input){
	int strLength = input.length();
	int counter = 0;
	for(int i = strLength -1;i >= 0;i--){
		if(input[i] == 'C' || input[i] == 'D' || input[i] == 'E' || input[i] == 'I'){
			if(i + 2 >= strLength)
				return false;
			else
				counter -= 1;
		}
		else if(input[i] == 'N'){
			if(i +1 >= strLength)
				return false;
		}
		else if(!validChar(input[i]))
			return false;
		else
			counter ++;
	}

	if(counter == 1)
		return true;
	else
		return false;
}

int main()
{
	string input;
	while(cin >> input){
		if(correctHedonianStr(input))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
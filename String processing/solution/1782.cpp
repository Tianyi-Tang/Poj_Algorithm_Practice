#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

char currentChar;
bool preApperOnce;
int counter;
string result;

void addResult(char newC){
	if(preApperOnce && counter > 1){
		result += '1';
		preApperOnce = false;
	}
	
	
	while(counter > 9){
		result += '9';
		result += currentChar;
		counter -= 9;
	}
	

	if(counter > 1){
		result += counter + '0';
		result += currentChar;
	}
	else{
		if(!preApperOnce){
			result += '1';
			preApperOnce = true;
		}

		if(currentChar == '1')
			result += "11";
		else{
			result += currentChar;
		}
	}

	if(newC == '\0' && preApperOnce)
		result += '1';

	currentChar = newC;
	counter = 1;
}

int main()
{
	string input;

	while(getline(cin,input)){
		result = "";
		preApperOnce  = false;

		if(input.length() == 0){
			cout << endl;
			continue;
		}
		
		currentChar = input[0];
		counter = 1;
		for(int i =1;i < input.length();i++){
			if(currentChar != input[i])
				addResult(input[i]);
			else
				counter ++;
		}
		addResult('\0');
		cout << result << endl;
	}

	return 0;
}
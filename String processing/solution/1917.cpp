#include<cstring>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
using namespace std;

int changeIndex,unChangIndex;
string changStr[2],unChangeStr[2];


int main()
{
	int testCase,start;
	string input,completInput,answer,completAnswer;
	bool unchangeAppear;

	cin >> testCase;
	getchar();
	while(testCase){
		changeIndex = unChangIndex = 0;
		completAnswer = completInput = "";
		unchangeAppear = false;
		
		getline(cin,input);
		for(int i =0;i < input.length();i++){
			if(input[i] == '<' && unchangeAppear){
				unChangeStr[unChangIndex++] = input.substr(start,i-start);
				unchangeAppear = false;
			}

			if(input[i] == '<'){
				start = i+1;
				continue;
			}
			else if(input[i] == '>'){
				if(start != i)
					changStr[changeIndex++] = input.substr(start,i-start);
				else
					changStr[changeIndex++] = "";
				unchangeAppear = true;
				start = i +1;
				continue;
			}
			
			completInput += input[i];
		}
		if(start != input.length())
			unChangeStr[unChangIndex++] = input.substr(start,input.length() - start);
		else
			unChangeStr[unChangIndex++] = "";

		getline(cin,answer);
		
		completAnswer = answer.substr(0,answer.length()-3);

		completAnswer += changStr[1] + unChangeStr[0];
		completAnswer += changStr[0] + unChangeStr[1];

		cout << completInput << endl;
		cout << completAnswer << endl;

		testCase --;
	}


	return 0;
}

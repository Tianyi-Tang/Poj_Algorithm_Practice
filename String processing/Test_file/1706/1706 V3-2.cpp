#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stdio.h>
using namespace std;

#define maxReferNum 1000

int apperRef[maxReferNum] = {0},referOrder[maxReferNum] = {0},correctOrder;
string allRef[maxReferNum][4];
string input;

bool isBlank(string str){
	for(int i =0;i < str.length();i++){
		if(str[i] != ' ')
			return false;
	}
	return true;
}

void executeNormal(){
	int referNum;
	bool appearNum = false;
	for(int i =0;i < input.length();i++){
		if(appearNum && input[i] == ']'){
			appearNum = false;
			if(apperRef[referNum] == 0){
				cout << correctOrder;
				apperRef[referNum] = correctOrder;
				referOrder[correctOrder++] = referNum;
			}
			else
				cout << apperRef[referNum];
		}
		else if(appearNum){
			referNum = referNum * 10 + input[i] - '0';
			continue;
		}
		else if(input[i] == '['){
			referNum = 0;
			appearNum = true;
		}
		cout << input[i];
	}
	cout << endl;
}

void getALlInput(){
	bool testFlage = false;
	int referNum, n;
	while(getline(cin,input)){
		if(isBlank(input))
			continue;
		else if(input[0] == '['){
			referNum = input[1] - '0';
			n = 0;
			for(int i =2;i < input.length() && input[i] != ']';i++)
				referNum = referNum * 10 + input[i] - '0';

			if(input[1] == '2'){
				testFlage = true;
			}

			allRef[referNum][n++] = input;
			while(getline(cin,input)){
				if(isBlank(input) || allRef[referNum][n-1] == input)
					break;
				allRef[referNum][n++] = input;
			}
		}
		else{
			executeNormal();
			while(getline(cin,input)){
				if(isBlank(input))
					break;
				executeNormal();
			}
			cout << endl;
		}
	}
}

void ouput(){
	bool afterRef;
	for(int i =1;i < correctOrder;i++){
		cout << "[" << i << "]";
		afterRef = false;
		for(int j =0;j < allRef[referOrder[i]][0].length();j++){
			if(afterRef)
				cout << allRef[referOrder[i]][0][j];
			else if(allRef[referOrder[i]][0][j] == ']')
				afterRef = true;
		}
		cout << endl;
		for(int j = 1;j < 4 && !isBlank(allRef[referOrder[i]][j]);j++)
			cout << allRef[referOrder[i]][j];
		cout << endl;
		cout << endl;
	}
}

int main()
{
	correctOrder = 1;
	// freopen("input.txt","r",stdin);
	getALlInput();
	ouput();


	return 0;
}

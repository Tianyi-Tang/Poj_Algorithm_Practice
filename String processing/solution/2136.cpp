#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int character[26] = {0},maxNum;

void printSpace(int num){
	for(int i =0;i < num;i++)
		cout << " ";
}

int main()
{
	string input;
	int spaceNum;
	char a = 'A';

	maxNum = 0;
	for(int i =0;i < 4;i++){
		getline(cin,input);
		for(int j =0;j < input.length();j++){
			if(input[j] >= 'A' && input[j] <= 'Z'){
				character[input[j] - 'A'] ++;
				if(character[input[j] - 'A'] > maxNum)
					maxNum = character[input[j] - 'A'];
			}
		}
	}

	for(int i = 0;i < maxNum;i++){
		spaceNum = 0;
		for(int j =0;j < 26;j++){
			if(character[j] >= maxNum - i){
				printSpace(spaceNum);
				cout << '*';
				spaceNum = 1;
			}
			else
				spaceNum +=2;
		}
		cout << endl;
	}

	for(int i =0;i < 26;i++){
		cout << a << " ";
		a ++;
	}
	return 0;
}
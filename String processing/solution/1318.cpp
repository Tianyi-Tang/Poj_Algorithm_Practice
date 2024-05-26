#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define maxDictionaryLength 100

string orginalStr[maxDictionaryLength],modifyStr[maxDictionaryLength];



string modfifyString(string str){
	int strLength,counter;
	string changeStr = "";
	char c = 'a';

	strLength = str.length();
	counter = 0;
	for(int i =0;i < 24;i++){
		for(int j =0;j < strLength;j++){
			if(str[j] == c){
				changeStr += c;
				counter ++;
			}
		}
		if(strLength == counter)
			break;
		c++;
	}
	return changeStr;
}



int main()
{
	string input,changeString;
	int inputIndex = 0;
	bool findOne;

	while(cin >> input){
		if(input == "XXXXXX")
			break;
		orginalStr[inputIndex++] = input;
	}

	sort(orginalStr,orginalStr+inputIndex);
	for(int i = 0;i < inputIndex;i++){
		changeString = modfifyString(orginalStr[i]);
		modifyStr[i] = changeString;
	}

	while(cin >> input){
		if(input == "XXXXXX")
			break;
		findOne = false;
		changeString = modfifyString(input);
		for(int i =0;i < inputIndex;i++){
			if(changeString == modifyStr[i]){
				cout << orginalStr[i] << endl;
				findOne = true;
			}
		}
		if(!findOne)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}


	return 0;
}
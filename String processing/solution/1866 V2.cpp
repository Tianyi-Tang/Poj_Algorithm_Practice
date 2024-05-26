#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <map>
using namespace std;

#define maxCharacter 100

int indexs[2] = {0},testCause;
string pattern[2][maxCharacter];
string input;


void excuteInput(int num){
	getline(cin,input);
	pattern[num][0] = "";
	for(int i =0;i < input.length();i++){
		if(input[i] == ' '){
			indexs[num] ++;
			pattern[num][indexs[num]] = "";
		}
		else
			pattern[num][indexs[num]] += input[i];
	}
	indexs[num] ++;
}

string matchPattern(){
	if(indexs[0] != indexs[1])
		return "-";

	map<string, string> aMap,bMap;
	for(int i =0;i < indexs[0];i++){
		if(pattern[0][i][0] == '<' && pattern[1][i][0] == '<')
			continue;
		else if(pattern[0][i][0] == '<'){
			if(aMap[pattern[0][i]].length() != 0 && aMap[pattern[0][i]] != pattern[1][i])
				return "-";
			else if(aMap[pattern[0][i]].length() == 0){
				aMap[pattern[0][i]] = pattern[1][i];
			}
		}
		else if(pattern[1][i][0] == '<'){
			if(bMap[pattern[1][i]].length() != 0 && bMap[pattern[1][i]] != pattern[0][i])
				return "-";
			else if(bMap[pattern[1][i]].length() == 0){
				bMap[pattern[1][i]] = pattern[0][i];
			}
		}
		else if(pattern[0][i] == pattern[1][i])
			continue;
		else
			return "-";
	}

	string result ="";
	for(int i =0;i < indexs[0];i++){
		if(i != 0)
			result += ' ';
		if(pattern[0][i][0] == '<' && pattern[1][i][0] == '<'){
			if(aMap[pattern[0][i]].length() != 0){
				result += aMap[pattern[0][i]];
				bMap[pattern[1][i]] = aMap[pattern[0][i]];
			}
			else if(bMap[pattern[1][i]].length() != 0){
				result += bMap[pattern[1][i]];
				aMap[pattern[0][i]] = bMap[pattern[1][i]];
			}
			else
				result += "x";
		}
		else if(pattern[0][i][0] == '<'){
			result += aMap[pattern[0][i]];
		}
		else if(pattern[1][i][0] == '<'){
			result += bMap[pattern[1][i]];
		}
		else
			result += pattern[0][i];
	}

	return result;
}

int main()
{

	cin >> testCause;
	getchar();
	while(testCause){
		indexs[0] = 0;
		indexs[1] = 0;
		excuteInput(0);
		excuteInput(1);
		cout << matchPattern() << endl;

		testCause --;
	}
	



	return 0;
}
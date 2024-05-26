#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

bool alphabets[26];
bool hasABlank;

bool isVowel(char a){
	if(a == 'A' || a == 'E' || a== 'I' || a == 'O' || a == 'U')
		return true;
	else
		return false;
}

bool isCharacter(char a){
	if(a >= 'A' && a <= 'Z')
		return true;
	else
		return false;
}

void inital(){
	hasABlank = false;
	for(int i =0;i< 26;i++)
		alphabets[i] = false;
}

int main()
{
	string input,answer;
	char c;

	while(getline(cin,input)){
		answer = "";
		inital();

		for(int i =0;i < input.length();i++){
			c = input[i];
			if(c == ' '){
				if(answer != "")
					hasABlank = true;
			}
			else if(isCharacter(c)){
				if(!isVowel(c) && !alphabets[c - 'A']){
					alphabets[c-'A'] = true;
					if(hasABlank){
						answer += ' ';
						hasABlank = false;
					}
					answer += c;
				}
			}
			else{
				hasABlank = false;
				answer += c;
			}
		}

		cout << answer << endl;

	}

	return 0;
}
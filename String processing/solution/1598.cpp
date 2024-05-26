#include<cstring>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
using namespace std;

#define maxKeywordNum 100
#define maxExcuseNum 20

int keyWordNum,excuseNum,worstNum;
string keyWordList[maxKeywordNum];
string worstExcuses[maxExcuseNum];
string line;

bool sameChar(char a , char b){
	if(a == b || a + 32 == b)
		return true;
	else
		return false;
}

bool seperateSymbol(int index){
	if(index == 0)
		return true;
	char a = line[index];

	if((a >= 'a' && a <= 'z')||(a >= 'A' && a <= 'Z'))
		return false;
	else
		return true;
}

int main()
{
	int maxIncidence,indexCounter,KeywordLength,currentIncidence,loopIndex;
	string currentKeyword;
	bool finding;

	loopIndex = 1;

	while(cin >> keyWordNum >> excuseNum){
		for(int i = 0;i < keyWordNum;i++){
			cin >> line;
			keyWordList[i] = line;
		}

		maxIncidence = -1;
		worstNum = 0;
		getchar();
		for(int i =0;i < excuseNum;i++){
			getline(cin,line);
			currentIncidence = 0;
			for(int j = 0;j < keyWordNum;j++){
				currentKeyword = keyWordList[j];
				KeywordLength = currentKeyword.length();
				finding = false;
				for(int z = 0; z < line.length();z++){
					if(finding && sameChar(line[z],currentKeyword[indexCounter]))
						indexCounter ++;
					else
						finding = false;
					
					if(!finding && seperateSymbol(z-1) && sameChar(line[z],currentKeyword[0])){
						finding = true;
						indexCounter = 1;
					}

					if(indexCounter == KeywordLength){
						finding = false;
						currentIncidence ++;
						indexCounter = -1;
					}
				}
			}
			if(currentIncidence > maxIncidence){
					worstNum = 1;
					worstExcuses[0] = line;
					maxIncidence = currentIncidence;
			}
			else if(currentIncidence == maxIncidence){
				worstExcuses[worstNum++] = line;
			}
		}

		cout << "Excuse Set #" << loopIndex << endl;
		for(int i =0;i < worstNum;i++){
			cout << worstExcuses[i] << endl;
		}
		cout << endl;

		loopIndex ++;
	}

	return 0;
}



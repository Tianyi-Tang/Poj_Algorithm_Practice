#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;

#define maxNum 100000
#define maxLength 10

int wordsNum;
char positionChar[maxNum];
const char space = ' ';


int main()
{
	char word[maxLength],currentChar;
	int wordIndex,i;
	string spaces;

	ifstream inputfile("input.txt");
	ofstream outputfile("output.txt");
	wordsNum = 0;
	while(inputfile >> word){
		if(word[0] == '1')
			break;
		wordIndex = strlen(word)-1;
		if(wordsNum == 0){
			positionChar[wordsNum++] = word[0];
		}
		else{
			for(i = 0;i < wordsNum;i++){
				if(positionChar[i] != word[i])
					break;
			}
			if(i == wordsNum)
				positionChar[wordsNum++] = word[i];
			else{
				positionChar[i] = word[i];
				wordsNum = i + 1;
			}
		}
		
		spaces = "";
		for(int i =0;i < wordsNum-1;i++)
			spaces += space;
		outputfile << spaces <<word << "\n";
	}
	outputfile.close();
	return 0;
}
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

#define maxLineChar 80

void htmlAction(string html,int& counter){
	if(html == "br")
		cout << endl;
	else if(html == "hr"){
		if(counter != 0)
			cout << endl;
		for(int i =0;i < maxLineChar;i++)
			cout << '-';
		cout << endl;
	}
	counter = 0;
}

void printNewWord(string& word,int& totalCounter,int& wordCounter){
	if(totalCounter + wordCounter +1 >= maxLineChar){
		cout << endl << word;
		totalCounter = wordCounter;
	}
	else{
		if(totalCounter == 0){
			cout << word;
			totalCounter += wordCounter;
		}
		else if(word != ""){
			cout << " " << word;
			totalCounter += wordCounter + 1;
		}
	}

	wordCounter = 0;
	word = "";
}

int main()
{
	string input,wordStr;
	int totalCounter,wordCounter;
	bool htmlTag;



	totalCounter = wordCounter = 0;
	htmlTag = false;
	wordStr = "";
	while(getline(cin,input)){
		for(int i =0;i < input.length();i++){
			if(htmlTag && input[i] == '>'){
				htmlAction(wordStr,totalCounter);
				htmlTag = false;
				wordStr = "";
			}
			else if(htmlTag)
				wordStr += input[i];

			if(input[i] != '<' && input[i] != '>' && !htmlTag){
				if(input[i] == ' '){
					printNewWord(wordStr,totalCounter,wordCounter);
				}
				else{
					wordStr += input[i];
					wordCounter ++;
				}
			}
			else if(input[i] == '<'){
				htmlTag = true;
				wordStr = "";
			}
		}
		printNewWord(wordStr,totalCounter,wordCounter);
	}


	return 0;
}
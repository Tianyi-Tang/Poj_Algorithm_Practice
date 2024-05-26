#include<cstring>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<map>
using namespace std;

#define maxRefer 5000

int indexRef,correctReferNum;
string appearRefer[maxRefer],strNum;
map<string, string> Referencemap;
string holeParagraph;

bool isBlank(string input){
	for(int i =0;i < input.length();i++){
		if(input[i] != ' ')
			return false;
	}
	return true;
}


string intToString(int number){
	string reveNum,num;

	reveNum = "";
	while(number != 0){
		reveNum += number % 10 + '0';
		number = number /10;
	}

	num = "";
	for(int i = reveNum.length()-1;i >=0;i--)
		num += reveNum[i];

	return num;
}



int storeIndexInArray(string referNum){
	for(int i =0;i < indexRef;i++){
		if(referNum == appearRefer[i])
			return i;
	}
	return -1;
}



void changeReferenceNum(){
	bool findNum = false;
	int length, start;
	length = 0; 
	for(int i =1;i < holeParagraph.length();i++){
		if(findNum && holeParagraph[i]!=']')
			length ++;
		else if (findNum && holeParagraph[i]==']'){
			strNum = holeParagraph.substr(start,length);
			if(storeIndexInArray(strNum) == -1){
				appearRefer[indexRef++] = strNum;
				holeParagraph.replace(start,length,intToString(correctReferNum));
				correctReferNum ++;
			}
			else{
				holeParagraph.replace(start,length,intToString(storeIndexInArray(strNum)+1));
			}
		}

		if(holeParagraph[i-1] == '['){
			findNum = true;
			length = 1;
			start = i;
		}
	}
}


int main()
{
	string line;
	int end;

	holeParagraph = "";
	indexRef = 0;
	correctReferNum = 1;



	while(getline(cin,line)){
		if(line.length() == 0 || isBlank(line)){
			if(holeParagraph == "")
				continue;
			if(holeParagraph[0] != '['){
				changeReferenceNum();
				cout << holeParagraph << endl;
			}
			else{
				end = 2;
				while(holeParagraph[end] != ']')
					end ++;
				strNum = holeParagraph.substr(1,end-1);
				Referencemap[strNum] = holeParagraph;
			}
			holeParagraph = "";
		}
		else if(!isBlank(line))
			holeParagraph += line + '\n';
	}

	if(holeParagraph[0] != '['){
		changeReferenceNum();
		cout << holeParagraph << endl;
	}
	else{
		end = 2;
		while(holeParagraph[end] != ']')
			end ++;
		strNum = holeParagraph.substr(1,end-1);
		Referencemap[strNum] = holeParagraph;
	}


	for(int i = 0;i < indexRef;i++){
		strNum = appearRefer[i];
		holeParagraph = Referencemap[strNum];
		changeReferenceNum();
		cout << holeParagraph << endl;
	}

	
	return 0;
}

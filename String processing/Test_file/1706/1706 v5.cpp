#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stdio.h>
using namespace std;

int appearRefer[1000] = {0};
int referOrder[1000] = {-1};
string allReference[1000];
string input;

bool blankLine(){
	for(int i =0;i < input.length();i++){
		if(input[i] != ' ')
			return false;
	}
	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	string wholeRef;
	int refernceNum, indexRef,nueLength;
	bool appearNum = false;
	
	refernceNum = 0;
	indexRef = 1;
	while(getline(cin,input)){
		if(input.length() == 0 || blankLine())
			continue;
		else if(input[0] == '['){
			nueLength = 1;
			refernceNum = input[1] - '0';
			for(int i =2;i < input.length();i++){
				if(input[i] != ']'){
					refernceNum = refernceNum * 10 + input[i] - '0';
					nueLength++;
				}
				else
					break;
			}
			wholeRef = input.substr(nueLength+2,input.length()- nueLength-2);

			while(getline(cin,input)){
				if(input.length() == 0 || blankLine())
					break;
				wholeRef += input;
			}
			allReference[refernceNum] = wholeRef;
		}
		else{
			while(true){
				for(int i =0;i < input.length();i++){
					if(input[i] == ']'){
						appearNum = false;
						if(!appearRefer[refernceNum]){
							appearRefer[refernceNum] = indexRef;
							referOrder[indexRef] = refernceNum;
							cout << indexRef++;
						}
						else
							cout << appearRefer[refernceNum];
					}
					else if(appearNum){
						refernceNum = refernceNum * 10 + input[i] - '0';
						continue;
					}
					else if(input[i] == '['){
						appearNum = true;
						refernceNum = 0;
					}
					cout << input[i];
				}
				cout << endl;

				getline(cin,input);
				if(input.length() ==0 || blankLine())
					break;
			}
			cout << endl;
		}
	}

	for(int i =1;i< indexRef;i++){
		if(i != 1)
			cout << endl;
		cout << "[" << i << "]" << allReference[referOrder[i]] << endl;
		
	}
	return 0;
}
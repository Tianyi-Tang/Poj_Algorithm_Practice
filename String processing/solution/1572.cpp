#include<cstring>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

#define maxReplaceNum 10

int paireNum;
string findStr[maxReplaceNum], replaceSt[maxReplaceNum];


void replaceString(string& input,string replace,int start,int end){
	string changestr = "";

	for(int i =0;i < start;i++)
		changestr += input[i];

	changestr += replace;

	for(int i = end;i < input.length();i++)
		changestr += input[i];

	input = changestr;
}

int main()
{
	int findLength,start,counter,findIndex;
	string input,str;
	bool finding,change;

	while(cin >> paireNum){
		if(paireNum == 0)
			break;

		getchar();
		for(int i =0;i < paireNum;i++){
			getline(cin,input);
			findStr[i] = input;
			getline(cin,input);
			replaceSt[i] = input;
		}

		getline(cin,input);


		for(int i = 0;i < paireNum;i++){
			while(true){
				start = input.find(findStr[i]);
				if(start == string::npos)
					break;
				input = input.replace(start,findStr[i].length(),replaceSt[i]);
			}
		}

		// findIndex = -1;
		// change = false;
		// while(findIndex < paireNum){
		// 	if(!change){
		// 		findIndex ++;
		// 		str = findStr[findIndex];
		// 		findLength = str.length();
		// 	}
		// 	else
		// 		change = false;
		// 	finding = false;
			
		// 	for(int j =0;j < input.length();j++){
		// 		if(finding && input[j] == str[counter])
		// 			counter ++;
		// 		else{
		// 			finding = false;
		// 		}

		// 		if(input[j] == str[0] && !finding){
		// 			finding = true;
		// 			start = j;
		// 			counter = 1;
		// 		}

		// 		if(counter == findLength){
		// 			replaceString(input,replaceSt[findIndex],start,j+1);
		// 			counter = -1;
		// 			finding = false;
		// 			change = true;
		// 			break;
		// 		}
		// 	}
			  
		// }

		cout << input << endl;
	}

	
	
	

	return 0;
}
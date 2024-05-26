#include<cstring>
#include<string.h>
#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define blackSlash '\\'

map<string, int> childMap[10000];
int nodeCounter,currentNode;


void storeInMap(string root){
	if(!childMap[currentNode].count(root))
		childMap[currentNode][root] = ++nodeCounter;
	currentNode = childMap[currentNode][root];
}

void splitPartString(string& wholeStr,string& splitStr,int index){
	splitStr = wholeStr.substr(0,index);
	wholeStr.replace(0,index+1,"");
}

void printAllRoot(int nodeNum,int spaceNum){
	for(map<string,int>::iterator it = childMap[nodeNum].begin();it != childMap[nodeNum].end(); it++){
		for(int i =1;i <= spaceNum;i++)
			printf(" ");
		printf("%s\n",(it->first).c_str());
		printAllRoot(it->second,spaceNum+1);
	}
	childMap[nodeNum].clear();
}

int main()
{
	int lineNum,indexBlackSlash,testCaseNum;
	string path,currentPath;

	cin >> testCaseNum;
	while(testCaseNum){
		nodeCounter = 0;
		cin >> lineNum;
		for(int i =0;i < lineNum;i++){
			cin >> path;
			currentNode = 0;
			indexBlackSlash = path.find(blackSlash);

			if(indexBlackSlash == string::npos){
				storeInMap(path);
			}
			else{
				splitPartString(path,currentPath,indexBlackSlash);
				storeInMap(currentPath);

				indexBlackSlash = path.find(blackSlash);
				while(indexBlackSlash != string::npos){
					splitPartString(path,currentPath,indexBlackSlash);
					storeInMap(currentPath);
					indexBlackSlash = path.find(blackSlash);
				}
				storeInMap(path);
			}
		}

		printAllRoot(0,0);

		testCaseNum --;
		if(testCaseNum)
			printf("\n");
	}


	

	return 0;
}
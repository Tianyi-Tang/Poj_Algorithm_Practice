#include<cstring>
#include<cstdlib>
#include<iostream>
#include<map>
#include<list>
#include<stdio.h>
using namespace std;

struct Node{
	string name;
	Node* fa;
	list<Node*> subNodes;
};

map<string, Node*> nodeMap;
Node* root;
string name1,name2;


void hirePeople(string parentName,string chilName){
	Node* parentNode = nodeMap[parentName];
	Node* childNode = new Node();

	childNode->name = chilName;
	parentNode->subNodes.push_back(childNode);
	nodeMap[chilName] = childNode;
	childNode->fa = parentNode;
}

void firePeople(string fireName){
	Node* deletNode = nodeMap[fireName];

	while(deletNode->subNodes.size() > 0){
		deletNode->name = deletNode->subNodes.front()->name;
		nodeMap[deletNode->name] = deletNode;;
		deletNode = deletNode->subNodes.front();
	}
	nodeMap.erase(fireName);
	deletNode->fa->subNodes.remove(deletNode);
	delete deletNode;
}

void print(Node* start,int level){
	if(!start)
		return;
	for(int i =0;i < level;i++)
		cout << "+";
	cout << start->name << endl;
	for(list<Node*>::iterator it = start->subNodes.begin(); it != start->subNodes.end();it++)
		print(*it,level +1);
}



void reaction(string input){
	int start;
	if(input == "print"){
		print(root,0);
		cout << "------------------------------------------------------------" << endl;
	}
	else if(input.length() > 5 && input.substr(0,4) == "fire"){
		name1 = input.substr(5,input.length()-5);
		firePeople(name1);
	}
	else{
		start = input.find(' ');
		name1 = input.substr(0,start);
		name2 = input.substr(start+7,input.length()- start-7);
		hirePeople(name1,name2);
	}

}

int main()
{
	string input;

	cin >> input;
	root = new Node();
	root->name = input;
	nodeMap[input] = root;

	getchar();
	while(getline(cin,input)){
		reaction(input);
	}

	return 0;
}
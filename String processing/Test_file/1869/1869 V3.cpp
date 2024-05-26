#include<cstring>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
using namespace std;

#define indentation "    "

int indentationLevel;

void printIndentation(){
	for(int i =0;i < indentationLevel;i++)
		cout << indentation;
}

int main()
{
	char c;
	bool fistEnter,needPrintIndentation;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	fistEnter = true;
	needPrintIndentation = false;
	while((c = getchar())){
		if(c == -1)
			break;

		if(c == ' ' || c == '	'|| c == '\n')
			continue;

		if(needPrintIndentation){
			needPrintIndentation = false;
			if(c != '}')
				printIndentation();
		}

		if(fistEnter){
			fistEnter = false;
			indentationLevel = 1;
			cout << c << endl;
			printIndentation();
			continue;
		}
		else if(c == '{'){
			cout << " {" << endl;
			indentationLevel++;
			printIndentation();
			continue;
		}
		else if(c == '}'){
			indentationLevel--;
			printIndentation();
			cout << c;
			continue;
		}

		cout << c;

		if(c == ';'){
			cout << endl;
			needPrintIndentation = true;
		}
		else if(c == ',')
			cout << ' ';

	}

	return 0;
}
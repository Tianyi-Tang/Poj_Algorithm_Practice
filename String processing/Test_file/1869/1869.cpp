#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;

#define maxLine 1500
#define indentation "    ";

int lineCounter,indentationLevel;
string porgram[maxLine];
string line,correctLine;


void addIndentationToLine(){
	porgram[lineCounter] = "";
	for(int i =0;i < indentationLevel;i++){
		porgram[lineCounter] += indentation; 
	}
}

void formCorrectFormat(){
	correctLine = "";

	for(int i =0;i < line.length();i++){
		if(line[i] != ' ' && line[i] != '	' && line[i] != '\n'){
			if(line[i] == '{' || line[i] == ';'){
				addIndentationToLine();
				if(line[i] == '{'){
					indentationLevel ++;
					if(correctLine.length() == 0){
						porgram[lineCounter-1] += " {";
						continue;
					}
					correctLine += " {";
				}
				else
					correctLine += ';';
				porgram[lineCounter++] += correctLine;
				correctLine = "";
				continue;
			}
			else if(line[i] == '}'){
				if(correctLine.length() != 0){
					addIndentationToLine();
					porgram[lineCounter++] += correctLine;
				}
				indentationLevel --;
				correctLine = "}";
				continue; 
			}

			correctLine += line[i];
			if(line[i] == ',')
				correctLine += ' ';
		}
	}
	if(correctLine.length() != 0){
		addIndentationToLine();
		porgram[lineCounter++] += correctLine;
	}
}


int main()
{
	lineCounter = 0;
	indentationLevel = 0;

	ifstream inputfile("input.txt");
	while(getline(inputfile,line)){
		if(lineCounter ==0){
			porgram[lineCounter++] = "{";
			indentationLevel ++;
			if(line.length()>1){
				line = line.substr(1,line.length()-1);
				formCorrectFormat();
			}
			continue;
		}
		formCorrectFormat();
	}




	for(int i =0;i < lineCounter;i++)
		cout << porgram[i] << endl;

	return 0;
}
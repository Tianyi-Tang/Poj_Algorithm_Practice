#include<cstring>
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;


int main()
{
	string outputLine,answerLine,inputLine;
	bool allcorrect = true;

	ifstream inputfile("input.txt");
	ifstream outputfile("input.txt");
	ifstream answerfile("input.txt");

	while(getline(outputfile,outputLine)){
		getline(answerfile,answerLine);
		getline(inputfile,inputLine);
		if(answerLine != outputLine){
			allcorrect = false;
			cout << "This input has error: " << inputLine << endl;
		}
	}
	if(allcorrect)
		cout << "all correct" << endl;


	return 0;
}




#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxCharNum 80



int main()
{
	string word;
	int totoalCounter;
	//freopen("input.txt","r",stdin);

	totoalCounter = 0;
	while(cin >> word){
		if(word == "<br>"){
			cout << endl;
			totoalCounter = 0;
		}
		else if(word == "<hr>"){
			if(totoalCounter != 0)
				cout << endl;
			for(int i =0;i < maxCharNum;i++)
				cout << '-';
			cout << endl;
			totoalCounter = 0;
		}
		else{
			if(totoalCounter + word.length() + 1 >= maxCharNum){
				cout << endl << word;
				totoalCounter = word.length();
			}
			else{
				if(totoalCounter == 0)
					cout << word;
				else{
					cout << " " << word;
					totoalCounter += 1;
				}
				totoalCounter += word.length();
			}
		}
	}
	return 0;
}
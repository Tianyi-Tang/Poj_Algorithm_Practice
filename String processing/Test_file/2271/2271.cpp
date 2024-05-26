#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

void activeHtmlTag(string orderStr,int& counter){
	if(orderStr == "hr"){
		if(counter != 0)
			cout << endl;
		for(int i =0;i < 80;i++){
			cout << '-';
		}
		cout << endl;
	}
	else if(orderStr == "br")
		cout << endl;
	
	counter = 0;
}


int main()
{
	string input,orderStr,wordStr;
	int totalCounter,wordCounter;
	bool htmlTag,justChange;

	freopen("input.txt","r",stdin);

	htmlTag = justChange = false;
	totalCounter = wordCounter = 0;
	wordStr = "";
	while(getline(cin,input)){
		for(int i =0;i < input.length();i++){
			if(htmlTag && input[i] == '>'){
				htmlTag = false;
				activeHtmlTag(orderStr,totalCounter);
				justChange = true;
			}
			else if(htmlTag)
				orderStr += input[i];
			else if(justChange){
				justChange = false;
				if(input[i] == ' ')
					continue;
			}

			if(input[i] != '<' && input[i] != '>' && !htmlTag){
				if(input[i] == ' '){
					if(wordCounter + totalCounter > 80){
						cout << endl;
						cout << wordStr;
						totalCounter = wordCounter;
					}
					else{
						if(totalCounter == 0)
							cout << wordStr;
						else if(wordStr!= ""){
							cout << " " << wordStr;
							totalCounter ++;
						}
						totalCounter += wordCounter;
					}

					wordCounter = 0;
					wordStr = "";
				}
				else{
					wordStr += input[i];
					wordCounter ++;
				}
			}
			else if(input[i] == '<'){
				htmlTag = true;
				orderStr = "";
			}

		}
	}



	return 0;
}